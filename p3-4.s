/*sum (float *a, float *b, int len)
	 	 rdi		rsi		rdx
*/
.global sum
sum:
	movq	%rdx, %rcx
	call	sumar
	ret
sumar:
	movss	(%rdi), %xmm0
	movss	(%rsi), %xmm1	
	addss	%xmm0, %xmm1
	movss	%xmm1, (%rdi)
	addq	$4, %rdi
	addq	$4, %rsi
	loop sumar
	ret
