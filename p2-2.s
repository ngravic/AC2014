.data
idx:	.quad 0
bit:	.quad 64
.text
.global countBits

countBits:
	movq	bit, %rcx
	do:
		rolq	%rdi
		adc		$0, idx
		loop	do
	movq 	idx, %rax
	ret