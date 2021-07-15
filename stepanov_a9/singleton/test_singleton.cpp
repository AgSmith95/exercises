#include <singleton.h>

#include <cassert>

#include <cstdio>

int main() {
    {
        singleton<int> si;
    }
    {
        singleton<int> si(10);
        assert(si.value == 10);
    }
    {
        singleton<int> si(10);
        assert((int)si == 10);
    }
    {
        singleton<int> si1(10);
        assert(si1.value == 10);
        singleton<int> si2(si1);
        assert(si2.value == 10);
    }
    {
        singleton<int> si1(10);
        singleton<int> si2;
        si2 = si1;
        assert(si2.value == 10);
    }
    {
        singleton<int> si1(10);
        singleton<int> si2(20);
        assert(si1 == si1);
        assert(si1 != si2);
        assert(si1 < si2);
        assert(si2 > si1);
        assert(si1 <= si2);
        assert(si2 >= si1);
    }

    return 0;
}