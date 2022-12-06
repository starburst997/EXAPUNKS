# 27: TEC EXA-Blaster Modem - Dataphone Network

> Using your modem, connect to each dataphone so that EMBER-2 will have a list of valid phone numbers.
> 
> Each dataphone contains a list of the owner's contacts (file 200). The phone number of one of these dataphones is in your host (file 300), while the rest are in the contact list of another dataphone.
> 
> Note that each dataphone (aside from the first) will appear in exactly one other dataphone's contact list, in such a way that you can find them all without getting stuck in a loop.
> 
> For more information see "Hacker Skills: Modem Control at the Direct Level" in the second issue of the zine.

## Solution

<div align="center"><img src="EXAPUNKS - TEC EXA-Blaster™ Modem (1151, 71, 9, 2022-12-05-19-36-59).gif" /></div>

### XB (global)
```exa
GRAB 300
REPL START
JUMP COPY_FILE

MARK START
LINK 800

MAKE

MARK COPY
TEST M = 1
FJMP DIAL
@REP 11
COPY M F
@END
JUMP COPY

MARK DIAL
SEEK -9999
MULI X 11 T
SEEK T
ADDI X 1 X
TEST EOF
TJMP END
COPY -1 #DIAL
@REP 11
COPY F #DIAL
@END

REPL SEARCH_PHONE
SEEK 9999
NOOP
NOOP
TEST MRD
FJMP DIAL
JUMP COPY

MARK END
WIPE
HALT

MARK SEARCH_PHONE
LINK 800
GRAB 200

MARK READ
SEEK 1
MARK COPY_FILE
COPY 1 M
@REP 11
COPY F M
@END

TEST EOF
FJMP READ

COPY 0 M
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 1151   | 71   | 9        |
|--------|------|----------|
