# 21: Sawayama Wonderdisc - Drive Controller

<div align="center"><img src="EXAPUNKS - Sawayama WonderDisc (8294, 58, 124, 2022-12-05-19-33-53).gif" /></div>

## Instructions
> Modify your WonderDisc, which normally only plays SSEA region games, to play games from any region.
> 
> The SSEA region code is available in file 300.
> 
> It is not necessary to leave no trace. Your EXAs should be written to operate indefinitely.
> 
> For more information see "Hardware Hacks: Sawayama WonderDisc" in the second issue of the zine.

## Solution

### XA (global)
```asm
LINK 800

COPY 8 #AUTH
COPY 0 #AUTH
COPY 3 #AUTH
COPY 2 #AUTH
COPY 7 #AUTH
COPY 1 #AUTH
COPY 0 #AUTH
COPY 4 #AUTH
COPY 9 #AUTH
COPY 5 #AUTH
COPY 1 #AUTH
COPY 2 #AUTH
COPY 5 #AUTH
COPY 2 #AUTH
COPY 6 #AUTH

MARK READ_TRAK
COPY #TRAK T
LINK 801
GRAB T

MARK SEND
TEST EOF
TJMP END
COPY F M
JUMP SEND

MARK END
COPY -1 M
DROP
LINK -1
JUMP READ_TRAK
```

### XB (local)
```asm
LINK 800

MARK START
MAKE

MARK COPY
COPY M X
TEST X = -1
TJMP END
COPY X F
JUMP COPY

MARK END
LINK 800
DROP
LINK -1
JUMP START
```

### XC (local)
```asm
GRAB 300
LINK 800
JUMP RELAY

MARK REPLACE
SEEK -1
COPY F M

MARK RELAY
MODE
COPY M X
MODE
TEST X > -2
FJMP REPLACE
COPY X M
JUMP RELAY
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 8294   | 58   | 124      |
