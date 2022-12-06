# 5: Aberdeen - selenium_wolf

<div align="center"><img src="EXAPUNKS - Aberdeen (2022-12-05-19-40-00).gif" /></div>

## Instructions
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

### XB (global)
```asm
LINK 800
LINK 801

MARK DUPE_LOOP
REPL DUPE
JUMP DUPE_LOOP

MARK DUPE
LINK 800
LINK 800
LINK -1
REPL NUKE
LINK -1
LINK 801
JUMP DUPE

MARK NUKE
COPY 1 #NUKE
```

### XC (global)
```asm
LINK 800
LINK 802

MARK DUPE_LOOP
REPL DUPE
JUMP DUPE_LOOP

MARK DUPE
LINK 800
LINK 800
@REP 5
REPL IDLE
@END

MARK IDLE
JUMP IDLE
```

