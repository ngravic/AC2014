  .data
  fmt:
       .string "%d"
  entero:
       .long -100
  funcs:
       .quad f1
       .quad f2
       .quad f3
  .text
  f1: movl $0,%esi; movq $fmt, %rdi; xorq %rax,%rax; call printf; jmp fin
  f2: movl $1,%esi; movq $fmt, %rdi; xorq %rax,%rax; call printf; jmp fin
  f3: movl $2,%esi; movq $fmt, %rdi; xorq %rax,%rax; call printf; jmp fin
.globl main
main:
     pushq %rbp; movq %rsp,%rbp
     movq $entero, %rsi
     movq $fmt, %rdi
     xorq %rax,%rax
     call scanf
     xorq %rax,%rax
     ############################
	 movl entero, %eax
	 movq funcs(, %rax, 8), %rdx
	 ############################
     jmp *%rdx
fin:
     movq %rbp,%rsp; popq %rbp; ret
