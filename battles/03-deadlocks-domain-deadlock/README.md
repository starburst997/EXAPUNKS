# 3: Deadlock's Domain (Deadlock)

<div align="center"><img src="EXAPUNKS - Deadlock's Domain (2022-12-05-19-35-20).gif" /></div>

## Instructions
> To win this battle you must grab files as they spawn in the central hosts and bring them back to your host. 
> 
> Reading the #FILE register will tell you the ID of the most recently created file currently in that host.
> 
>      Gain one point for every file you bring back to your host.
> 
>      Lose one point every time one of your EXAs executes a KILL instruction.
> 
> For more information see "Hacker Battle Domination" in the second issue of the zine.

## Solution

### XA (global)
```asm
MARK BEGIN
COPY 800 X
REPL START
COPY 801 X
REPL START
COPY 802 X
JUMP BEGIN

MARK START
LINK 800
LINK X
KILL
LINK 799
KILL
LINK X
KILL
GRAB #FILE
LINK -1
LINK -1
DROP

MARK LOOP
LINK 800
LINK X
GRAB #FILE
LINK -1
LINK -1
DROP
JUMP LOOP
```

