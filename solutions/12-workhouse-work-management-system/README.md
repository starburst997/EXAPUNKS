# 12: Workhouse (Work Management System)

<div align="center"><img src="EXAPUNKS - WorkHouse (523, 28, 2, 2022-12-05-19-21-45).gif" /></div>

## Instructions
> Locate EMBER-2's user file in the *users* host and overwrite it so that the sum of the values is the same but no individual value exceeds $75. All values, except for the last, must be the maximum value ($75). You will need to add additional values to accomplish this.
> 
> EMBER-2's username is available in file 300.
> 
> Note that the sum of the values in EMBER-2's account will always be less than $10,000.
> 
> For more information see "Network Exploration: Workhouse" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
COPY F X
DROP
LINK 800
GRAB 199
MARK FIND_FILE_ID
TEST F = X
SEEK 2
FJMP FIND_FILE_ID

SEEK -1
COPY F X
DROP
LINK 799
GRAB X

COPY 0 X
SEEK 2
MARK SUM
ADDI X F X
TEST EOF
FJMP SUM

SEEK -9999
SEEK 2
MARK OVERWRITE
COPY 75 F
SUBI X 75 X
TEST X < 75
FJMP OVERWRITE

COPY X F
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 523    | 28   | 2        |
