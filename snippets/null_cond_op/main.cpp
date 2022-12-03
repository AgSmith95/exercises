#include <iostream>

// generic LHSlt holder
template<typename LHS, typename OP>
struct LHSlt {
    LHS lhs_;
};

// declare myop as an operator-like construct
enum { myop };

// parse 'lhs <myop' into LHSlt
template<typename LHS>
LHSlt<LHS, decltype(myop)> operator<(const LHS& lhs, decltype(myop))
{
    return { lhs };
}

// declare (int <myop> int) -> int
int operator>(LHSlt<int, decltype(myop)> lhsof, int rhs)
{
    int& lhs = lhsof.lhs_;
    // here comes your actual implementation
    return lhs + rhs;
}

// strictly optional
#define plus <myop>

int main() {
    std::cout << (5 plus 2) << '\n';
}
