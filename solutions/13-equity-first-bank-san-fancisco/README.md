# 13: Equity First Bank (San Fancisco)

<div align="center"><img src="EXAPUNKS - Equity First Bank (4024, 17, 10, 2022-12-05-19-22-11).gif" /></div>

## Instructions
> Dispense all available cash from all connected ATMs.
> 
> For more information see "Network Exploration: Equity First Bank" in the first issue of the zine.

## Solution

### XA (global)
```asm
LINK 800
LINK 800
LINK 800
COPY 800 X
MARK REPLICATE
REPL DISPENSE
ADDI X 1 X
TEST X = 806
FJMP REPLICATE

MARK DISPENSE
LINK X
COPY #CASH X
MARK LOOP
COPY 20 #DISP
SUBI X 1 X
TEST X = 0
FJMP LOOP
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 4024   | 17   | 10       |
