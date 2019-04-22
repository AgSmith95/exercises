#include <iostream>
#include <deque>

/**
 * https://en.cppreference.com/w/cpp/container/deque :
 *
 * std::deque (double-ended queue) is an indexed sequence container that allows fast insertion and deletion at both
 * its beginning and its end.
 * In addition, insertion and deletion at either end of a deque never invalidates pointers or references
 * to the rest of the elements.
 *
 * As opposed to std::vector, the elements of a deque are not stored contiguously: typical implementations use a
 * sequence of individually allocated fixed-size arrays, with additional bookkeeping, which means indexed access to
 * deque must perform two pointer dereferences, compared to vector's indexed access which performs only one.
 *
 * The storage of a deque is automatically expanded and contracted as needed. Expansion of a deque is cheaper than
 * the expansion of a std::vector because it does not involve copying of the existing elements to a new memory location.
 * On the other hand, deques typically have large minimal memory cost; a deque holding just one element has to
 * allocate its full internal array (e.g. 8 times the object size on 64-bit libstdc++; 16 times the object size or
 * 4096 bytes, whichever is larger, on 64-bit libc++).
 *
 *
 * The complexity (efficiency) of common operations on deques is as follows:
 *
 * Random access - constant O(1)
 * Insertion or removal of elements at the end or beginning - constant O(1)
 * Insertion or removal of elements - linear O(n)
 *
 * std::deque meets the requirements of Container, AllocatorAwareContainer, SequenceContainer and ReversibleContainer.
 */

template <typename T>
void print_deque(const std::deque<T>& d) {
    std::cout << "deque: [ ";
    for(const auto& el : d) {
        std::cout << el << " ";
    }
    std::cout << "]\n";
}

int main() {
    {   // size overhead example
        std::deque<int> di;
        std::cout   << "di size = "     << di.size()    << '\n'
                    << "sizeof(int) = " << sizeof(int)  << '\n'
                    << "sizeof(di) = "  << sizeof(di)   << '\n' // This will not give the real size of the container
                                                                // with elements and stuff. This is the same as
                    << "sizeof(std::deque<int>) = " << sizeof(std::deque<int>) << '\n'; //  this line
        // For obtaining size you can use something like this:
        //      'sizeof(std::vector<int>) + (sizeof(int) * MyVector.size())'
        // but it looks aesthetically awful :(
    }
    std::cout << "\n";
    {   // push/emplace/pop back/front; complexity: constant
        std::deque<int> di;
        // push
        di.push_back(10);   // adds an element to the end
        di.push_front(20);  // adds an element to the beginning
        print_deque(di);
        // emplace
        di.emplace_back(30);    // constructs an element in-place at the end
        di.emplace_front(40);   // constructs an element in-place at the beginning
        print_deque(di);
        // pop
        di.pop_back();  // removes the last element
        print_deque(di);
        di.pop_front(); // removes the first element
        print_deque(di);
        // back/front
        std::cout   << "di.back  = " << di.back()   << '\n'
                    << "di.front = " << di.front()  << '\n';
    }
    std::cout << "\n";
    {   // random access iterator / at; complexity: constant
        std::deque<int> di = {10,20,30,40,50,60,70,80,90};
        std::cout << "some elements: " << di[3] << ' ' << di[5] << ' ' << di[8] << '\n';
        std::cout << "di.at(4) = " << di.at(4) << '\n';
    }
    std::cout << "\n";
    {   // resize. complexity: Linear in the difference between the current size and count.
        std::deque<int> di = {10,20,30,40,50,60,70,80,90};
        print_deque(di);
        di.resize(5);
        print_deque(di);
        di.resize(9);
        print_deque(di);
    }
    std::cout << "\n";
    {   // constructors (w/o allocators)
        // NOTE: [8] has the top priority when using {}, so be careful with [1], [2] and [3]

        // [1] Default. See above.
        // [2] Constructs the container with count copies of elements with value value. Since C++11:
        //      deque( size_type count,
        //      const T& value,
        //      const Allocator& alloc = Allocator());
        std::deque<int> di2(100,10);
        std::cout << "di2.size = " << di2.size() << '\n';
        // [3] Constructs the container with count default-inserted instances of T. No copies are made. Since C++11:
        //      explicit deque( size_type count, const Allocator& alloc = Allocator() );
        std::deque<int> di3(50);
        std::cout << "di3.size = " << di3.size() << '\n';
        // [4] Constructs the container with the contents of the range [first, last).
        //      template< class InputIt >
        //      deque( InputIt first, InputIt last,
        //      const Allocator& alloc = Allocator() );
        std::deque<int> di4{di3.begin(), di3.begin() + 20};
        std::cout << "di4.size = " << di4.size() << '\n';
        // [5] Copy. Constructs the container with the copy of the contents of other.
        //      If alloc is not provided, allocator is obtained as if by calling
        //      std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.get_allocator())
        // Since C++ 11:
        //      deque( const deque& other, const Allocator& alloc );
        std::deque<int> di5{di4};
        std::cout << "di5.size = " << di5.size() << '\n';
        // [6] Move constructor. Constructs the container with the contents of other using move semantics.
        // Allocator is obtained by move-construction from the allocator belonging to other.
        // deque( deque&& other );
        std::deque<int> di6{std::deque<int>(35) /* using [3] to instantiate temporary object*/ };
        std::cout << "di6.size = " << di6.size() << '\n';
        // [7] Allocator-extended move constructor.
        // TODO: find some usefull example.
        // [8] Constructs the container with the contents of the initializer list init. Since C++11:
        //      deque( std::initializer_list<T> init,
        //      const Allocator& alloc = Allocator() );
        std::deque<int> di7{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        std::cout << "di7.size = " << di7.size() << '\n';
    }
    return 0;
}