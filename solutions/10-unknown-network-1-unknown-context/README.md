# 10: Unknown Network 1 (Unknown Context)

<div align="center"><img src="EXAPUNKS - UNKNOWN NETWORK 1 (31, 22, 27, 2022-12-05-19-21-17).gif" /></div>

## Instructions
> Find file 276 in the network and bring it back to your host.
> 
> Note that an EXA cannot grab a file that is being held by another EXA.

## Solution

### [XA](XA.exa) (global)
```asm
COPY 4 X

MARK A
LINK 800
SUBI X 1 X
TEST X = 0
TJMP END
REPL A
JUMP B

MARK B
LINK 801
SUBI X 1 X
TEST X = 0
TJMP END
REPL B
JUMP A

MARK END
KILL
GRAB 276
LINK -1
LINK -1
LINK -1
LINK -1
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 31     | 22   | 27       |
