x���Q0x320: a
x321: b
x322: c
x323: d
x324: x
x325: y
x326: z
x3ef: MOV R0, 0x322
x3f2: SUB R0, 0x323
x3f5: MOV R1, R0
x3f6: ADD R1, 0x321
x3f9: MVI R2, 10
x3fb: MOV R3, R1
x3fc: ADD R3, R2
x3fd: MOV R0, R3
x3fe: STA 0x320
x401: MVI R4, 200
x403: MOV R5, 0x320
x406: CMP R5, R4
x407: JC 0x40b
x40a: JMP 0x41c
x40b: MVI R6, 145
x40d: MOV R7, 0x324
x410: ADD R7, R6
x411: MOV R1, 0x322
x414: SUB R1, R7
x417: MOV R0, R1
x418: STA 0x320
x41b: JMP 0x420
x41c: INR 0x322
x41d: STA 0x320
x420: end
