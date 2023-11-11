/**
 * The purpose of this program was to explore 2 things in C++14:
 * 	1. How to determine if the class has a member with a specific name on compile time
 * 	2. How to use it in template specializations to create separate handlers for classes with or without members with specific names
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

// Helper template to detect the existence of a member variable called errData
template <typename T, typename = std::void_t<>>
struct HasErrData : std::false_type {};
// Specialization for types that have the specified member variable
template <typename T>
struct HasErrData<T, std::void_t<decltype(std::declval<T>().errData)>> : std::true_type {};
// declval makes it possible to refer to a PUBLIC member of a class without instanciating the class
//		in this example: if class T has no member called errData, "std::declval<T>().errData" will fail
//		and "HasErrData" falls to the first option - "HasErrData : std::false_type {}"
// decltype returns a type of a given expression
// void_t maps anything to void
//		since we have a specialization for HasErrData<T, void>, if declval is successful
//		the second option will be selected - "HasErrData<T, ...> : std::true_type {};

template<class T, std::enable_if_t<!HasErrData<T>::value, bool> = true>
void setErrData(T&, const char*) {
	// do nothing if there is no errData
}
template<class T, std::enable_if_t<HasErrData<T>::value, bool> = true>
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
	std::cout << "Msg1 has errData: " << std::boolalpha << HasErrData<Msg1>::value << std::endl;
	std::cout << "Msg2 has errData: " << std::boolalpha << HasErrData<Msg2>::value << std::endl;

	Msg1 m1;
	setMembers(m1, 10, "Hello");
	Msg2 m2;
	setMembers(m2, 10, "Hello");

	return 0;
}
