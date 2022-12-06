# 7: Last Stop Snaxnet (Factory 11)

<div align="center"><img src="EXAPUNKS - Last Stop SNAXNET (31, 11, 2, 2022-12-05-19-20-41).gif" /></div>

## Instructions
> ﻿Remove the keyword ‗PEANUTS‗ (file 300) from the Peanut Blast recipe (file 237).
> 
> Note that the target keyword will appear in a different position in each of the 100 test runs. To view and debug each of the different test runs, click the arrow buttons next to the "TEST RUN" display above.

## Solution

### XA (global)
```asm
GRAB 300
COPY F X
DROP
LINK 800
LINK 800
GRAB 237
MARK LOOP
TEST F = X
FJMP LOOP
SEEK -1
VOID F
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 31     | 11   | 2        |
