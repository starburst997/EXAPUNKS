# 2: Valhalla - =Plastered

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

<div align="center"><img src="EXAPUNKS - Valhalla (2022-12-05-19-33-03).gif" /></div>

### XA (global)
```exa
LINK 800
GRAB 200
ADDI F F X
MULI X F X
SUBI X F F
LINK 800

```

