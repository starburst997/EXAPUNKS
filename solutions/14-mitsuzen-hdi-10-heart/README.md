# 14: Mitsuzen HDI-10 - Heart

<div align="center"><img src="EXAPUNKS - Mitsuzen HDI-10 (119, 32, 7, 2022-12-05-19-22-20).gif" /></div>

## Instructions
> Read a value from the nerve connected to your central nervous system (CNS) and make your heart beat by writing a sequence of values to your sinoatrial (SA-N) and atrioventricular (AV-N) nodes as indicated in the HDI-10 I/O log when holding the "SHOW GOAL" button. The length of each sequence of values should be equal to the value from the CNS divided by -10. Repeat _ad infinitum_.
> 
> It is not necessary to leave no trace. Your EXAs should be written to operate indefinitely.
> 
> For more information see "Debugging the Phage" in the first issue of the zine.

## Solution

### XA (global)
```asm
LINK 800

MARK READ
COPY #NERV X
DIVI X -10 X
COPY X M
COPY X M
JUMP READ
```

### XB (global)
```asm
LINK 800
LINK 1
LINK 1

MARK BEAT
COPY M X
COPY 40 #NERV
MARK SEQUENCE
COPY -70 #NERV
SUBI X 1 X
TEST X = 1
FJMP SEQUENCE
JUMP BEAT
```

### XC (global)
```asm
LINK 800
LINK 3
LINK 3

COPY -70 #NERV
MARK BEAT
COPY M X
COPY 40 #NERV
MARK SEQUENCE
COPY -70 #NERV
SUBI X 1 X
TEST X = 1
FJMP SEQUENCE
JUMP BEAT

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 119    | 32   | 7        |
