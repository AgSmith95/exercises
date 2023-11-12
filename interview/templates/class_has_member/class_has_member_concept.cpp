#include <iostream>
#include <type_traits>

template <class T>
concept HasErrData = requires(T t) { t.errData; };
template <class T>
concept HasIntErrData = requires(T t) {
	{ t.errData } -> std::same_as<int&>;  // & is vital in std::same_as<int&>
	// read more about this madness here:
	//		https://stackoverflow.com/a/63347691/5202246
	//		https://stackoverflow.com/questions/63347537/how-to-use-a-c-requires-clause-in-a-concept-to-require-a-member-variable-to-sa
	// Basically, it happens because decltype(t.errData) != decltype((t.errData)) so that the
	// 		"{ t.errData } -> std::same_as<int&>" becomes "requires std::same_as<decltype((t.errData)), int>"
	// See also https://en.cppreference.com/w/cpp/language/requires -> "Compound requirements"
};
template <class T>
concept HasIntErrData2 = requires(T t) {
	requires std::same_as<decltype((t.errData)), int&>;
};
// Here is a way to avoid that '&'
template <class T>
concept HasConstCharErrData = requires(T t) {
	requires std::same_as<decltype(t.errData), const char*>;
};

struct Msg1 {
	int errCode = 0;
	const char* errDescr = "";
};
struct Msg2 {
	int errCode = 0;
	const char* errDescr = "";
	const char* errData = "";
};
struct Msg3 {
	int errCode = 0;
	const char* errDescr = "";
	double errData = 3.33;
};
struct Msg4 {
	int errCode = 0;
	const char* errDescr = "";
	int errData = 4;
};

int main() {
	static_assert(!HasErrData<Msg1>);
	static_assert(HasErrData<Msg2>);
	static_assert(HasErrData<Msg3>);
	static_assert(HasErrData<Msg4>);

	static_assert(!HasIntErrData<Msg1>);
	static_assert(!HasIntErrData<Msg2>);
	static_assert(!HasIntErrData<Msg3>);
	static_assert(HasIntErrData<Msg4>);

	static_assert(!HasIntErrData2<Msg1>);
	static_assert(!HasIntErrData2<Msg2>);
	static_assert(!HasIntErrData2<Msg3>);
	static_assert(HasIntErrData2<Msg4>);

	static_assert(!HasConstCharErrData<Msg1>);
	static_assert(HasConstCharErrData<Msg2>);
	static_assert(!HasConstCharErrData<Msg3>);
	static_assert(!HasConstCharErrData<Msg4>);

	return 0;
}
