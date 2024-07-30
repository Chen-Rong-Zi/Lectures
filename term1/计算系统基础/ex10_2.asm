						SR1		DR
x3000 0000:     LHI     __      R3      I_________(0x8000)
x3000 0004:     ADDI    R0(S1)	R2(S2)  I_________(0x0000)
x3000 0008:     AND     R3(S1)  R1(S2)  R4(DR)
x3000 000C:     BEQZ    R4(S1)	I_________(0x0004)
x3000 0010:     ADDI    R2(S1)	R2(DR)	I_________(0x0001)
x3000 0014:     ADD     R1(S1)  R1(S2)  R1(DR)
x3000 0018:     BEQZ    R1(S1)	I_________(0x0004)
x3000 001C:     j       I_________(0x03FFFFE8)
x3000 0020:     TRAP    R0      R0      R0      R0      R0      R0 ;exit!
