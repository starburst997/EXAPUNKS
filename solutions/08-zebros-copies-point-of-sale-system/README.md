# 8: Zebros Copies - Point-Of-Sale System

> Erase Ghast's debt to the copy shop by zeroing out his balance in the customer database (file 200) and appending a payment to the payment log (file 201) with today's date and the exact amount of his prior balance.
> 
> Ghast's customer ID is available in file 300.
> 
> For more information see "Network Exploration: Digicash Point-of-Sale Systems" in the first issue of the zine.

## Solution

<div align="center"><img src="EXAPUNKS - Zebros Copies (101, 24, 4, 2022-12-05-19-20-53).gif" /></div>

### XA (global)
```exa
LINK 800
LINK 801
COPY #DATE X
LINK -1
GRAB 201
SEEK 9999
COPY X F
COPY M F
COPY M F
COPY M F
```

### XB (global)
```exa
GRAB 300
COPY F X
DROP
LINK 800
GRAB 200
MARK LOOP
TEST F = X
FJMP LOOP
COPY X M
COPY F M
COPY F M
SEEK -2
COPY 0 F
COPY 0 F
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 101    | 24   | 4        |
|--------|------|----------|
