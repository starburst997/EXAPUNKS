# 20: Mitsuzen HDI-10 - Left Hand

<div align="center"><img src="EXAPUNKS - Mitsuzen HDI-10 (69, 54, 19, 2022-12-05-19-33-17).gif" /></div>

> There are three nerve signals that need to be relayed: muscle control (M), which runs from your central nervous system (CNS) to your hand (HND), and heat (H) and pressure (P), which run the other direction.
> 
> For each signal, read a value from the input nerve and relay it to the output nerve. Repeat _ad infinitum_.
> 
> It is not necessary to leave no trace. Your EXAs should be written to operate indefinitely.
> 
> For more information see "Debugging the Phage" in the first issue of the zine.

## Solution

### XC (global)
```asm
LINK 800


COPY 2 T
COPY 3 X
REPL GO_RELAY

COPY -3 X
REPL GO_READ

COPY 3 X
COPY 1 T
REPL GO_RELAY

COPY -3 X
REPL GO_READ

COPY 0 T
NOOP
REPL GO_RELAY

COPY 3 X


MARK GO_READ
MAKE
SUBI 2 T F
LINK X
MARK GO_READ_LOOP
LINK X
FJMP READ_START
SUBI T 1 T
JUMP GO_READ_LOOP

MARK GO_RELAY
MAKE
SUBI 2 T F
LINK X
MARK GO_RELAY_LOOP
LINK X
FJMP RELAY_START
SUBI T 1 T
JUMP GO_RELAY_LOOP


MARK RELAY_START
SEEK -1
COPY F T
MARK RELAY_LOOP
FJMP RELAY
SUBI T 1 T
JUMP RELAY_LOOP
MARK RELAY
COPY #NERV M
JUMP RELAY


MARK READ_START
SEEK -1
COPY F T
MARK READ_LOOP
FJMP READ
SUBI T 1 T
JUMP READ_LOOP
MARK READ
COPY M #NERV
NOOP
JUMP READ
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 69     | 54   | 19       |
