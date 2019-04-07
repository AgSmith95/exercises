//
// Created by smith on 07/04/19.
//

#ifndef VIRTUAL_INHERITANCE_C_HPP
#define VIRTUAL_INHERITANCE_C_HPP

#include <iostream>

class C {
    int data;
public:
    C(): data{} {
        std::cout << "C()\n";
    }
    explicit C(const int& x): data{x} { //  Clang-Tidy: Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
        std::cout << "C(" << data << ")\n";
    }
    int getData() { return data; }
};

class CChild1: public C {
public:
    CChild1() {
        std::cout << "CChild1()\n";
    }
    explicit CChild1(const int& x): C{x} {  //  Clang-Tidy: Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
        std::cout << "CChild1(" << x << "); getData()=" << getData() << '\n';
    }
};

class CChild2: virtual public C {
public:
    CChild2() {
        std::cout << "CChild2()\n";
    }
    explicit CChild2(const int& x): C{x} {  //  Clang-Tidy: Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
        std::cout << "CChild2(" << x << "); getData()=" << getData() << '\n';
    }
};

class CChild3: public C {
public:
    CChild3() {
        std::cout << "CChild3()\n";
    }
    explicit CChild3(const int& x): C{x} {  //  Clang-Tidy: Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
        std::cout << "CChild3(" << x << "); getData()=" << getData() << '\n';
    }
};

class CChild4: virtual public C {
public:
    CChild4() {
        std::cout << "CChild4()\n";
    }
    explicit CChild4(const int& x): C{x} {  //  Clang-Tidy: Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
        std::cout << "CChild4(" << x << "); getData()=" << getData() << '\n';
    }
};

class CGrandchild1: virtual public CChild1, virtual public CChild2 {
public:
    CGrandchild1() {
        std::cout << "CGrandchild1()\n";
    }
    explicit CGrandchild1(const int& d): C{d} {
        std::cout << "CGrandchild1(" << d << ")\n";
    };
    CGrandchild1(const int& x, const int& y): CChild1{x}, CChild2{y} {
        std::cout << "CGrandchild1(" << x << ',' << y << ")\n";
    };
};

class CGrandchild2: virtual public CChild1, virtual public CChild3 {
public:
    CGrandchild2() {
        std::cout << "CGrandchild2()\n";
    }
    //explicit CGrandchild2(const int& d): C{d} { //  error: type ‘C’ is not a direct or virtual base of ‘CGrandchild2’
    //    std::cout << "CGrandchild2(" << d << ")\n";
    //};
    CGrandchild2(const int& x, const int& y): CChild1{x}, CChild3{y} {
        std::cout << "CGrandchild2(" << x << ',' << y << ")\n";
    };
};

class CGrandchild3: virtual public CChild2, public CChild4 {
public:
    CGrandchild3() {
        std::cout << "CGrandchild3()\n";
    }
    explicit CGrandchild3(const int& d): C{d} {
        std::cout << "CGrandchild3(" << d << ")\n";
    };
    CGrandchild3(const int& x, const int& y): CChild2{x}, CChild4{y} {
        std::cout << "CGrandchild3(" << x << ',' << y << "); getData()=" << getData() << '\n';
    };
};

class CGrandchild4: public CChild2, public CChild4 {
public:
    CGrandchild4() {
        std::cout << "CGrandchild4()\n";
    }
    explicit CGrandchild4(const int& d): C{d} {
        std::cout << "CGrandchild4(" << d << ")\n";
    };
    CGrandchild4(const int& x, const int& y): CChild2{x}, CChild4{y} {
        std::cout << "CGrandchild4(" << x << ',' << y << "); getData()=" << getData() << '\n';
    };
};

#endif //VIRTUAL_INHERITANCE_C_HPP
