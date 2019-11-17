	.file	"main.cpp"
	.intel_syntax noprefix
	.text
	.globl	writeStringAsm(char const*, unsigned int)
	.type	writeStringAsm(char const*, unsigned int), @function
writeStringAsm(char const*, unsigned int):
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
	.size	writeStringAsm(char const*, unsigned int), .-writeStringAsm(char const*, unsigned int)
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
	call	constructChild()
	mov	QWORD PTR -8[rbp], rax
	mov	rax, QWORD PTR -8[rbp]
	mov	rdi, rax
	call	operator delete(void*)@PLT
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
	.section	.text._ZN6ParentC2Ev,"axG",@progbits,Parent::Parent(),comdat
	.align 2
	.weak	Parent::Parent()
	.type	Parent::Parent(), @function
Parent::Parent():
.LFB3:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR -8[rbp], rdi
	lea	rdx, vtable for Parent[rip+16]
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR [rax], rdx
	mov	edi, 64
	call	operator new[](unsigned long)@PLT
	mov	rdx, rax
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR 8[rax], rdx
	mov	esi, 9
	lea	rdi, .LC0[rip]
	call	writeStringAsm(char const*, unsigned int)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	Parent::Parent(), .-Parent::Parent()
	.weak	Parent::Parent()
	.set	Parent::Parent(),Parent::Parent()
	.section	.rodata
.LC1:
	.string	"~Parent()\n"
	.section	.text._ZN6ParentD2Ev,"axG",@progbits,Parent::~Parent(),comdat
	.align 2
	.weak	Parent::~Parent()
	.type	Parent::~Parent(), @function
Parent::~Parent():
.LFB6:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR -8[rbp], rdi
	lea	rdx, vtable for Parent[rip+16]
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR [rax], rdx
	mov	rax, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR 8[rax]
	test	rax, rax
	je	.L6
	mov	rax, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR 8[rax]
	mov	rdi, rax
	call	operator delete[](void*)@PLT
.L6:
	mov	esi, 10
	lea	rdi, .LC1[rip]
	call	writeStringAsm(char const*, unsigned int)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	Parent::~Parent(), .-Parent::~Parent()
	.weak	Parent::~Parent()
	.set	Parent::~Parent(),Parent::~Parent()
	.section	.text._ZN6ParentD0Ev,"axG",@progbits,Parent::~Parent(),comdat
	.align 2
	.weak	Parent::~Parent()
	.type	Parent::~Parent(), @function
Parent::~Parent():
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
	call	Parent::~Parent()
	mov	rax, QWORD PTR -8[rbp]
	mov	esi, 16
	mov	rdi, rax
	call	operator delete(void*, unsigned long)@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	Parent::~Parent(), .-Parent::~Parent()
	.section	.rodata
.LC2:
	.string	"Child()\n"
	.section	.text._ZN5ChildC2Ev,"axG",@progbits,Child::Child(),comdat
	.align 2
	.weak	Child::Child()
	.type	Child::Child(), @function
Child::Child():
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
	call	Parent::Parent()
.LEHE0:
	lea	rdx, vtable for Child[rip+16]
	mov	rax, QWORD PTR -24[rbp]
	mov	QWORD PTR [rax], rdx
	mov	edi, 64
.LEHB1:
	call	operator new[](unsigned long)@PLT
.LEHE1:
	mov	rdx, rax
	mov	rax, QWORD PTR -24[rbp]
	mov	QWORD PTR 16[rax], rdx
	mov	esi, 8
	lea	rdi, .LC2[rip]
	call	writeStringAsm(char const*, unsigned int)
	jmp	.L11
.L10:
	mov	rbx, rax
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
	call	Parent::~Parent()
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
	.section	.gcc_except_table._ZN5ChildC2Ev,"aG",@progbits,Child::Child(),comdat
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
	.section	.text._ZN5ChildC2Ev,"axG",@progbits,Child::Child(),comdat
	.size	Child::Child(), .-Child::Child()
	.weak	Child::Child()
	.set	Child::Child(),Child::Child()
	.section	.rodata
