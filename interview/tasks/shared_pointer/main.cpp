#include <iostream>
#include <memory>
#include <cassert>

#include "shared_pointer.hpp"

using namespace std;

int main() {
    // test trivial construction
    {
        shared_pointer<int> sp1;
        assert(!sp1);
        assert(sp1.get_count() == 1);
    }
    // test constructor
    {
        shared_pointer<int> sp1(new int(10));
        assert(*sp1 == 10);
        assert(*sp1.get() == 10);
        assert(sp1.get_count() == 1);
    }
    // test copy ctr
    {
        shared_pointer<int> sp1(new int(10));
        auto ptr = sp1.get();
        {
            shared_pointer<int> sp2(sp1);
            assert(ptr == sp2.get());
            assert(*sp2 == 10);
            assert(sp2.get_count() == 2);
        }
        assert(sp1.get_count() == 1);
    }
    // test copy assignment
    {
        shared_pointer<int> sp1(new int(10));
        assert(*sp1 == 10);
        assert(sp1.get_count() == 1);
        shared_pointer<int> sp2(new int(20));
        assert(*sp2 == 20);
        assert(sp2.get_count() == 1);
        sp2 = sp1; // reassign
        assert(*sp2 == 10);
        assert(sp2.get() == sp1.get());
        assert(sp1.get_count() == 2);
        assert(sp2.get_count() == 2);
    }
    // test move ctr
    {
        shared_pointer<int> sp1(new int(10));
        auto ptr = sp1.get();
        shared_pointer<int> sp2(std::move(sp1));
        assert(ptr == sp2.get());
        assert(*sp2 == 10);
        assert(sp2.get() == ptr);
        assert(sp2.get_count() == 1);
        assert(sp1.get() == nullptr);
        assert(sp1.get_count() == 0);
    }
    // test move assignment
    {
        shared_pointer<int> sp1(new int(10));
        assert(*sp1 == 10);
        assert(sp1.get_count() == 1);
        shared_pointer<int> sp2(new int(20));
        assert(*sp2 == 20);
        assert(sp2.get_count() == 1);
        sp2 = std::move(sp1); // reassign
        assert(*sp2 == 10);
        assert(sp2.get_count() == 1);
        assert(!sp1);
    }
    return 0;
}