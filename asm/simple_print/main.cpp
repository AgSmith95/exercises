
void writeStringAsm(const char* str, const unsigned len) {
//    register const char* arg3 asm("rsi") = str;
//    register const unsigned arg4 asm("rdx") = len;

//  g++ -masm=intel main.cpp -o main
//  Intel syntax
    asm(
        "mov rax, 1 ;"
        "mov rdi, 1 ;"
        "mov rsi, QWORD PTR [rbp-8] ;"
        "mov edx, DWORD PTR [rbp-12] ;"
        "syscall;"
    );

//  AT&T syntax:
//    asm(
//        "mov $0x1 , %rax ;"
//        "mov $0x1 , %rdi ;"
//        "mov -0x8(%rbp) , %rsi ;"
//        "mov -0xc(%rbp) , %edx ;"
//        "syscall ;"
//    );
}

int main() {
    writeStringAsm("Hello, World!\n", 15);
    return 0;
}