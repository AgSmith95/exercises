// g++ -masm=intel main.cpp -o main
// g++ -masm=intel main.cpp -S -o main.s
#define SIZE 16

class Parent;
class Child;

void writeStringAsm(const char* str, const unsigned len) {
//    register const char* arg3 asm("rsi") = str;
//    register const unsigned arg4 asm("rdx") = len;
    asm(
        "mov rax, 1 ;"
        "mov rdi, 1 ;"
        "mov rsi, QWORD PTR [rbp-8] ;"
        "mov edx, DWORD PTR [rbp-12] ;"
        "syscall;"
    );
    /**
     // AT&T syntax:
         "mov $0x1 , %rax ;"
         "mov $0x1 , %rdi ;"
         "mov -0x8(%rbp) , %rsi ;"
         "mov -0xc(%rbp) , %edx ;"
         "syscall ;"
     */
}

Parent* constructChild();
void deleteParent(Parent*);

int main() {
    {
        Parent *p1 = constructChild();
        delete p1; // warning: possible problem detected in invocation of delete operator: [-Wdelete-incomplete]
                   // destructor isn't even called here
    }

    return 0;
}

class Parent {
public:
    Parent(): m_pData{new int[SIZE]} {
        writeStringAsm("Parent()\n", 9);
    }
    virtual ~Parent() {
        delete[] m_pData;
        writeStringAsm("~Parent()\n", 10);
    }
private:
    int *m_pData;
};

class Child: public Parent {
public:
    Child(): m_cData{new int[SIZE]} {
        writeStringAsm("Child()\n", 8);
    }
    ~Child() override {
        delete[] m_cData;
        writeStringAsm("~Child()\n", 9);
    }
private:
    int *m_cData;
};

Parent* constructChild() {
    return new Child();
}

void deleteParent(Parent* p) {
    delete p;
}