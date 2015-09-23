.global sum_sse

sum_sse:
	movq	%rdx, %rcx
	call	sumar
	ret

sumar:
	movaps (%rdi), %xmm0
	movaps (%rsi), %xmm1
	addps %xmm0, %xmm1
	movaps %xmm1, (%rdi)
	addq $16,%rsi
	addq $16,%rdi
	addq $-4,%rcx
	cmpq $0, %rcx
	jnz sumar
	ret