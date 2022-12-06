# 16: TEC Redshift (Development Kit)

<div align="center"><img src="EXAPUNKS - TEC Redshift™ (7944, 27, 4, 2022-12-05-19-23-05).gif" /></div>

## Instructions
> There is an unknown three-digit code (such as 4-7-3) that, when entered one digit at a time into #PASS, will unlock the link between *debug* and *secret*. Find the three-digit code and create a file in your host that contains the code as a sequence of three values, followed by the development kit's RDK ID.

## Solution

### XA (global)
```asm
LINK 800

MARK BRUTE_FORCE
TEST MRD
TJMP DIE

@REP 3
SWIZ X 000@{3,-1} #PASS
@END

REPL SECRET
ADDI X 1 X
FJMP BRUTE_FORCE

MARK SECRET
LINK 800
COPY 666 M
GRAB 199
COPY F T
DROP
MAKE
@REP 3
SWIZ X 000@{3,-1} F
@END
COPY T F
LINK -1
LINK -1
HALT

MARK DIE
COPY M X
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 7943   | 26   | 4        |
