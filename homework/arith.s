	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_arith
	.p2align	4, 0x90
_arith:                                 ## @arith
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	movl	16(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	12(%ebp), %edx
	addl	$20, %ecx
	subl	%edx, %ecx
	addl	%edx, %edx
	subl	%edx, %ecx
	leal	(%ecx,%eax,2), %eax
	popl	%ebp
	retl


.subsections_via_symbols
