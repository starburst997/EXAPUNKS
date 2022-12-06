# 23: Xtreme League Baseball (Player Database)

<div align="center"><img src="EXAPUNKS - Xtreme League Baseball (294, 70, 24, 2022-12-05-19-35-36).gif" /></div>

## Instructions
> The hosts *active* and *penalty* contain files that correspond to extreme baseball players (files 200-299), along with a directory file that contains a list of those files' IDs (file 199). Each player file contains their name and the following statistics in this order: BA, ZA, APB, WRT, OI, OD, PC, and PS.
> 
> Create a file in your host with the name of the player with the highest score using EMBER-2's algorithm:
> 
> SCORE = (BA + ZA + APB) / 3 + ( WRT \* OI ) / OD + (PC - PS) \* 20
> 
> Players in the *penalty* host should be ignored, as they are currently banned from the game.

## Solution

### XA (local)
```asm
LINK 800

GRAB 199

MARK READ
COPY F M
TEST EOF
TJMP END
COPY 1 M
JUMP READ

MARK END
DROP
LINK -1
COPY -2 M
LINK 800
COPY -2 M
```

### XB (local)
```asm
LINK 800

MARK LOOP
GRAB M

SEEK 1
ADDI F F X
ADDI F X X
DIVI X 3 X
COPY X T
MULI F F X
DIVI X F X
ADDI X T X
COPY X T
SUBI F F X
MULI 20 X X
ADDI T X X

; BROADCAST VALUE + NAME
SEEK -9999
COPY F T
DROP
LINK -1
COPY X M
COPY X M
COPY X M
COPY T M
LINK 800

TEST M = -2
TJMP END

JUMP LOOP

MARK END
```

### XC (local)
```asm
MAKE

MARK LOOP
TEST M = -2
TJMP LAST
TEST M > X
TJMP GREATER
VOID M
VOID M
JUMP LOOP

MARK LAST
VOID M
TEST M > X
TJMP GREATER_LAST
VOID M
VOID M
DROP
HALT

MARK GREATER_LAST
VOID M
SEEK -1
COPY M F
DROP
HALT

MARK GREATER
COPY M X
SEEK -1
COPY M F
JUMP LOOP
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 294    | 70   | 24       |
