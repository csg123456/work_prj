	.file	"memory.c"
	.globl	_a
	.data
	.align 4
_a:
	.ascii "hello world\0"
	.globl	_b
_b:
	.byte	65
	.comm	_f, 4, 2
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "hello world\0"
LC1:
	.ascii "malloc failed!\0"
	.align 4
LC2:
	.ascii "&main = %p, str = %p, &a = %p, &b = %p, &f = %p, d = %p, &str = %p, &c = %p, &d = %p. \12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$64, %esp
	call	___main
	movl	$LC0, 60(%esp)
	movl	$0, 56(%esp)
	movl	$4, (%esp)
	call	_malloc
	movl	%eax, 52(%esp)
	movl	52(%esp), %eax
	testl	%eax, %eax
	jne	L2
	movl	$LC1, (%esp)
	call	_puts
	movl	$-1, %eax
	jmp	L4
L2:
	movl	52(%esp), %eax
	movl	$287454020, (%eax)
	movl	52(%esp), %edx
	movl	60(%esp), %eax
	leal	52(%esp), %ecx
	movl	%ecx, 36(%esp)
	leal	56(%esp), %ecx
	movl	%ecx, 32(%esp)
	leal	60(%esp), %ecx
	movl	%ecx, 28(%esp)
	movl	%edx, 24(%esp)
	movl	$_f, 20(%esp)
	movl	$_b, 16(%esp)
	movl	$_a, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$_main, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$0, %eax
L4:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
