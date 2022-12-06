# 9: SFCTA Highway Sign #4902 - Remote Access Interface

<div align="center"><img src="EXAPUNKS - SFCTA Highway Sign 4902 (167, 11, 1, 2022-12-05-19-21-05).gif" /></div>

## Instructions
> Write EMBER-2's message (file 300) to the highway sign. The file contains one character value for each position on the sign from left to right, top to bottom.
> 
> For more information see "Hardware Hacks: Electronic Highway Signs" in the first issue of the zine.

## Solution

### XA (global)
```asm
GRAB 300
LINK 800
COPY 0 X
MARK LOOP
DIVI X 9 #DATA
MODI X 9 #DATA
COPY F #DATA
ADDI X 1 X
TEST EOF
FJMP LOOP
WIPE
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 167    | 11   | 1        |
