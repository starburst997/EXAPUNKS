# 3: Deadlock's Domain - Deadlock

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

<div align="center"><img src="EXAPUNKS - Deadlock's Domain (2022-12-05-19-35-20).gif" /></div>

### XA (global)
```exa
LINK 800
LINK 799
GRAB 199
COPY F X
COPY F M
COPY X M
WIPE
```

### XB (global)
```exa
LINK 800
LINK 800
MAKE
COPY M F
COPY M F
```

