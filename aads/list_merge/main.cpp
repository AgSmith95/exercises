#include <vector>
#include "SinglyLinkedList.hpp"

SinglyLinkedList& merge_sorted(const std::vector<SinglyLinkedList*>& vec) {
    if (vec.empty()) {
        throw;
    }
    SinglyLinkedList *res = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        res->mergeSorted(*vec[i]);
    }
    return *res;
}

int main() {
    SinglyLinkedList list1({1,1,2,4,5}),
                     list2({2,3,4,8,9}),
                     list3({2,3,4,5}),
                     list4({1,1,2,4,8,9}),
                     list5({2,4,1});

//    list1.append(list2).print(); // works

//    std::cout << list1.isSorted() << '\n'; // works
//    std::cout << list5.isSorted() << '\n'; // works

//    list1.mergeSorted(list2).print(); // works
//    list3.mergeSorted(list4).print(); // works

    merge_sorted({&list1, &list2, &list3, &list4}).print();
    list1.mergeSorted(list5).print();

    return 0;
}