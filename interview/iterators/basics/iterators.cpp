#include <iostream>
#include <vector>

class Container {
    unsigned size;
    int *data;
public:
    explicit Container(unsigned s): size{s}, data{new int[size]} {
        for (long i = 0; i < size; ++i) {
            data[i] = i;
        }
    }
    ~Container() { delete[] data; }
    int* begin() { return  data; }
    int* end() { return data+size; }
};

int main() {
    {   // the basics 1
        std::vector<int> vi = {1,2,3,4,5};
        std::vector<int>::iterator it = vi.begin(); // Warning: Clang-Tidy: Use auto when declaring iterators
        std::cout << *(it+3) << '\n';   // iterator is, sort of, a pointer
                                        // to an element in a container
    }
    std::cout << '\n';
    {   // the basics 2
        std::vector<int> vi = {1,2,3,4,5};
        // loop through the container
        for (auto it = vi.begin(); it != vi.end(); ++it) {  // Warning: Clang-Tidy: Use range-based for loop instead
            std::cout << *it << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    {   // range-based for std:: containers
        std::vector<int> vi = {1,2,3,4,5};
        for (const auto& it: vi) {  // better to use auto& (reference) to avoid copying
            std::cout << it << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    {   // range based for for user-defined classes
        Container c{5};
        for (const auto& it: c) {   // begin() and end() should be defined
                                    // to be able to use range based for
            std::cout << it << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    return 0;
}