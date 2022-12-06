// I like to keep simple program in one file
// Might clean this up eventually...
#include <map>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
using namespace std;

const int CYCLE_N = 6;
const int SIZE_N = 4;
const int ACTIVITY_N = 8;

// Types
enum Stats : int32_t {
	Cycles = 0,
	Size = 1,
	Activity = 2
};

struct GIF {
	fs::path name;
	fs::file_time_type time;
};

struct EXA {
	string name;
	string source;
	bool local;
};

struct Solution {
	string id;
	string name;
	int wins;
	int cycles;
	int size;
	int activity;
	fs::path path;

	vector<EXA> exas;
};

struct Info {
	string id;
	string description;
	string title;
	string path;
	fs::path gif;
};

// Vars
int maxChars = 0;
map<string, Solution> solutions;
map<string, Info> dataMap;
vector<string> ids = { };
vector<string> battles = { };

// Utils
string readString(ifstream& stream) {
	int32_t i;
	stream.read(reinterpret_cast<char*>(&i), sizeof(i));
	
	char* buffer = new char[i + 1];
	buffer[i] = 0; // nul terminated

	stream.read(buffer, i);

	return buffer;
}

void writeNum(ofstream& stream, int n, int max) {
	string str = to_string(n);

	stream << str;
	for (int j = 0; j < max - str.length(); j++) stream << ' ';
}

bool compareTime(const GIF& a, const GIF& b)
{
	return a.time < b.time;
}

