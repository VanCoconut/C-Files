	.file	"prova.c"
	.text
	.globl	funzione
	.def	funzione;	.scl	2;	.type	32;	.endef
	.seh_proc	funzione
funzione:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$0, -4(%rbp)
	movq	$0, -16(%rbp)
	jmp	.L2
.L4:
	movq	-16(%rbp), %rax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	-16(%rbp), %rdx
	movl	%edx, (%rax)
	movq	-16(%rbp), %rax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L3
	addl	$1, -4(%rbp)
.L3:
	addq	$1, -16(%rbp)
.L2:
	cmpq	$9, -16(%rbp)
	jbe	.L4
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 5.1.0"
