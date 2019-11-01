#include <iostream>

// syntax: typedef <return_type> (*<name>)(<argument_types>);
typedef int (*func)(int);

int plus5(int i) {
	return i+5;
}

int plus7(int i) {
	return i+7;
}

int main() {
	func f;
	
	f = plus5;
	std::cout << f(5) << '\n';

	f = plus7;
	std::cout << f(3) << '\n';
}
