#include <cstdint>
#include <cstdio>
#include <iostream>

// fold expression is a parameter pack for a binary operators
// https://en.cppreference.com/w/cpp/language/fold

// 1) Unary right fold (E op ...) becomes (E1 op (... op (E[N-1] op E[N])))
template<typename... Args>
uint64_t OR_un_r(Args... args)
{
	return (args | ...);
}
// 2) Unary left fold (... op E) becomes (((E[1] op E[2]) op ...) op E[N])
template<typename... Args>
uint64_t AND_un_l(Args... args)
{
	return (... & args);
}
// 3) Binary right fold (E op ... op I) becomes (E[1] op (... op (E[N−1] op (E[N] op I))))
template<typename... Args>
int64_t PLUS_bi_r(Args... args)
{
	return (args + ... + 0);
}
// 4) Binary left fold (I op ... op E) becomes ((((I op E[1]) op E[2]) op ...) op E[N])
template<typename... Args>
int64_t MUL_bi_l(Args... args)
{
	return (1 * ... * args);
}

int main() {
	printf("0x%lx\n", OR_un_r(0xA, 0x2, 0x8, 0x10) ); // 0x1A = [ 0xA | < 0x2 | (0x8 | 0x10) > ]
	printf("0x%lx\n", AND_un_l(0xFF, 0x1F, 0x7A, 0x3B, 0x9F) ); // 0x1A = [ < { ( 0xFF & 0x1F ) & 0x7A } & 0x3B > & 0x9F ]
	printf("0x%lx\n", PLUS_bi_r(0xA, 0x2, 0xE) ); // 0x1A = [ < ( 0xA + 0x2 ) + 0xE > + 0 ]
	printf("0x%lx\n", MUL_bi_l(0x2, 0xD) ); // 0x1A = [ 0x2 * ( 0xD * 1 ) ]
	return 0;
}
