#ifndef OVERRIDE_FINAL_HPP
#define OVERRIDE_FINAL_HPP

class Parent {
public:
    // enable overriding by making function virtual
    // also adds Virtual Table (VTable) and other interesting effects
    // More about it here: https://shaharmike.com/cpp/vtable-part1/
    virtual int foo(int i) {
        return i + 10;
    }
};

class Child: public Parent {
public:
    // overriding function
    int foo(int i) override {
        return i + 100;
    }
};

class GrChild: public Child {
public:
    // marking function final in order to
    // disallow further overriding
    int foo(int i) final {
        return i + 1000;
    }
};

//class GrGrChild: public GrChild {
//public:
//    // error: virtual function ‘virtual int GrGrChild::foo(int)’ overriding final function
//    int foo(int i) override {
//        return i + 10000;
//    }
//};

#endif