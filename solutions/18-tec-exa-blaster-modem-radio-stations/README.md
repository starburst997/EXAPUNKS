# 18: TEC EXA-Blaster Modem - Radio Stations

<div align="center"><img src="EXAPUNKS - TEC EXA-Blaster� Modem (874, 57, 18, 2022-12-05-19-32-10).gif" /></div>

> ﻿Connect to each radio station and replace every song in the playlist (file 200) with ‗CAN'T (NOT) GET OVER YOU‗ by ‗ME2U‗ (file 300). Each song in a playlist consists of two keywords: the song name and the artist name.
> 
> A list of phone numbers for the radio stations is available in file 301.
> 
> Note that EXAs in global mode can only communicate if there is a path of links connecting them.
> 
> For more information see "Hacker Skills: Modem Control at the Direct Level" in the second issue of the zine.

## Solution

### XA (local)
```asm
GRAB 300
LINK 800

MARK DIAL
MODE
TEST MRD
FJMP STOP
@REP 11
COPY M #DIAL
@END

LINK 800
MODE
REPL BOT

COPY M X
MARK COPY
COPY F M
COPY F M
SEEK -2
TEST M = 1
TJMP COPY

LINK -1
COPY -1 #DIAL
JUMP DIAL

MARK BOT
GRAB 200

MARK COPY_BOT
COPY 1 M
COPY M F
COPY M F
TEST EOF
FJMP COPY_BOT
COPY 0 M
HALT

MARK STOP
LINK -1
```

### XB (global)
```asm
GRAB 301

MARK DIAL
@REP 11
COPY F M
@END

TEST EOF
FJMP DIAL
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 874    | 57   | 18       |
