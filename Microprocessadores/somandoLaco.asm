.global _start
_start:
	MOV r0,#0
	MOV r1,#0
loop:
	ADD r1,r0
	ADD r0,#1
	CMP r0,#10
	BNE loop
end:
	B end
