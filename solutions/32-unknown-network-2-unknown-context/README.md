# 32: Unknown Network 2 (Unknown Context)

<div align="center"><img src="EXAPUNKS - UNKNOWN NETWORK 2 (243, 55, 53, 2022-12-05-19-41-10).gif" /></div>

## Instructions
> Terminate all other EXAs and bring any files they were holding back to your host. Only EXAs in the central host will be holding files, and their file IDs will always be between 200 and 299, inclusive.
> 
> Note that some links may become non-traversable as a result of your actions.

## Solution

### [XA](XA.exa) (global)
```asm
; GRAB FILE

@REP 5
LINK 800
@END

@REP 6
KILL
@END

COPY 200 X
MARK LOOP_BRING_FILE
@REP 10
REPL BRING_FILE
ADDI X 1 X
@END
TEST X < 300
TJMP LOOP_BRING_FILE

@REP 4
LINK -1
REPL KILLER
@END
HALT

MARK KILLER
KILL
KILL
HALT

MARK BRING_FILE
GRAB X
@REP 5
LINK -1
@END
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 243    | 55   | 53       |
