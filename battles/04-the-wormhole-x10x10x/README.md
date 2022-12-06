# 4: The Wormhole - X10X10X

<div align="center"><img src="EXAPUNKS - The Wormhole (2022-12-05-19-36-44).gif" /></div>

## Instructions
> To win this battle you must fill the network's hosts with as many of your EXAs as you can. Note that each pair of test runs has its own unique network layout, with bi-directional links between hosts that use the prime numbers between 2 and 13 as link IDs (2, 3, 5, 7, 11, and 13).
> 
>      Gain one point for every EXA you control in the network at the end of the battle.
> 
>      Lose one point every time one of your EXAs executes a KILL instruction.
> 
> For more information see "Hacker Battle Domination" in the second issue of the zine.

## Solution

### XA (global)
```asm
LINK 800

;REPL DUPE_5
REPL DUPE_11

MARK DUPE_2
REPL LINK_2
MARK DUPE_3
REPL LINK_3
MARK DUPE_5
REPL LINK_5
MARK DUPE_7
REPL LINK_7
MARK DUPE_11
REPL LINK_11
MARK DUPE_13
REPL LINK_13

JUMP DUPE_2

MARK LINK_2
LINK 2
REPL DUPE_3
;REPL DUPE_7
JUMP DUPE_13
MARK LINK_3
LINK 3
REPL DUPE_5
;REPL DUPE_11
JUMP DUPE_2
MARK LINK_5
LINK 5
REPL DUPE_7
;REPL DUPE_13
JUMP DUPE_3
MARK LINK_7
LINK 7
REPL DUPE_11
;REPL DUPE_2
JUMP DUPE_5
MARK LINK_11
LINK 11
REPL DUPE_13
;REPL DUPE_3
JUMP DUPE_11
MARK LINK_13
LINK 13
REPL DUPE_2
;REPL DUPE_5
JUMP DUPE_11
```

