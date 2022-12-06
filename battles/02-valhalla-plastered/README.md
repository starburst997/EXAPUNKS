# 2: Valhalla (=Plastered)

<div align="center"><img src="EXAPUNKS - Valhalla (2022-12-05-19-33-03).gif" /></div>

## Instructions
> To win this battle you must control a majority of the hosts for as long as possible. 
> 
> To take control of a host, write any value to its #CTRL register. Reading from a #CTRL register will tell if you (1) or your opponent (-1) controls the host.
> 
>      Gain one point every cycle you control more hosts than your opponent.
> 
>      Lose one point every time one of your EXAs executes a KILL instruction.
> 
> For more information see "Hacker Battle Domination" in the second issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800

COPY 1 #CTRL
LINK -1

MARK FORWARD_FIRST
COPY 1 #CTRL
LINK 800
;COPY 1 #CTRL
LINK 800
COPY 1 #CTRL
LINK 800
COPY 1 #CTRL
LINK 800

KILL

COPY 1 #CTRL
LINK 800
COPY 1 #CTRL
LINK 800
COPY 1 #CTRL
LINK 800
COPY 1 #CTRL
LINK 800

JUMP BACKWARD

MARK FORWARD
COPY 1 #CTRL
LINK 800
;COPY 1 #CTRL
LINK 800
COPY 1 #CTRL
LINK 800
COPY 1 #CTRL
LINK 800
COPY 1 #CTRL
LINK 800
COPY 1 #CTRL
LINK 800
COPY 1 #CTRL
LINK 800
COPY 1 #CTRL
LINK 800


MARK BACKWARD
COPY 1 #CTRL
LINK -1
COPY 1 #CTRL
LINK -1
COPY 1 #CTRL
LINK -1
COPY 1 #CTRL
LINK -1
COPY 1 #CTRL
LINK -1
COPY 1 #CTRL
LINK -1
COPY 1 #CTRL
LINK -1
COPY 1 #CTRL
LINK -1
COPY 1 #CTRL

JUMP FORWARD
```

