# 25: KGOG-TV (Satellite Uplink)

<div align="center"><img src="EXAPUNKS - KGOG-TV (502, 79, 6, 2022-12-05-19-36-12).gif" /></div>

## Instructions
> Align the satellite dish with the target satellite by setting the azimuth, elevation, and frequency. Then transmit the data from EMBER-2's video (file 301) after encrypting it using the TV station's encryption key (file 199).
> 
> The azimuth, elevation, and frequency of the target satellite are available in file 300.
> 
> Note that you must align the satellite dish before transmitting any data.
> 
> For more information see "Look to the Stars with Satellite Uplink Systems" in the second issue of the zine.

## Solution

### XA (global)
```asm
; MOVE MOTR
GRAB 300
LINK 800
LINK 799

SEEK 5
COPY F #FREQ

SEEK -5
COPY F X
REPL AZIM

SEEK 1
COPY F X
REPL ELEV

WIPE
HALT

MARK ELEV
LINK 801
TEST #ELEV < X
TJMP ELEV_LESS
SUBI #ELEV X T
COPY -1 X
JUMP LOOP
MARK ELEV_LESS
SUBI X #ELEV T
COPY 1 X
JUMP LOOP

MARK AZIM
LINK 800
TEST #AZIM < X
TJMP AZIM_LESS
SUBI #AZIM X T
COPY -1 X
JUMP LOOP
MARK AZIM_LESS
SUBI X #AZIM T
COPY 1 X

MARK LOOP
FJMP END
SUBI T 1 T
COPY X #MOTR
JUMP LOOP

MARK END
COPY 1 M
```

### XB (global)
```asm
; TRANSMIT
GRAB 301
SEEK 1
LINK 800

; WAIT FOR MOTR
VOID M
VOID M

REPL BROADCAST_KEY

LINK 799

; ENCRYPT
MARK ENCRYPT_LOOP
COPY 1 M
COPY M X

SUBI 9999 X T
TEST F > T
TJMP ENCRYPT_WRAP

SEEK -1
ADDI X F #DATA

MARK ENCRYPT_LOOP_END
TEST EOF
FJMP ENCRYPT_LOOP

COPY -1 M
WIPE
HALT

MARK ENCRYPT_WRAP
SEEK -1
SUBI 9999 X T
SUBI F T T
SUBI T 1 #DATA
JUMP ENCRYPT_LOOP_END


; BROADCAST
MARK BROADCAST_KEY
GRAB 199

MARK BROADCAST_LOOP
TEST M = -1
TJMP BROADCAST_END
COPY F M
TEST EOF
FJMP BROADCAST_LOOP

SEEK -9999
JUMP BROADCAST_LOOP

MARK BROADCAST_END
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 502    | 79   | 6        |
