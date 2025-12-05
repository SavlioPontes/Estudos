.global _start @ eh assim que comenta!
_start:
	MOV r0,#0 @ contador começando em 0
	
loop:
	ADD r0,r0,#1 @ r0 += 1
	CMP r0,#9 @compara se r0 = 9
	BNE loop @ ele so funciona depois do Compare(CMP) caso NAO sejam iguais, refaz o laço.
end:
	B end @ trava o codigo em um loop, mas sem encerrar ele