.LC3:
	.string	"~Child()\n"
	.section	.text._ZN5ChildD2Ev,"axG",@progbits,Child::~Child(),comdat
	.align 2
	.weak	Child::~Child()
	.type	Child::~Child(), @function
Child::~Child():
.LFB13:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR -8[rbp], rdi
	lea	rdx, vtable for Child[rip+16]
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR [rax], rdx
	mov	rax, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR 16[rax]
	test	rax, rax
	je	.L13
	mov	rax, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR 16[rax]
	mov	rdi, rax
	call	operator delete[](void*)@PLT
.L13:
	mov	esi, 9
	lea	rdi, .LC3[rip]
	call	writeStringAsm(char const*, unsigned int)
	mov	rax, QWORD PTR -8[rbp]
	mov	rdi, rax
	call	Parent::~Parent()
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	Child::~Child(), .-Child::~Child()
	.weak	Child::~Child()
	.set	Child::~Child(),Child::~Child()
	.section	.text._ZN5ChildD0Ev,"axG",@progbits,Child::~Child(),comdat
	.align 2
	.weak	Child::~Child()
	.type	Child::~Child(), @function
Child::~Child():
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
	call	Child::~Child()
	mov	rax, QWORD PTR -8[rbp]
	mov	esi, 24
	mov	rdi, rax
	call	operator delete(void*, unsigned long)@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	Child::~Child(), .-Child::~Child()
	.text
	.globl	constructChild()
	.type	constructChild(), @function
constructChild():
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
	call	operator new(unsigned long)@PLT
.LEHE3:
	mov	rbx, rax
	mov	rdi, rbx
.LEHB4:
	call	Child::Child()
.LEHE4:
	mov	rax, rbx
	jmp	.L19
.L18:
	mov	r12, rax
	mov	esi, 24
	mov	rdi, rbx
	call	operator delete(void*, unsigned long)@PLT
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
	.size	constructChild(), .-constructChild()
	.globl	deleteParent(Parent*)
	.type	deleteParent(Parent*), @function
deleteParent(Parent*):
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
	.size	deleteParent(Parent*), .-deleteParent(Parent*)
	.weak	vtable for Child
	.section	.data.rel.ro.local._ZTV5Child,"awG",@progbits,vtable for Child,comdat
	.align 8
	.type	vtable for Child, @object
	.size	vtable for Child, 32
vtable for Child:
	.quad	0
	.quad	typeinfo for Child
	.quad	Child::~Child()
	.quad	Child::~Child()
	.weak	vtable for Parent
	.section	.data.rel.ro.local._ZTV6Parent,"awG",@progbits,vtable for Parent,comdat
	.align 8
	.type	vtable for Parent, @object
	.size	vtable for Parent, 32
vtable for Parent:
	.quad	0
	.quad	typeinfo for Parent
	.quad	Parent::~Parent()
	.quad	Parent::~Parent()
	.weak	typeinfo for Child
	.section	.data.rel.ro._ZTI5Child,"awG",@progbits,typeinfo for Child,comdat
	.align 8
	.type	typeinfo for Child, @object
	.size	typeinfo for Child, 24
typeinfo for Child:
	.quad	vtable for __cxxabiv1::__si_class_type_info+16
	.quad	typeinfo name for Child
	.quad	typeinfo for Parent
	.weak	typeinfo name for Child
	.section	.rodata._ZTS5Child,"aG",@progbits,typeinfo name for Child,comdat
	.type	typeinfo name for Child, @object
	.size	typeinfo name for Child, 7
typeinfo name for Child:
	.string	"5Child"
	.weak	typeinfo for Parent
	.section	.data.rel.ro._ZTI6Parent,"awG",@progbits,typeinfo for Parent,comdat
	.align 8
	.type	typeinfo for Parent, @object
	.size	typeinfo for Parent, 16
typeinfo for Parent:
	.quad	vtable for __cxxabiv1::__class_type_info+16
	.quad	typeinfo name for Parent
	.weak	typeinfo name for Parent
	.section	.rodata._ZTS6Parent,"aG",@progbits,typeinfo name for Parent,comdat
	.align 8
	.type	typeinfo name for Parent, @object
	.size	typeinfo name for Parent, 8
typeinfo name for Parent:
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
