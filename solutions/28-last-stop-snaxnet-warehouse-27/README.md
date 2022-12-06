# 28: Last Stop Snaxnet (Warehouse 27)

<div align="center"><img src="EXAPUNKS - Last Stop SNAXNET (301, 98, 30, 2022-12-05-19-37-37).gif" /></div>

## Instructions
> An array of five Zippe-type gas centrifuges, ZGC0 through ZGC4, are connected in a cascade configuration.
> 
> Read each of the #ZGCX registers and determine which centrifuge currently has the highest pressure. Then disable that centrifuge's regulator by writing a value of 0 to its #POWR register. Repeat this process until all five regulators have been disabled.

## Solution

### [XB](XB.exa) (global)
```asm
LINK 800
LINK 798

MARK FWD_LISTENS
COPY M X
COPY X T
FJMP END

MARK FWD
LINK 800
SUBI T 1 T
TJMP FWD
COPY 0 #POWR
COPY 2 M
COPY X T

MARK BWD
LINK -1
SUBI T 1 T
TJMP BWD
JUMP FWD_LISTENS

MARK END
COPY 0 #POWR
COPY 2 M
JUMP FWD_LISTENS
```

### [XD](XD.exa) (local)
```asm
LINK 800
LINK 799

MAKE

MARK START
COPY -1 X

MARK COUNTER
TEST X = 4
TJMP SEND

ADDI X 1 X
TEST M = 1
FJMP COUNTER

; SAVE COUNTER
COPY X F
JUMP COUNTER

MARK SEND
SEEK -1
MODE
COPY F M
VOID M
MODE
COPY 2 M
JUMP START
```

### [XA](XA.exa) (local)
```asm
LINK 800
LINK 799

; UNROLL FOR BETTER CYCL
@REP 5
MARK TEST@{0,1}
TEST #ZGC@{0,1} > X
TJMP COPY@{0,1}
COPY 0 M
@END

MARK TEST5
TEST X = 0
TJMP KILL
VOID M
COPY 0 X
JUMP TEST0

@REP 5
MARK COPY@{0,1}
COPY #ZGC@{0,1} X
COPY 1 M
JUMP TEST@{1,1}
@END

MARK KILL
KILL
GRAB 400
WIPE
LINK -1
LINK 798
KILL
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 301    | 98   | 30       |