// Parse Saves (.solution) / GIFs specified in arguments and create the repo's file
// TODO: Include leaderboard as well?
int main(int argc, char* argv[])
{
	cout << "EXA-Parser: " << endl;
	cout << "  input 1: Directory to saves" << endl;
	cout << "  input 2: Directory to gifs" << endl;
	cout << "  input 3: Directory to descriptions" << endl;
	cout << "  input 4: data.txt" << endl;
	cout << "  input 5: Output Directory" << endl << endl;

	fs::path pathSaves = "../temp/saves";
	if (argc >= 2) pathSaves = argv[1];
	if (!fs::is_directory(pathSaves)) {
		cout << "Directory for save is invalid " << fs::current_path() << endl << endl;
		return 1;
	}

	fs::path pathGIFs = "../temp/gifs";
	if (argc >= 3) pathGIFs = argv[2];
	if (!fs::is_directory(pathGIFs)) {
		cout << "Directory for GIFs is invalid " << fs::current_path() << endl << endl;
		return 1;
	}

	fs::path pathDescriptions = "../temp/descriptions";
	if (argc >= 4) pathDescriptions = argv[3];
	if (!fs::is_directory(pathDescriptions)) {
		cout << "Directory for descriptions is invalid " << fs::current_path() << endl << endl;
		return 1;
	}

	fs::path pathData = "data.txt";
	if (argc >= 5) pathData = argv[4];
	ifstream dataStream(pathData);
	if (!dataStream) {
		cout << "File (data.txt) not found!\n";
		return 1;
	}

	fs::path pathOutput = "..";
	if (argc >= 6) pathOutput = argv[5];
	if (!fs::is_directory(pathOutput)) {
		fs::create_directories(pathOutput);

		if (!fs::is_directory(pathOutput)) {
			cout << "Directory for output is invalid " << fs::current_path() << endl << endl;
			return 1;
		}
	}

	// Loop all gifs, they are badly named, so instead assume they were saved in order (sort by time)
	cout << "Parse GIFs:" << endl;

	vector<GIF> gifs = { };
	for (const auto& entry : fs::directory_iterator(pathGIFs)) {
		gifs.push_back({ entry.path(), fs::last_write_time(entry.path()) });

		cout << "    " << entry.path() << endl;
	}

	sort(gifs.begin(), gifs.end(), compareTime);

	// Create hash map / array
	cout << endl << "Parse data.txt:" << endl;

	int globalCounter = 0;
	int solutionCounter = 1;
	int battleCounter = 1;
	string line;
	while (getline(dataStream, line)) {
		int i1 = line.find(',');
		if (i1 == string::npos) continue;

		int i2 = line.find(',', i1 + 1);
		if (i2 == string::npos) continue;

		string id = line.substr(0, i1);
		string description = line.substr(i1 + 1, i2 - i1 - 1) + ".txt";
		string title = line.substr(i2 + 1);

		bool isBattle = description.rfind("battle-", 0) == 0;
		int counter = isBattle ? battleCounter++ : solutionCounter++;

		// Create path based on title
		string path = ((counter < 10) ? ("0" + to_string(counter)) : to_string(counter)) + '-';
		char last = ' ';
		for (int i = 0; i < title.length(); i++) {
			char c = title[i];
			if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
				path += c;
				last = c;
			}
			else if (c >= 'A' && c <= 'Z') {
				path += c + 0x20;
				last = c;
			}
			else if ((c == ' ' || c == '-') && last != '-') {
				path += '-';
				last = '-';
			}
		}

		Info info = { id, description, title, path, gifs[globalCounter].name };

		int total = 1 + title.length() + 12 + path.length() + 1;
		if (total > maxChars) maxChars = total;

		cout << "    " << id << ": " << title << endl;

		dataMap[id] = info;

		if (!isBattle) ids.push_back(id);
		else battles.push_back(id);

		globalCounter++;
	}

	// Loop all saves, overwrite if cycles is better
	cout << endl << "Parse Saves:" << endl;

	for (const auto& entry : fs::directory_iterator(pathSaves)) {
		ifstream solutionStream(entry.path(), ios::binary);
		if (!solutionStream) continue;

		int32_t i;
		solutionStream.read(reinterpret_cast<char*>(&i), sizeof(i));

		// Will probably change if there is new version
		if (i != 0x3F0) continue;

		string id = readString(solutionStream);
		string name = readString(solutionStream);

		int32_t wins;
		solutionStream.read(reinterpret_cast<char*>(&wins), sizeof(i));

		int32_t redshift;
		solutionStream.read(reinterpret_cast<char*>(&redshift), sizeof(i));

		// Stats
		solutionStream.read(reinterpret_cast<char*>(&i), sizeof(i));

		int cycles = 0, size = 0, activity = 0;
		for (int j = 0; j < i; j++) {
			int32_t type, value;
			solutionStream.read(reinterpret_cast<char*>(&type), sizeof(type));
			solutionStream.read(reinterpret_cast<char*>(&value), sizeof(value));

			switch ((Stats) type) {
			case Cycles:
				cycles = value;
				break;
			case Size:
				size = value;
				break;
			case Activity:
				activity = value;
				break;
			}
		}

		solutionStream.read(reinterpret_cast<char*>(&i), sizeof(i));

		Solution solution = {
			id,
			name,
			100, // TODO: Not saved in the file format?
			cycles,
			size,
			activity,
			entry.path()
		};

		for (int j = 0; j < i; j++) {
			solutionStream.ignore(); // Magic 0xA
			
			string name = readString(solutionStream);
			string source = readString(solutionStream);

			bool collapsed = solutionStream.get() > 0;
			bool local = solutionStream.get() > 0;

			solutionStream.seekg(100, ios::cur); // Skip Bitmap

			solution.exas.push_back({
				name,
				source,
				local
			});
		}

		// Only replace if cycles are lower
		if (solutions.find(id) != solutions.end()) {
			Solution old = solutions[id];
			if (old.cycles > solution.cycles) {
				cout << "  + " << id << ": " << name << endl;

				solutions[id] = solution;
			}
			else {
				cout << "  - " << id << ": " << name << endl;
			}
		}
		else {
			cout << "    " << id << ": " << name << endl;

			solutions[id] = solution;
		}
	}

	// Alright, now we can create the files / directories as needed
	// Clear all previous files
	cout << endl << "Clear previous files:" << endl;

	fs::path pathOutputSolutions = pathOutput / "solutions";
	if (fs::is_directory(pathOutputSolutions)) {
		fs::remove_all(pathOutputSolutions);
		cout << "    Clearing 'solutions' directory" << endl;
	}
	else {
		cout << "    No 'solutions' directory found" << endl;
	}

	fs::path pathOutputBattles = pathOutput / "battles";
	if (fs::is_directory(pathOutputBattles)) {
		fs::remove_all(pathOutputBattles);
		cout << "    Clearing 'battles' directory" << endl;
	}
	else {
		cout << "    No 'battles' directory found" << endl;
	}

	cout << endl << "Create files:" << endl;

	// Create README
	fs::path pathReadme = pathOutput / "README.md";
	ifstream readmeStream(pathReadme);
	if (!readmeStream) {
		cout << "    README not found, create new one" << endl;

		ofstream readmeOut(pathReadme);
		readmeOut << "# EXAPUNKS" << endl << endl << "<!-- EXA_START -->" << endl << "<!-- EXA_END -->" << endl;
		readmeOut.close();

		readmeStream.open(pathReadme);
	}
	else {
		cout << "    README found!" << endl;
	}

	// Find magic comment to insert table
	fs::path pathReadmeTemp = pathOutput / "README.md.temp";
	ofstream readmeOut(pathReadmeTemp);

	bool skip = false;
	while (getline(readmeStream, line)) {
		if (line == "<!-- EXA_START -->") {
			readmeOut << line << endl;
			skip = true;

			// Create table
			readmeOut << "| Level";
			for (int i = 0; i < maxChars - 5 + 1; i++) readmeOut << ' ';
			readmeOut << "| Cycles | Size | Activity |" << endl;

			readmeOut << "|";
			for (int i = 0; i < maxChars + 2; i++) readmeOut << '-';
			readmeOut << "|--------|------|----------|" << endl;

			for (int i = 0; i < ids.size(); i++) {
				Info info = dataMap[ids[i]];
				readmeOut << "| [" << info.title << "](solutions/" << info.path << ") ";

				int total = maxChars - (1 + info.title.length() + 12 + info.path.length() + 1);
				for (int j = 0; j < total; j++) readmeOut << ' ';

				Solution solution = solutions[ids[i]];
				readmeOut << "| ";
				writeNum(readmeOut, solution.cycles, CYCLE_N);
				readmeOut << " | ";
				writeNum(readmeOut, solution.size, SIZE_N);
				readmeOut << " | ";
				writeNum(readmeOut, solution.activity, ACTIVITY_N);
				readmeOut << " |" << endl;
			}

			// Create battle
			readmeOut << "| Battle";
			for (int i = 0; i < maxChars - 5 + 0; i++) readmeOut << ' ';
			readmeOut << "| Wins |" << endl;

			readmeOut << "|";
			for (int i = 0; i < maxChars + 2; i++) readmeOut << '-';
			readmeOut << "|------|" << endl;

			for (int i = 0; i < battles.size(); i++) {
				Info info = dataMap[battles[i]];
				readmeOut << "| [" << info.title << "](battles/" << info.path << ") ";

				int total = maxChars - (1 + info.title.length() + 10 + info.path.length() + 1);
				for (int j = 0; j < total; j++) readmeOut << ' ';

				Solution solution = solutions[ids[i]];
				readmeOut << "| ";
				writeNum(readmeOut, solution.wins, 4);
				readmeOut << " |" << endl;
			}
		}
		else if (line == "<!-- EXA_END -->") {
			readmeOut << line << endl;
			skip = false;
		}
		else if (!skip) {
			readmeOut << line << endl;
		}
	}

	// Replace README
	readmeStream.close();
	readmeOut.close();
	remove(pathReadme);
	rename(pathReadmeTemp, pathReadme);

	// Create solutions folder
	fs::create_directories(pathOutputSolutions);

	cout << endl << "  Making solutions:" << endl;

	for (int i = 0; i < ids.size(); i++) {
		Info info = dataMap[ids[i]];

		fs::create_directories(pathOutputSolutions / info.path);
		ofstream readmeOut(pathOutputSolutions / info.path / "README.md");

		readmeOut << "# " << to_string(i + 1) << ": " << info.title << endl << endl;

		// Copy GIF
		fs::copy(info.gif, pathOutputSolutions / info.path / info.gif.filename());
		readmeOut << "<div align=\"center\"><img src=\"" << info.gif.filename().string() << "\" /></div>" << endl << endl;

		// Read description files
		ifstream descriptionStream(pathDescriptions / info.description);
		if (descriptionStream) {
			readmeOut << "## Instructions" << endl;
			while (getline(descriptionStream, line)) {
				readmeOut << "> " << line << endl;
			}
			readmeOut << endl;
		}

		readmeOut << "## Solution" << endl << endl;

		// Add source as well
		Solution solution = solutions[ids[i]];

		for (int j = 0; j < solution.exas.size(); j++) {
			EXA exa = solution.exas[j];
			readmeOut << "### " << exa.name << " (" << (exa.local ? "local" : "global") << ")" << endl;
			readmeOut << "```asm" << endl;
			readmeOut << exa.source << endl;
			readmeOut << "```" << endl << endl;

			// Generate file as well
			ofstream exaOut(pathOutputSolutions / info.path / (exa.name + ".exa"));
			exaOut << exa.source;
		}

		// Copy OG file save as well
		fs::copy(solution.path, pathOutputSolutions / info.path / solution.path.filename());

		// Add score
		readmeOut << "#### Results" << endl;
		readmeOut << "| Cycles | Size | Activity |" << endl;
		readmeOut << "|--------|------|----------|" << endl;
		readmeOut << "| ";
		writeNum(readmeOut, solution.cycles, CYCLE_N);
		readmeOut << " | ";
		writeNum(readmeOut, solution.size, SIZE_N);
		readmeOut << " | ";
		writeNum(readmeOut, solution.activity, ACTIVITY_N);
		readmeOut << " |" << endl;

		cout << "    " << info.title << endl;
	}

	// Create battles folder
	fs::create_directories(pathOutputBattles);

	cout << endl << "  Making battles:" << endl;

	for (int i = 0; i < battles.size(); i++) {
		Info info = dataMap[battles[i]];

		fs::create_directories(pathOutputBattles / info.path);
		ofstream readmeOut(pathOutputBattles / info.path / "README.md");

		readmeOut << "# " << to_string(i + 1) << ": " << info.title << endl << endl;

		// Copy GIF
		fs::copy(info.gif, pathOutputBattles / info.path / info.gif.filename());
		readmeOut << "<div align=\"center\"><img src=\"" << info.gif.filename().string() << "\" /></div>" << endl << endl;

		// Read description files
		ifstream descriptionStream(pathDescriptions / info.description);
		if (descriptionStream) {
			readmeOut << "## Instructions" << endl;
			while (getline(descriptionStream, line)) {
				readmeOut << "> " << line << endl;
			}
			readmeOut << endl;
		}

		readmeOut << "## Solution" << endl << endl;

		// Add source as well
		Solution solution = solutions[ids[i]];

		for (int j = 0; j < solution.exas.size(); j++) {
			EXA exa = solution.exas[j];
			readmeOut << "### " << exa.name << " (" << (exa.local ? "local" : "global") << ")" << endl;
			readmeOut << "```asm" << endl;
			readmeOut << exa.source << endl;
			readmeOut << "```" << endl << endl;

			// Generate file as well
			ofstream exaOut(pathOutputBattles / info.path / (exa.name + ".exa"));
			exaOut << exa.source;
		}

		// Copy OG file save as well
		fs::copy(solution.path, pathOutputBattles / info.path / solution.path.filename());

		cout << "    " << info.title << endl;
	}
}