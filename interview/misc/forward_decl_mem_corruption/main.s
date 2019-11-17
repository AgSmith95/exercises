	.file	"main.cpp"
	.intel_syntax noprefix
	.text
	.globl	_Z14writeStringAsmPKcj
	.type	_Z14writeStringAsmPKcj, @function
_Z14writeStringAsmPKcj:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR -8[rbp], rdi
	mov	DWORD PTR -12[rbp], esi
	mov	rsi, QWORD PTR -8[rbp]
	mov	edx, DWORD PTR -12[rbp]
#APP
# 17 "main.cpp" 1
	mov rax, 1 ;mov rdi, 1 ;mov rsi, QWORD PTR [rbp-8] ;mov edx, DWORD PTR [rbp-12] ;syscall;
# 0 "" 2
#NO_APP
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z14writeStringAsmPKcj, .-_Z14writeStringAsmPKcj
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	call	_Z14constructChildv
	mov	QWORD PTR -8[rbp], rax
	mov	rax, QWORD PTR -8[rbp]
	mov	rdi, rax
	call	_ZdlPv@PLT
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
.LC0:
	.string	"Parent()\n"
	.section	.text._ZN6ParentC2Ev,"axG",@progbits,_ZN6ParentC5Ev,comdat
	.align 2
	.weak	_ZN6ParentC2Ev
	.type	_ZN6ParentC2Ev, @function
_ZN6ParentC2Ev:
.LFB3:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR -8[rbp], rdi
	lea	rdx, _ZTV6Parent[rip+16]
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR [rax], rdx
	mov	edi, 64
	call	_Znam@PLT
	mov	rdx, rax
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR 8[rax], rdx
	mov	esi, 9
	lea	rdi, .LC0[rip]
	call	_Z14writeStringAsmPKcj
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_ZN6ParentC2Ev, .-_ZN6ParentC2Ev
	.weak	_ZN6ParentC1Ev
	.set	_ZN6ParentC1Ev,_ZN6ParentC2Ev
	.section	.rodata
.LC1:
	.string	"~Parent()\n"
	.section	.text._ZN6ParentD2Ev,"axG",@progbits,_ZN6ParentD5Ev,comdat
	.align 2
	.weak	_ZN6ParentD2Ev
	.type	_ZN6ParentD2Ev, @function
_ZN6ParentD2Ev:
.LFB6:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR -8[rbp], rdi
	lea	rdx, _ZTV6Parent[rip+16]
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR [rax], rdx
	mov	rax, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR 8[rax]
	test	rax, rax
	je	.L6
	mov	rax, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR 8[rax]
	mov	rdi, rax
	call	_ZdaPv@PLT
.L6:
	mov	esi, 10
	lea	rdi, .LC1[rip]
	call	_Z14writeStringAsmPKcj
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	_ZN6ParentD2Ev, .-_ZN6ParentD2Ev
	.weak	_ZN6ParentD1Ev
	.set	_ZN6ParentD1Ev,_ZN6ParentD2Ev
	.section	.text._ZN6ParentD0Ev,"axG",@progbits,_ZN6ParentD5Ev,comdat
	.align 2
	.weak	_ZN6ParentD0Ev
	.type	_ZN6ParentD0Ev, @function
_ZN6ParentD0Ev:
.LFB8:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR -8[rbp], rdi
	mov	rax, QWORD PTR -8[rbp]
	mov	rdi, rax
	call	_ZN6ParentD1Ev
	mov	rax, QWORD PTR -8[rbp]
	mov	esi, 16
	mov	rdi, rax
	call	_ZdlPvm@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	_ZN6ParentD0Ev, .-_ZN6ParentD0Ev
	.section	.rodata
.LC2:
	.string	"Child()\n"
	.section	.text._ZN5ChildC2Ev,"axG",@progbits,_ZN5ChildC5Ev,comdat
	.align 2
	.weak	_ZN5ChildC2Ev
	.type	_ZN5ChildC2Ev, @function
_ZN5ChildC2Ev:
.LFB10:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA10
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 24
	.cfi_offset 3, -24
	mov	QWORD PTR -24[rbp], rdi
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
.LEHB0:
	call	_ZN6ParentC2Ev
.LEHE0:
	lea	rdx, _ZTV5Child[rip+16]
	mov	rax, QWORD PTR -24[rbp]
	mov	QWORD PTR [rax], rdx
	mov	edi, 64
.LEHB1:
	call	_Znam@PLT
.LEHE1:
	mov	rdx, rax
	mov	rax, QWORD PTR -24[rbp]
	mov	QWORD PTR 16[rax], rdx
	mov	esi, 8
	lea	rdi, .LC2[rip]
	call	_Z14writeStringAsmPKcj
	jmp	.L11
.L10:
	mov	rbx, rax
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
	call	_ZN6ParentD2Ev
	mov	rax, rbx
	mov	rdi, rax
.LEHB2:
	call	_Unwind_Resume@PLT
.LEHE2:
.L11:
	add	rsp, 24
	pop	rbx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZN5ChildC2Ev,"aG",@progbits,_ZN5ChildC5Ev,comdat
.LLSDA10:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10-.LLSDACSB10
.LLSDACSB10:
	.uleb128 .LEHB0-.LFB10
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB10
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L10-.LFB10
	.uleb128 0
	.uleb128 .LEHB2-.LFB10
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE10:
	.section	.text._ZN5ChildC2Ev,"axG",@progbits,_ZN5ChildC5Ev,comdat
	.size	_ZN5ChildC2Ev, .-_ZN5ChildC2Ev
	.weak	_ZN5ChildC1Ev
	.set	_ZN5ChildC1Ev,_ZN5ChildC2Ev
	.section	.rodata
