# 17: Digital Library Project - Patron Access System

> Books are stored in the host corresponding to the first digit of their call number, while a book's file ID is 200 plus the last two digits of the call number. For example, book 512 would be stored in the host *500-599* as file 212.
> 
> Duplicate each of the books requested by EMBER-2 and bring them back to your host.
> 
> The call numbers for the books EMBER-2 wants are available in file 300.
> 
> Note that EMBER-2 will never request more than one book from the same host.

## Solution

<div align="center"><img src="EXAPUNKS - Digital Library Project (1489, 50, 37, 2022-12-05-19-31-17).gif" /></div>

### XB (global)
```exa
@REP 3
NOOP
@END

MARK BOOK
MODE
TEST MRD
FJMP STOP

MAKE
REPL BOT
COPY M T
MODE
COPY T M
MODE
COPY M T
MODE
COPY T M

MARK COPY
TEST MRD
FJMP END
COPY M F
NOOP
JUMP COPY

MARK END
DROP
JUMP BOOK

MARK BOT
MODE
LINK 800
COPY M X

MARK HOST
LINK 800
SUBI X 1 X
TEST X = 0
FJMP HOST

GRAB M
MARK COPY_BOT
COPY F M
TEST EOF
FJMP COPY_BOT

MARK STOP
```

### XA (local)
```exa
GRAB 300
MARK BOOK
TEST EOF
TJMP STOP
COPY F X

SWIZ X 0003 M
SWIZ X 0021 X
ADDI X 200 M

JUMP BOOK

MARK STOP
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 1489   | 50   | 37       |
|--------|------|----------|
