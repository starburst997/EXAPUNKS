# 4: Trash World News (Tutorial 4)

<div align="center"><img src="EXAPUNKS - TRASH WORLD NEWS (308, 11, 2, 2022-12-05-19-20-08).gif" /></div>

## Instructions
> File 200 contains exactly one number, N. Create a new file in the *outbox* containing the numbers N through 0 in decreasing order. When you are finished, delete file 200.
> 
> For help completing this task see "Ghast Walks U Thru It" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
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

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 308    | 11   | 2        |