.LC3:
	.string	"~Child()\n"
	.section	.text._ZN5ChildD2Ev,"axG",@progbits,_ZN5ChildD5Ev,comdat
	.align 2
	.weak	_ZN5ChildD2Ev
	.type	_ZN5ChildD2Ev, @function
_ZN5ChildD2Ev:
.LFB13:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR -8[rbp], rdi
	lea	rdx, _ZTV5Child[rip+16]
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR [rax], rdx
	mov	rax, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR 16[rax]
	test	rax, rax
	je	.L13
	mov	rax, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR 16[rax]
	mov	rdi, rax
	call	_ZdaPv@PLT
.L13:
	mov	esi, 9
	lea	rdi, .LC3[rip]
	call	_Z14writeStringAsmPKcj
	mov	rax, QWORD PTR -8[rbp]
	mov	rdi, rax
	call	_ZN6ParentD2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	_ZN5ChildD2Ev, .-_ZN5ChildD2Ev
	.weak	_ZN5ChildD1Ev
	.set	_ZN5ChildD1Ev,_ZN5ChildD2Ev
	.section	.text._ZN5ChildD0Ev,"axG",@progbits,_ZN5ChildD5Ev,comdat
	.align 2
	.weak	_ZN5ChildD0Ev
	.type	_ZN5ChildD0Ev, @function
_ZN5ChildD0Ev:
.LFB15:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR -8[rbp], rdi
	mov	rax, QWORD PTR -8[rbp]
	mov	rdi, rax
	call	_ZN5ChildD1Ev
	mov	rax, QWORD PTR -8[rbp]
	mov	esi, 24
	mov	rdi, rax
	call	_ZdlPvm@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	_ZN5ChildD0Ev, .-_ZN5ChildD0Ev
	.text
	.globl	_Z14constructChildv
	.type	_Z14constructChildv, @function
_Z14constructChildv:
.LFB16:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA16
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	r12
	push	rbx
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	mov	edi, 24
.LEHB3:
	call	_Znwm@PLT
.LEHE3:
	mov	rbx, rax
	mov	rdi, rbx
.LEHB4:
	call	_ZN5ChildC1Ev
.LEHE4:
	mov	rax, rbx
	jmp	.L19
.L18:
	mov	r12, rax
	mov	esi, 24
	mov	rdi, rbx
	call	_ZdlPvm@PLT
	mov	rax, r12
	mov	rdi, rax
.LEHB5:
	call	_Unwind_Resume@PLT
.LEHE5:
.L19:
	pop	rbx
	pop	r12
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.section	.gcc_except_table,"a",@progbits
.LLSDA16:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE16-.LLSDACSB16
.LLSDACSB16:
	.uleb128 .LEHB3-.LFB16
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB16
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L18-.LFB16
	.uleb128 0
	.uleb128 .LEHB5-.LFB16
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE16:
	.text
	.size	_Z14constructChildv, .-_Z14constructChildv
	.globl	_Z12deleteParentP6Parent
	.type	_Z12deleteParentP6Parent, @function
_Z12deleteParentP6Parent:
.LFB17:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR -8[rbp], rdi
	cmp	QWORD PTR -8[rbp], 0
	je	.L22
	mov	rax, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR [rax]
	add	rax, 8
	mov	rax, QWORD PTR [rax]
	mov	rdx, QWORD PTR -8[rbp]
	mov	rdi, rdx
	call	rax
.L22:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	_Z12deleteParentP6Parent, .-_Z12deleteParentP6Parent
	.weak	_ZTV5Child
	.section	.data.rel.ro.local._ZTV5Child,"awG",@progbits,_ZTV5Child,comdat
	.align 8
	.type	_ZTV5Child, @object
	.size	_ZTV5Child, 32
_ZTV5Child:
	.quad	0
	.quad	_ZTI5Child
	.quad	_ZN5ChildD1Ev
	.quad	_ZN5ChildD0Ev
	.weak	_ZTV6Parent
	.section	.data.rel.ro.local._ZTV6Parent,"awG",@progbits,_ZTV6Parent,comdat
	.align 8
	.type	_ZTV6Parent, @object
	.size	_ZTV6Parent, 32
_ZTV6Parent:
	.quad	0
	.quad	_ZTI6Parent
	.quad	_ZN6ParentD1Ev
	.quad	_ZN6ParentD0Ev
	.weak	_ZTI5Child
	.section	.data.rel.ro._ZTI5Child,"awG",@progbits,_ZTI5Child,comdat
	.align 8
	.type	_ZTI5Child, @object
	.size	_ZTI5Child, 24
_ZTI5Child:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS5Child
	.quad	_ZTI6Parent
	.weak	_ZTS5Child
	.section	.rodata._ZTS5Child,"aG",@progbits,_ZTS5Child,comdat
	.type	_ZTS5Child, @object
	.size	_ZTS5Child, 7
_ZTS5Child:
	.string	"5Child"
	.weak	_ZTI6Parent
	.section	.data.rel.ro._ZTI6Parent,"awG",@progbits,_ZTI6Parent,comdat
	.align 8
	.type	_ZTI6Parent, @object
	.size	_ZTI6Parent, 16
_ZTI6Parent:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS6Parent
	.weak	_ZTS6Parent
	.section	.rodata._ZTS6Parent,"aG",@progbits,_ZTS6Parent,comdat
	.align 8
	.type	_ZTS6Parent, @object
	.size	_ZTS6Parent, 8
_ZTS6Parent:
	.string	"6Parent"
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.ident	"GCC: (Ubuntu 8.3.0-6ubuntu1) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
