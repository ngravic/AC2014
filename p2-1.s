.data
fmt:	.asciz	"%ld\n"
fmt2:	.asciz	"%p\n"
i:	.quad	0xdeadbeef
.text
.global main
main:
	movq $fmt, %rdi		#Formato	
	movq $1234, %rsi	#Valor a imprimir
	xorq %rax, %rax		#Cant valores pto. flotante
	call printf
	
	#Valor registro rsp
	movq $fmt, %rdi
	movq %rsp, %rsi
	xorq %rax, %rax
	call printf
	
	#Dir. cadena de formato
	movq $fmt, %rdi
	movq $fmt, %rsi
	xorq %rax, %rax
	call printf

	#Dir. cadena formato hex
	movq $fmt2, %rdi
	movq $fmt2, %rsi
	xorq %rax, %rax
	call printf

	#Quad en tope de pila
	movq $fmt, %rdi
	movq (%rsp), %rsi
	xorq %rax, %rax
	call printf

	#Quad en rsp + 8
	movq $fmt, %rdi
	movq 8(%rsp), %rsi
	xorq %rax, %rax
	call printf

	#Valor de i
	movq $fmt, %rdi
	movq i, %rsi
	xorq %rax, %rax
	call printf

	#Direccion de i
	movq $fmt, %rdi
	movq $i, %rsi
	xorq %rax, %rax
	call printf

	ret

#Ej 1)
#	* Valor registro rsp: Linea 8 reemplazar por movq %rsp, %rsi
#	* Direccion cadena de formato: Linea 8 reemp por movq $fmt, %rsi
#	* Direccion cadena formato hex: Linea 2 reemp por fmt: .asciz "%p\n"
#	* El quad en el tope de la pila: Linea 8 reemp por movq (%rsp), %rsi
#	* El quad en rsp + 8: Linea 8 reemp por movq 8(%rsp), %rsi
#	* El valor i: Linea 8 reemp por movq i, %rsi
#	* La direc de i: Linea 8 reemp por movq $i, %rsi


