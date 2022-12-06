# 33: TEC EXA-Blaster Modem - Pager Network

<div align="center"><img src="EXAPUNKS - TEC EXA-Blaster™ Modem (638, 62, 29, 2022-12-05-19-41-45).gif" /></div>

> Connect to each pager and copy EMBER-2's message (file 300) to the screen (#DATA). Then activate all of the pagers at exactly the same time by writing a value to each #PAGE register in the same cycle.
> 
> A list of phone numbers for the pagers is available in file 301.
> 
> For more information see "Hacker Skills: Modem Control at the Direct Level" in the second issue of the zine.

## Solution

### XA (local)
```asm
; SYNC ALL EXA TO PAGE
; AT THE SAME TIME
; KINDA TRICKY, HAD
; TO COUNT CYCLES
; AND MAKES SURE TO USE
; AN EVEN # OF INSTRUTI.

; CLOCK OFFSET
COPY M X ; 211 / 253

; START DIALS
GRAB 301
LINK 800

MARK DIAL
@REP 11
COPY F #DIAL
@END
REPL PAGER

; WAIT ------------
VOID M
COPY -1 #DIAL

MODE ; <- GLOBAL
SUBI X M X ; 30 / 36
MODE ; <- LOCAL

TEST EOF
FJMP DIAL

; GO BACK, TELL FINISH
WIPE
GRAB 300
LINK -1
KILL
HALT

MARK PAGER
GRAB 300
LINK 800

MARK COPY_DATA
COPY F #DATA
NOOP ; EVEN # OF CYCLES
TEST EOF
FJMP COPY_DATA

LINK -1
DROP
COPY 1 M

LINK 800

; PRECISE CYCLE WAIT
COPY X T
MARK WAIT_CYCLE
SUBI T 1 T
TJMP WAIT_CYCLE

COPY 1 #PAGE
```

### XB (local)
```asm
; I CALCULATED THE MAGIC
; NUMBERS BY FINDING THE
; CORRECT ONE FOR 2 TEST
; THEN COMPARE THEM
; AND FIGURE OUT A
; FORMULA

; COUNT WORDS & BROADCAS
GRAB 300

MARK COUNT
SEEK 1
ADDI X 1 X
TEST EOF
FJMP COUNT

LINK 800
DROP
LINK -1

; CALCULATE STARTING
; OFFSET FOR CYCLES
MULI X 14 T
ADDI 85 T M

MODE ; <- GLOBAL

; OFFSET TO REMOVE
; ON EACH EXA
MULI X 2 X
ADDI 12 X X

; BROADCAST OFFSET
MARK BROADCAST
COPY X M
JUMP BROADCAST
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 638    | 62   | 29       |
