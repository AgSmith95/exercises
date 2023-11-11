/**
 * The purpose of this program was to explore 2 things in C++14:
 * 	1. How to determine if the class has a member with a specific name and type on compile time
 * 	2. How to use it in template specializations to create separate handlers for classes with or without members with specific name+type combo
 *
 * read more here:
 * 	https://stackoverflow.com/a/16000226/5202246
 * 	https://stackoverflow.com/questions/1005476/how-to-detect-whether-there-is-a-specific-member-variable-in-class
 */
#include <iostream>
#include <type_traits>

struct Msg1 {
	int errCode = 0;
	const char* errDescr = "";

	void print() { std::cout << "Msg1:{errCode=" << errCode << ",errDescr='" << errDescr << "'}\n"; }
};
struct Msg2 {
	int errCode = 0;
	const char* errDescr = "";
	const char* errData = "";

	void print() { std::cout << "Msg2:{errCode=" << errCode << ",errDescr='" << errDescr << "',errData='" << errData << "'}\n"; }
};
struct Msg3 {
	int errCode = 0;
	const char* errDescr = "";
	double errData = 1.23;

	void print() { std::cout << "Msg2:{errCode=" << errCode << ",errDescr='" << errDescr << "',errData=" << errData << "}\n"; }
};

// Helper template to detect the existence of a member variable called errData
template <typename T, typename = const char*>
struct HasConstCharErrData : std::false_type {};
// Specialization for types that have the specified member variable
template <typename T>
struct HasConstCharErrData<T, decltype(std::declval<T>().errData)> : std::true_type {};
// declval makes it possible to refer to a member of a class without instanciating it
// decltype returns a type of a given expression

template<class T, std::enable_if_t<!HasConstCharErrData<T>::value, bool> = true>
void setErrData(T&, const char*) {
	// do nothing if there is no errData
}
template<class T, std::enable_if_t<HasConstCharErrData<T>::value, bool> = true>
void setErrData(T& msg, const char* val) {
	msg.errData = val;
}

template<class T>
void setMembers(T& msg, int errCode, const char* errDescr) {
	msg.errCode = errCode;
	msg.errDescr = errDescr;
	setErrData(msg, errDescr);
	msg.print();
}

int main() {
	std::cout << "Msg1 has const char* errData: " << std::boolalpha << HasConstCharErrData<Msg1>::value << std::endl;
	std::cout << "Msg2 has const char* errData: " << std::boolalpha << HasConstCharErrData<Msg2>::value << std::endl;
	std::cout << "Msg3 has const char* errData: " << std::boolalpha << HasConstCharErrData<Msg3>::value << std::endl;

	Msg1 m1;
	setMembers(m1, 10, "Hello");
	Msg2 m2;
	setMembers(m2, 10, "Hello");
	Msg3 m3;
	setMembers(m3, 10, "Hello");

	return 0;
}
