# 5: Aberdeen - selenium_wolf

<div align="center"><img src="EXAPUNKS - Aberdeen (2022-12-05-19-40-00).gif" /></div>

> To win this battle you must occupy a majority of the hosts for as long as possible. You occupy a host if you have more EXAs in it than your opponent.
> 
>      Gain one point every cycle you occupy more hosts than your opponent.
> 
>      Lose one point every time one of your EXAs executes a KILL instruction.
> 
> Writing any value to the #NUKE register will destroy all EXAs in that host, including the EXA that triggered it.
> 
> For more information see "Hacker Battle Domination" in the second issue of the zine.

## Solution

### XA (global)
```asm
GRAB 300
COPY F M
COPY F M
COPY F M
COPY F M
COPY F M
```

### XB (global)
```asm
LINK 800
GRAB 200
SEEK 9999
COPY M F
COPY M F
COPY M F
COPY M F
COPY M F
```

