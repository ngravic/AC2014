.text

.global     setjmp2
.global     longjmp2

# setjmp2 guarda el estado de los registros caller saved en el arreglo que esta de arg
# longjmp2 restaura los registros que se le pasan como param

setjmp2: 
    movq %rsp, (%rdi)
    movq %rbp, 8(%rdi)
    movq %rbx, 16(%rdi)
    movq %r10, 24(%rdi)
    movq %r13, 32(%rdi)
    movq %r14, 40(%rdi)
    movq %r15, 48(%rdi)
    movq (%rsp), %rax
    movq %rax, 56(%rdi)
    xorq %rax, %rax
    ret
		 

longjmp2:    
    cmpq    $0, %rsi
    jne     _next
    incq    %rsi    
_next:
    movq    %rsi, %rax    
    movq    (%rdi), %rsp
    movq    8(%rdi), %rbp
    movq    16(%rdi), %rbx
    movq    24(%rdi), %r10
    movq    32(%rdi), %r13
    movq    40(%rdi), %r14
    movq    48(%rdi), %r15
    movq    56(%rdi), %rcx
    movq    %rcx, (%rsp)
    ret