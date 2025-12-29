.global _start
_start:
	MOV r0,#5
	BL fatorial @salva esse ponto vai ser o primeiro lr e oq vai puxar no final
	B end

fatorial:
	PUSH {lr} @pega o a ultimo lr q é sempre o do ponto anterior n-1
	 
	CMP r0,#1
	BLE caso_base @se for igual a 1 vai pro caso base
	
	PUSH {r0} @apos ver se é n>1 ele coloca na pilha q vai guardar o lr n-1 e os numeros a serem multiplicados
	SUB r0,#1 @ diminui o contador/ nosso n fatorial
	BL fatorial @salva ESSE PONTO para voltar nas recursoes,ou seja, o lr é a partir desse ponto(so volta pros calculos)
	
	POP {r1} @pega o valor da pilha e multiplica
	MUL r0,r0,r1
	
	POP {lr} @pega o lr alternado com o numero na pilha e volta pra recursao anterior
	BX lr
	
caso_base:
	MOV r0,#1 @bota r0 pra 1(caso base)
	POP {lr} @retorna pra ultima recursao (2 no caso 2-1 = 1)
	BX lr
