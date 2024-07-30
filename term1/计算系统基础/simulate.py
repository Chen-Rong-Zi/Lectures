R3 = 0x80000000
R2 = 0
R1 = -1
while R2 != 7:
    R4 = R3 & R1
#     print(R4)
    if R4 != 0:
        R2 += 1
    R1 += R2
    if R1 != 0:
        break
print(R2)
