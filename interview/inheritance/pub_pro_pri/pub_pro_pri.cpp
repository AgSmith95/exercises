#include <iostream>

class A {
    int a_def;
public:
    int a_pub;
protected:
    int a_pro;
private:
    int a_pri;
};

class B: public A {
    int foo() {
        int sum{};
        sum += a_pub;
        sum += a_pro;
        // sum += a_pri;    //  error: ‘int A::a_pri’ is private within this context
        // sum += a_def;    //  error: ‘int A::a_def’ is private within this context
        return sum;
    }
};
class C: protected A{
    int foo() {
        int sum{};
        sum += a_pub;
        sum += a_pro;
        // sum += a_pri;    //  error: ‘int A::a_pri’ is private within this context
        // sum += a_def;    //  error: ‘int A::a_def’ is private within this context
        return sum;
    }
};
class D: private A{
    int foo() {
        int sum{};
        sum += a_pub;
        sum += a_pro;
        // sum += a_pri;    //  error: ‘int A::a_pri’ is private within this context
        // sum += a_def;    //  error: ‘int A::a_def’ is private within this context
        return sum;
    }
};

class E: A {
    int foo() {
        int sum{};
        sum += a_pub;
        sum += a_pro;
        // sum += a_pri;    //  error: ‘int A::a_pri’ is private within this context
        // sum += a_def;    //  error: ‘int A::a_def’ is private within this context
        return sum;
    }
};

class Bpub: public    B {
    int foo() {
        int sum{};
        sum += a_pub;
        sum += a_pro;
        // sum += a_pri;    //  error: ‘int A::a_pri’ is private within this context
        // sum += a_def;    //  error: ‘int A::a_def’ is private within this context
        return sum;
    }
};
class Bpro: protected B {
    int foo() {
        int sum{};
        sum += a_pub;
        sum += a_pro;
        // sum += a_pri;    //  error: ‘int A::a_pri’ is private within this context
        // sum += a_def;    //  error: ‘int A::a_def’ is private within this context
        return sum;
    }
};
class Bpri: private   B {
    int foo() {
        int sum{};
        sum += a_pub;
        sum += a_pro;
        // sum += a_pri;    //  error: ‘int A::a_pri’ is private within this context
        // sum += a_def;    //  error: ‘int A::a_def’ is private within this context
        return sum;
    }
};

class Cpub: public    C {
    int foo() {
        int sum{};
        sum += a_pub;
        sum += a_pro;
        // sum += a_pri;    //  error: ‘int A::a_pri’ is private within this context
        // sum += a_def;    //  error: ‘int A::a_def’ is private within this context
        return sum;
    }
};
class Cpro: protected C {
    int foo() {
        int sum{};
        sum += a_pub;
        sum += a_pro;
        // sum += a_pri;    //  error: ‘int A::a_pri’ is private within this context
        // sum += a_def;    //  error: ‘int A::a_def’ is private within this context
        return sum;
    }
};
class Cpri: private   C {
    int foo() {
        int sum{};
        sum += a_pub;
        sum += a_pro;
        // sum += a_pri;    //  error: ‘int A::a_pri’ is private within this context
        // sum += a_def;    //  error: ‘int A::a_def’ is private within this context
        return sum;
    }
};

class Dpub: public    D {
    int foo() {
        int sum{};
        // sum += a_pub;    //  error: ‘int A::a_pub’ is inaccessible within this context
        // sum += a_pro;    //  error: ‘int A::a_pro’ is protected within this context
        // sum += a_pri;    //  error: ‘int A::a_pri’ is private within this context
        // sum += a_def;    //  error: ‘int A::a_def’ is private within this context
        return sum;
    }
};
class Dpro: protected D {
    int foo() {
        int sum{};
        // sum += a_pub;    //  error: ‘int A::a_pub’ is inaccessible within this context
        // sum += a_pro;    //  error: ‘int A::a_pro’ is protected within this context
        // sum += a_pri;    //  error: ‘int A::a_pri’ is private within this context
        // sum += a_def;    //  error: ‘int A::a_def’ is private within this context
        return sum;
    }
};
class Dpri: private   D {
    int foo() {
        int sum{};
        // sum += a_pub;    //  error: ‘int A::a_pub’ is inaccessible within this context
        // sum += a_pro;    //  error: ‘int A::a_pro’ is protected within this context
        // sum += a_pri;    //  error: ‘int A::a_pri’ is private within this context
        // sum += a_def;    //  error: ‘int A::a_def’ is private within this context
        return sum;
    }
};

int main() {
    int sum{};

    B b;
    sum += b.a_pub;
    // sum += b.a_pro;  //  error: ‘int A::a_pro’ is protected within this context
    // sum += b.a_pri;  //  error: ‘int A::a_pri’ is private within this context
    // sum += b.a_def;  //  error: ‘int A::a_def’ is private within this context

    C c;
    // sum += c.a_pub;  //  error: ‘int A::a_pub’ is inaccessible within this context
    // sum += c.a_pro;  //  error: ‘int A::a_pro’ is protected within this context
    // sum += c.a_pri;  //  error: ‘int A::a_pro’ is private within this context
    // sum += c.a_def;  //  error: ‘int A::a_def’ is private within this context

    D d;
    // sum += d.a_pub;  //  error: ‘int A::a_pub’ is inaccessible within this context
    // sum += d.a_pro;  //  error: ‘int A::a_pro’ is protected within this context
    // sum += d.a_pri;  //  error: ‘int A::a_pro’ is private within this context
    // sum += d.a_def;  //  error: ‘int A::a_def’ is private within this context

    E e;
    // sum += e.a_pub;  //  error: ‘int A::a_pub’ is inaccessible within this context
    // sum += e.a_pro;  //  error: ‘int A::a_pro’ is protected within this context
    // sum += e.a_pri;  //  error: ‘int A::a_pro’ is private within this context
    // sum += e.a_def;  //  error: ‘int A::a_def’ is private within this context

    return 0;
}