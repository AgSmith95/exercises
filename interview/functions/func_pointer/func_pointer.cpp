#include <iostream>
#include <functional>

// syntax: typedef <return_type> (*<name>)(<argument_types>);
typedef int (*func)(int);

int plus5(int i) {
	return i+5;
}

int plus7(int i) {
	return i+7;
}

int (*Func (int i, int (*f)(int)))(int) {
    if (i == 5) {
        return plus5;
    }
    else if (i == 7) {
        return plus7;
    }
    else {
        return f;
    }
}

//typedef func(*Foo)(int, func);
using Foo = func(*)(int, func); // same as typedef above

int main() {
	func f;
	
	f = plus5;
	std::cout << f(5) << '\n';

	f = plus7;
	std::cout << f(3) << '\n';

	std::function<int(int)> ff = plus5;
    std::cout << ff(5) << '\n';

    ff = plus7;
    std::cout << ff(3) << '\n';

    std::cout << Func(3, plus7)(3) << '\n';
    std::cout << Func(5, plus7)(5) << '\n';
    std::cout << Func(7, plus5)(3) << '\n';

    std::function<func(int, func)> F = Func;
    std::cout << F(3, plus7)(3) << '\n';
    std::cout << F(5, plus7)(5) << '\n';
    std::cout << F(7, plus5)(3) << '\n';

    std::function<int(*(int, int(*)(int) ))(int)> FF = Func;
    std::cout << FF(3, plus7)(3) << '\n';
    std::cout << FF(5, plus7)(5) << '\n';
    std::cout << FF(7, plus5)(3) << '\n';

    Foo foo = Func;
    std::cout << foo(3, plus7)(3) << '\n';
    std::cout << foo(5, plus7)(5) << '\n';
    std::cout << foo(7, plus5)(3) << '\n';
}
