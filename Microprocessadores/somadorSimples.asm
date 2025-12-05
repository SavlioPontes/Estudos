.global _start @ eh assim que comenta!
_start:
	MOV r0,#5 @ r0 = 5
	MOV r1,#1 @ r1 = 2
	ADD r2,r0,r1 @ r2 = r0 + r1
	
end:
	B end @ trava o codigo em um loop, mas sem encerrar ele
	
