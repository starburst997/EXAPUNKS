# 24: King's Ransom Online - US West Realm

<div align="center"><img src="EXAPUNKS - King's Ransom Online (110, 49, 39, 2022-12-05-19-35-52).gif" /></div>

> ﻿Reset the ownership of all castles and sub-buildings to ‗P00000‗ (file 300), the player ID for unowned buildings.
> 
> To ensure that there are no witnesses you must first disconnect all connected players. Terminate every EXA in every host before changing any castle or sub-building files anywhere in the network. If you leave an EXA alive in one host while changing a file in another you will fail the task.
> 
> For more information see "Network Exploration: King's Ransom Online" in the second issue of the zine.

## Solution

### XA (local)
```asm
GRAB 300
COPY F T
DROP
VOID M
LINK 800

COPY 800 X
REPL OVERWRITE
COPY 801 X
REPL OVERWRITE
COPY 802 X
REPL OVERWRITE
COPY 803 X
REPL OVERWRITE
COPY 804 X
REPL OVERWRITE
COPY 805 X

MARK OVERWRITE
LINK X
COPY T X

GRAB 200
SEEK 2
COPY X F

MARK LOOP_SUB
REPL REPLACE_SUB
COPY F M
COPY X M
TEST EOF
TJMP END
JUMP LOOP_SUB

MARK REPLACE_SUB
GRAB M
SEEK 2
COPY M F
TEST EOF
FJMP LOOP_SUB

MARK END
```

### XB (local)
```asm
LINK 800
COPY 800 X

MARK KILL
LINK X
KILL
KILL
KILL
LINK -1
ADDI X 1 X
TEST X = 806
FJMP KILL

LINK -1
COPY 1 M
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 110    | 49   | 39       |
