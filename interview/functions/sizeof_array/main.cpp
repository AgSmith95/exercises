#include <iostream>

//int foo(const float arr[]) { // oopsy, mistake
//    // ‘sizeof’ on array function parameter ‘arr’ will return size of ‘const float*’
//    return sizeof(arr);
//}

template <typename T, size_t N>
constexpr size_t array_size(const T(&)[N]) {
    return N;
}

struct X {
    int a;
    int b;
};

int main() {
    float farr[14];
    int   iarr[17];
    char  carr[23];
    X     xarr[3];

    std::cout << array_size(farr) << '\n';
    std::cout << array_size(iarr) << '\n';
    std::cout << array_size(carr) << '\n';
    std::cout << array_size(xarr) << '\n';

    /*********
     * 14
     * 17
     * 23
     * 3
     *********/

//    float* fp = farr;
//    std::cout << array_size(fp) << '\n';
//      error: no matching function for call to ‘array_size(float*&)’
//      mismatched types ‘const T [N]’ and ‘float*’

    return 0;
}