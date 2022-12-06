# 3: Trash World News - Tutorial 3

<div align="center"><img src="EXAPUNKS - TRASH WORLD NEWS (11, 12, 4, 2022-12-05-19-19-57).gif" /></div>

> File 199 contains exactly two values: a keyword and a number. Create a new file in the *outbox* and copy those two values to it, swapping their order so that the number is first. When you are finished, delete file 199.
> 
> For help completing this task see "Ghast Walks U Thru It" in the first issue of the zine.

## Solution

### XA (global)
```asm
LINK 800
LINK 799
GRAB 199
COPY F X
COPY F M
COPY X M
WIPE
```

### XB (global)
```asm
LINK 800
LINK 800
MAKE
COPY M F
COPY M F
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 11     | 12   | 4        |
