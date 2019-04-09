#include <iostream>

// parametrized type;
// Defining a template
template <typename T>
class Holder {
    T data;
public:
    Holder(): data{} {};
    explicit Holder(const T& t): data{t} {};
    explicit Holder(T&& t): data{t} {};
    void printData() { std::cout << data << '\n'; }
};

// function template
template <typename T>
void printT(const T& t) {
    std::cout << t << '\n';
}

// Template specialization
template <>
class Holder<unsigned char> {
    unsigned char data;
public:
    Holder(): data{} {};
    explicit Holder(const unsigned char& t): data{t} {};
    explicit Holder(unsigned char&& t): data{t} {};
    void printData() { std::cout << "unsigned char: '" << data << "'\n"; }
};
//

// variadic templates
void printAll() {       //  <=  MUST define this function with NO arguments
    std::cout << '\n';  //      in order to not enter infinite recursion
}
template <typename T, typename... Args>
void printAll(const T& t, Args... args) {
    std::cout << t << "; ";
    printAll(args...);
}

int main() {
    {   //  Parametrized type
        Holder<int> hi{20};                 //  template instantiation
        Holder<double> hd{20.20};           //  template instantiation
        Holder<char> hc{'H'};               //  template instantiation
        Holder<const char*> hs{"Hello!"};   //  template instantiation

        hi.printData();
        hd.printData();
        hc.printData();
        hs.printData();
    }
    std::cout << '\n';
    {   //  Template function
        printT(10);
        printT(10.10);
        printT('%');
        printT("10:10");
    }
    std::cout << '\n';
    {   // Template specialization
        unsigned char uc{'U'};

        Holder<unsigned char> uch{uc};
        uch.printData();
    }
    std::cout << '\n';
    {   //  Variadic templates
        printAll("Hello", 71.5, 'F', 3);
    }
    return 0;
}