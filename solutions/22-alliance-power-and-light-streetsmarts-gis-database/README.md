# 22: Alliance Power and Light - Streetsmarts GIS Database

<div align="center"><img src="EXAPUNKS - Alliance Power and Light (44, 45, 44, 2022-12-05-19-35-09).gif" /></div>

> Locate the two hosts with the specified hostnames (file 300), which correspond to the target power grid substations. When you've found them, cut the power by writing a value of 0 to #POWR.
> 
> For more information see "Network Exploration: Geographic Information Systems" in the second issue of the zine.

## Solution

### XA (global)
```asm
GRAB 300
COPY F X
DROP

LINK 800

LINK 800
LINK 800


MARK DUPE
REPL CHECK
LINK 802
JUMP DUPE


MARK CUT_POWER
COPY M #POWR
HALT

MARK WALK
LINK 801

MARK CHECK
HOST T
TEST X = T
TJMP CUT_POWER
JUMP WALK
```

### XB (global)
```asm
NOOP
NOOP
NOOP

GRAB 300
SEEK 1
COPY F X
DROP

LINK 800

LINK 800
LINK 800


MARK DUPE
REPL CHECK
LINK 802
JUMP DUPE


MARK CUT_POWER
COPY 0 M
COPY 0 #POWR
HALT


MARK WALK
LINK 801

MARK CHECK
HOST T
TEST X = T
TJMP CUT_POWER
JUMP WALK
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 44     | 45   | 44       |
