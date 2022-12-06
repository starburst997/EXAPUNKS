# 15: Trash World News - Unknown Context

<div align="center"><img src="EXAPUNKS - TRASH WORLD NEWS (568, 26, 4, 2022-12-05-19-22-30).gif" /></div>

## Instructions
> ﻿Find and replace the keywords in the target message (file 212) as directed by EMBER-2.
> 
> A list of keyword pairs indicating which words should be found and what they should be replaced with is available in file 300. For example, the keyword ‗AI‗ should be replaced with the keyword ‗COLLECTIVE‗. Each keyword will only occur once, but may occur in any order.
> 
> Also, move file 200 to the *outbox*.

## Solution

### XA (global)
```asm
GRAB 300
MARK LOOP
COPY F M
COPY F M
TEST EOF
FJMP LOOP
COPY 666 M
```

### XB (global)
```asm
LINK 800
LINK 799
GRAB 212
MARK REPLACE
COPY M X
TEST X = 666
TJMP END
SEEK -9999
MARK SEARCH
TEST F = X
FJMP SEARCH
SEEK -1
COPY M F
JUMP REPLACE

MARK END
DROP
LINK -1
GRAB 200
LINK 800
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 568    | 26   | 4        |
