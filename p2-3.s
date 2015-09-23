.text
.global findChar
.global strCmp
.global fuerzabruta

/*		Busca caracter dentro de cadena apuntada en rdi		*/

findChar:
	movq	%rdx, %rcx
	movq	%rsi, %rax
	repne	scasb
	jne		retFail
	movq	$1, %rax
	ret

/*		Compara las cadenas apuntadas en rdi y rsi con longitud en rcx		*/

strCmp:
	movq	%rdx, %rcx				
	repe	cmpsb
	jne		retFail
	movq	$1, %rax
	ret

/*		Funcion auxiliar que devuelve 0 en caso de no encontrar		*/

retFail:
	movq	$0, %rax
	ret	

/* 
int fuerzabruta(char *S, char *s, int lS, int ls) {
	int i, j;
	for(i=0; i<lS-ls+1; i++) {
		if(S[i] == s[0]) {
			for(j = 0; j < ls && S[i+j] == s[j]; j++) 
				if(j == ls) return i;
		}
	}
	return -1;
}	
*/

fuerzabruta:
	movq	%rdi, %r8
	movq	%rsi, %r9
	movq	%rdx, %r10
	movq	%rcx, %r11
    lodsb    					
    subq	%rcx, %rdx
    incq	%rdx
    movq	%rdx, %rcx
    
lookingfor:
    repne	scasb
    jne		fbretFail    
    movq	%rcx, %r12		
    movq	%rdi, %r13
    movq	%rsi, %rdx    
    movq	%r11, %rcx
    decq	%rcx	
    repe	cmpsb
    je		retSuccess         			
    movq	%r12,%rcx
    movq	%r13,%rdi
    movq	%rdx,%rsi
    jmp		lookingfor
        
retSuccess:
	movq	%r12, %rax
    ret

fbretFail:
	movq	%r12, %rax
    ret