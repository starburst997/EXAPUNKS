# 26: Equity First Bank - San Francisco - ATMs Offline

<div align="center"><img src="EXAPUNKS - Equity First Bank (113, 52, 6, 2022-12-05-19-36-30).gif" /></div>

> ﻿Move EMBER-2's new account (file 300) into *checking*. Then iterate over the checking accounts listed in the directory (file 199) and, in that order, transfer $1.00 from each target account to EMBER-2's account. Finally, add the file ID of EMBER-2's account file to the end of the directory.
> 
> The keywords ‗CREDIT‗ and ‗DEBIT‗ are available in file 301.
> 
> For more information see "Network Exploration: Equity First Bank" in the first issue of the zine.

## Solution

### XC (global)
```asm
GRAB 301
SEEK 1
COPY F X
REPL DEBIT_BOT
SEEK -9999
COPY F X
DROP
GRAB 300
SEEK 9999
LINK 800
LINK 800

MARK LOOP
COPY M T
COPY T F
COPY X F
COPY 1 F
COPY 0 F
JUMP LOOP

; REPL: DEBIT ACC
MARK DEBIT_LOOP
GRAB M
MODE
COPY F M
MODE
SEEK 9999
COPY T F
COPY X F
COPY 1 F
COPY 0 F
DROP
JUMP DEBIT_LOOP

MARK DEBIT_BOT
GRAB 300
COPY F T
DROP
LINK 800
LINK 800

MODE
GRAB 199
REPL DEBIT_LOOP

MARK ITERATE_LOOP
COPY F M
TEST EOF
FJMP ITERATE_LOOP

COPY 300 F

; WAIT UNTIL DONE
COPY 3 T
MARK WAIT
SUBI T 1 T
FJMP KILL
JUMP WAIT

MARK KILL
KILL
KILL
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 113    | 52   | 6        |
