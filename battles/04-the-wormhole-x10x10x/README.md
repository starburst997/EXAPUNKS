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
GRAB 200
LINK 800
COPY F T
WIPE
MAKE
ADDI 1 T T
MARK LOOP
SUBI T 1 T
COPY T F
TJMP LOOP
```

