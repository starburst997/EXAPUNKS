# 29: Mitsuzen HDI-10 (Visual Cortex)

<div align="center"><img src="EXAPUNKS - Mitsuzen HDI-10 (1878, 41, 359, 2022-12-05-19-37-59).gif" /></div>

## Instructions
> Read a value from each of the optic nerves present and write the correct value to the nerve that runs deeper into your visual cortex (V-CTX). To determine the value that should be written, count the number of values read that are greater than -55, multiply that count by 5, and then subtract 75. Repeat _ad infinitum_.
> 
> It is not necessary to leave no trace. Your EXAs should be written to operate indefinitely.
> 
> For more information see "Debugging the Phage" in the first issue of the zine.

## Solution

### XB (global)
```asm
LINK 800

MARK START
COPY 0 X
JUMP TEST

MARK LOOP
TEST M = -2
TJMP END
LINK M

MARK TEST
TEST #NERV > -55
FJMP LOOP

MARK COUNT
ADDI X 1 X
JUMP LOOP


MARK END
LINK 3
LINK 3

MULI X 5 X
SUBI X 75 #NERV

LINK -3
LINK -1
JUMP START
```

### XC (global)
```asm
MARK LOOP
COPY 1 M
COPY 1 M

COPY 1 M
COPY 1 M

COPY -3 M
COPY -3 M

COPY -3 M
COPY -3 M

COPY -1 M
COPY -1 M

COPY -1 M
COPY -1 M

COPY 3 M
COPY 3 M

COPY 1 M
COPY 1 M

COPY -2 M

JUMP LOOP
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 1878   | 41   | 359      |
