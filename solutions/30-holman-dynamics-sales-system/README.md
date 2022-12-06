# 30: Holman Dynamics - Sales System

<div align="center"><img src="EXAPUNKS - Holman Dynamics (4459, 119, 7, 2022-12-05-19-38-24).gif" /></div>

> Create a file in your host containing the contiguous 16-value sequence from the garbage file (file 199) that is a valid credit card number. There will be exactly one such sequence.
> 
> For more information see "How to Validate Credit Card Numbers" in the second issue of the zine.

## Solution

### XA (global)
```asm
LINK 800
LINK 802
LINK 799
GRAB 199

; FIX EDGE CASE VERY END
SEEK 9999
COPY -9999 F
SEEK -9999

; FIND 16 SEQ
MARK RESET
COPY 0 X
MARK LOOP
ADDI X 1 X
TEST F < 0
TJMP RESET

TEST X > 15
FJMP LOOP

; FOUND
SEEK -16
COPY 0 X
COPY 0 T

@REP 8
COPY F M
ADDI M T T
SEEK 1
@END

SEEK -15
@REP 8
ADDI T F T
SEEK 1
@END

SWIZ T 0001 T
FJMP VALID

; RESET COUNTER TO -1
SEEK -1
COPY 15 X
JUMP LOOP


MARK VALID
MODE
REPL DUPE
SEEK -17

@REP 16
COPY F M
@END

SEEK 9999
SEEK -1
VOID F

HALT

MARK DUPE
MAKE
@REP 16
COPY M F
@END

LINK -1
LINK -1
LINK -1
KILL
```

### XB (global)
```asm
; TRANSFORM ODD #
JUMP LOOP

MARK GREATER
SUBI X 9 M

MARK LOOP
MULI M 2 X
TEST X > 9
TJMP GREATER

COPY X M
JUMP LOOP
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 4459   | 119  | 7        |
