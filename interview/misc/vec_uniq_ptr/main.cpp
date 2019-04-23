#include <iostream>
#include <memory>
#include <vector>

class A {
    static unsigned count;
    unsigned id;
public:
    A(): id(++count) {};
    ~A() {
        std::cout << "~A[" << id << "]()\n";
    }
    void print() const {
        std::cout << "A[" << id << "]::print()\n";
    }
};
unsigned A::count = 0;

void printUpA(const std::unique_ptr<A>& x) {
    x->print();
}

int main() {
    {
        std::unique_ptr<int[]> upi(new int[10]); // better not to use such things
        upi[9] = 9;
        std::cout << upi[9];
    }
    std::cout << "\n";
    {
        std::vector<std::unique_ptr<int[]>> vupi;   // what have I brought upon this cursed land
        vupi.push_back(std::unique_ptr<int[]>{new int[5]}); // it is hard to comment
        std::cout << vupi[0][3] << '\n';    // well... it compiles... at least
        vupi.push_back(std::unique_ptr<int[]>{new int[4]}); // WOW! It still works!!!
        std::cout << vupi[1][3] << '\n';    // WOW! It still works!!!
    }
    std::cout << "\n";
    {   // check that objects are destructed
        std::unique_ptr<A[]> upA(new A[3]);
    }   // spoiler: they are
    std::cout << "\n";
    {
        std::vector<std::unique_ptr<A>> vupA;   // I simply don't understand where to use it,
                                                // but it is legit compilable
        vupA.push_back(std::unique_ptr<A>(new A()));
        vupA.push_back(std::unique_ptr<A>(new A()));
        vupA.push_back(std::unique_ptr<A>(new A()));
        for (auto& a: vupA) {
            a->print();
        }

        std::cout << "\n";
        printUpA(vupA[1]);
        std::cout << "\n";

        for (auto& a: vupA) {
            a->print();
        }
    }
    std::cout << "\n";
    return 0;
}