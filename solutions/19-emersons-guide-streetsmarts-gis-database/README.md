# 19: Emerson's Guide - Streetsmarts GIS Database

> Each host contains a list of restaurants and their ratings, from one to five stars (file 200). Locate the entry that corresponds to the Last Stop on Eddy Street and change its rating from one to five stars.
> 
> The name of the target restaurant and its location within the GIS grid is available in file 300. The first coordinate is the number of times to move east, while the second coordinate is the number of times to move north (positive) or south (negative).
> 
> For more information see "Network Exploration: Geographic Information Systems" in the second issue of the zine.

## Solution

<div align="center"><img src="EXAPUNKS - Emerson's Guide (53, 52, 6, 2022-12-05-19-32-52).gif" /></div>

### XA (global)
```exa
GRAB 300
SEEK 1

LINK 800

; FIGURE OUT E/W & MOVE
; COULD BE ANOTHER EXA
COPY F X

TEST X = 0
TJMP LOCATE_NORTH_SOUTH
TEST X < 0
TJMP WEST
COPY X T
COPY 801 X
JUMP LOOP_EAST_WEST
MARK WEST
MULI X -1 T
COPY 803 X

MARK LOOP_EAST_WEST
LINK X
SUBI T 1 T
FJMP LOCATE_NORTH_SOUTH
JUMP LOOP_EAST_WEST

; FIGURE OUT N/S & MOVE
MARK LOCATE_NORTH_SOUTH
COPY F X

TEST X = 0
TJMP CHANGE_STARS
TEST X < 0
TJMP SOUTH
COPY X T
COPY 800 X
JUMP LOOP_NORTH_SOUTH
MARK SOUTH
MULI X -1 T
COPY 802 X

MARK LOOP_NORTH_SOUTH
LINK X
SUBI T 1 T
FJMP CHANGE_STARS
JUMP LOOP_NORTH_SOUTH

MARK CHANGE_STARS
SEEK -9999
COPY F X
WIPE
GRAB 200

MARK CHECK_NAME
TEST X = F
TJMP ADD_STARS
SEEK 5
JUMP CHECK_NAME

MARK ADD_STARS
COPY F X
COPY X F
COPY X F
COPY X F
COPY X F
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 53     | 52   | 6        |
|--------|------|----------|
