#include <cstdio>

class Field{
public:
    Field() {printf("Field()\n");}
    ~Field() {printf("~Field()\n");}
};

class G {
public:
    G() {printf("G()\n");}
    ~G() {printf("~G()\n");}
    virtual void f() {printf("G::f()\n");}
};

class GChild: public G {
    Field a;
public:
    GChild() {printf("GChild()\n");}
    ~GChild() {printf("~GChild()\n");}
    void f() override {printf("GChild::f()\n");}
};
