	.file	"main.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "Original string: %s\12\0"
LC2:
	.ascii "Reversed string: %s\12\0"
LC3:
	.ascii "Strings are Equal\0"
LC4:
	.ascii "Strings are not Equal\0"
LC6:
	.ascii "Area=%f\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB13:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$64, %esp
	call	___main
	movl	%esp, %eax
	movl	%eax, %ebx
	flds	LC0
	fstps	-12(%ebp)
	movl	$1634558318, -30(%ebp)
	movw	$110, -26(%ebp)
	leal	-30(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	addl	$1, %eax
	movl	%eax, %edx
	subl	$1, %edx
	movl	%edx, -16(%ebp)
	movl	$16, %edx
	subl	$1, %edx
	addl	%edx, %eax
	movl	$16, %ecx
	movl	$0, %edx
	divl	%ecx
	imull	$16, %eax, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	leal	12(%esp), %eax
	addl	$0, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	leal	-30(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strcpy
	leal	-30(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	leal	-30(%ebp), %eax
	movl	%eax, (%esp)
	call	_stringReverse
	leal	-30(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	-20(%ebp), %eax
	leal	-30(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L2
	movl	$LC3, (%esp)
	call	_puts
	jmp	L3
L2:
	movl	$LC4, (%esp)
	call	_puts
L3:
	flds	-12(%ebp)
	fldl	LC5
	fmulp	%st, %st(1)
	flds	-12(%ebp)
	fmulp	%st, %st(1)
	fstps	-24(%ebp)
	flds	-24(%ebp)
	fstpl	4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$100, %eax
	movl	%ebx, %esp
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.globl	_stringReverse
	.def	_stringReverse;	.scl	2;	.type	32;	.endef
_stringReverse:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	L6
L7:
	addl	$1, -4(%ebp)
L6:
	movl	-4(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L7
	movl	$0, -8(%ebp)
	movl	-4(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -12(%ebp)
	jmp	L8
L9:
	movl	-8(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -13(%ebp)
	movl	-8(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-13(%ebp), %eax
	movb	%al, (%edx)
	addl	$1, -8(%ebp)
	subl	$1, -12(%ebp)
L8:
	movl	-8(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jl	L9
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.section .rdata,"dr"
	.align 4
LC0:
	.long	1077936128
	.align 8
LC5:
	.long	1374389535
	.long	1074339512
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_strcpy;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_strcmp;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
