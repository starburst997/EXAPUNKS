# 11: UC Berkeley (EECS Department)

<div align="center"><img src="EXAPUNKS - UC Berkeley (165, 48, 7, 2022-12-05-19-21-30).gif" /></div>

## Instructions
> ﻿Locate the specified host (either *tape-1*, *tape-2*, or *tape-3*), and then locate the specified entry (‗ПАСЬЯНС‗) in the tape backup file in that host (file 200). Create a file in your host containing the entry's data.
> 
> The names of the target host and entry are available in file 300.
> 
> For more information see "Accessing Data in Legacy Storage Systems" in the first issue of the zine.

## Solution

### XA (global)
```asm
GRAB 300
COPY F X
DROP
LINK 800
MARK FIND_HOST
LINK 800
LINK 800
HOST T
TEST X = T
FJMP FIND_HOST

GRAB 200
SEEK 9999
MARK FIND_ENTRY
SEEK -3
TEST F = M
TJMP START_COPYING
COPY 0 M
SEEK -1
JUMP FIND_ENTRY

MARK START_COPYING
COPY 666 M
COPY F T
COPY F X
SEEK -9999
SEEK T
COPY X M
MARK COPYING
COPY F M
SUBI X 1 X
TEST X = 0
FJMP COPYING
```

### XB (global)
```asm
NOOP
NOOP
GRAB 300
SEEK 1
COPY F X
DROP
MAKE

MARK SEARCHING
COPY X M
TEST M = 666
FJMP SEARCHING

COPY M X
MARK COPYING
COPY M F
SUBI X 1 X
TEST X = 0
FJMP COPYING
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 165    | 48   | 7        |
