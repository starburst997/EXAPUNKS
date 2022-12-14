# 31: US Government (Fema Genetic Database)

<div align="center"><img src="EXAPUNKS - U.S. Government (999, 131, 71, 2022-12-05-19-40-24).gif" /></div>

## Instructions
> ﻿Overwrite the genetic sequence of ‗SEN WALKER CAINE JR‗ with the genetic sequence of ‗PRES WALKER CAINE‗ so that it looks like the younger politician is actually a clone of the older politician.
> 
> The names of these two politicians are available in file 300.
> 
> Note that you may need to overwrite a data chunk with another data chunk from the same file.
> 
> For more information see "Accessing Data in Legacy Storage Systems" in the first issue of the zine.

## Solution

### [XA](XA.exa) (local)
```asm
; FIRST ATTEMPTS WERE
; BAD, BUT IM HAPPY
; WITH THIS ONE
;
;
; BROADCASTER SEND DNA
; GLOBALLY
;
; OVERWRITER RECEIVE DNA
; GLOBALLY
;
; BROAD/OVERW MAKE COPY
; OF DNA IN REPL

MARK START
GRAB 300
FJMP SKIP_SEEK
SEEK 1

MARK SKIP_SEEK
COPY F X
DROP

LINK 800

LINK 801
GRAB 200

MARK FIND_NAME
TEST F = X
TJMP FOUND_NAME
SEEK 10
JUMP FIND_NAME


MARK FILE_COPIER
MAKE

@REP 10
COPY M F
@END

FILE X
COPY X M
HALT


MARK KILL
WIPE
LINK -1
KILL
HALT


MARK FOUND_NAME
REPL FILE_COPIER

MARK LOOP_LOCAL_SEND
@REP 10
COPY F M
@END

DROP
COPY M X
GRAB X

TEST X = 400 ; FIRST
TJMP BROADCASTER_START
TEST X > 401 ; DNA SEND
TJMP BROADCASTER_DNA


; **********************
; OVERWRITER START *****
LINK -1
COPY 1 M
LINK -1

; WAIT LOCAL
MARK WAIT_OVERWRITER
VOID M

; COPY FILE TO X -> REPL
MARK DUPE_OVERWRITER
COPY F X
REPL OVERWRITER_DUPE
JUMP WAIT_OVERWRITER

MARK OVERWRITER_DUPE
MODE ; <- GLOBAL

LINK 800

SWIZ X 3 T
ADDI 800 T T
LINK T

SWIZ X 2 T
ADDI 200 T T
GRAB T

SWIZ X 1 T
MULI T 10 X
SEEK X

@REP 10
COPY M F
@END

HALT


; *********************
; BROADCASTER START ****
MARK BROADCASTER_START
; REPL FOR OVERWRITER
LINK -1
LINK -1
REPL START
LINK 800

; WAIT LOCAL
MARK WAIT_BROADCASTER
VOID M

; COPY FILE TO X -> REPL
TEST EOF
TJMP KILL
COPY F X
REPL BROADCASTER_DUPE
JUMP WAIT_BROADCASTER

MARK BROADCASTER_DUPE
SWIZ X 3 T
ADDI 800 T T
LINK T

SWIZ X 2 T
ADDI 200 T T
GRAB T

SWIZ X 1 T
MULI T 10 X
SEEK X

COPY 10 T
REPL FILE_COPIER

JUMP LOOP_LOCAL_SEND

MARK BROADCASTER_DNA
LINK -1
LINK -1
COPY 1 M
MODE ; <- GLOBAL

@REP 10
COPY F M
@END

MODE ; <- LOCAL
LINK 800
COPY 1 M
WIPE
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 999    | 131  | 71       |
