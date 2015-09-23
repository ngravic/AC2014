/*
int solve(float a, float b, float c, float d, float e, float f, float *x, float *y)
			xmm0	 xmm1	  xmm2	   xmm3		xmm4	xmm5	   rdi		rsi
	ax + by = e
	cx + dy = f
	Resultado en rdi, rsi
	Devuelve 0 si unica solucion
	-1 en caso contrario
*/
.text
.global solve

solve:
	movss %xmm0, %xmm6	
	mulss %xmm4, %xmm6	
	movss %xmm1, %xmm7	
	mulss %xmm3, %xmm7	
	subss %xmm7, %xmm6			#Determinante 

	movq $0, %rax
	cvtsi2ss %rax, %xmm15
	ucomiss %xmm15, %xmm6		
	#Si determinante = 0, no hay solucion. retorna -1
	je _noResult

	#Calculo X:
	movss %xmm2, %xmm7	
	mulss %xmm4, %xmm7	
	movss %xmm1, %xmm8	
	mulss %xmm5, %xmm8	
	subss %xmm8, %xmm7			#Determinante X

	#Division X con determinante
	movss %xmm7, %xmm10	#xmm10 = c*e - b*f
	divss %xmm6, %xmm10	#xmm10 = c*e - b*f / a*e - b*d
	
	#Calculo Y:
	movss %xmm0, %xmm8	
	mulss %xmm5, %xmm8	
	movss %xmm2, %xmm9	
	mulss %xmm3, %xmm9	
	subss %xmm9, %xmm8			#Determinante Y

	#Division Y con determinante
	movss %xmm8, %xmm11	
	divss %xmm6, %xmm11	

	#Guardar Resultado en lo que apunta rdi, rsi (X, Y)
	movss %xmm10, (%rdi)
 	movss %xmm11, (%rsi)

 	#Calculo correcto. Retorna 0
	movq $0, %rax				
	ret
	

_noResult:
	movq $-1, %rax
	ret 		
