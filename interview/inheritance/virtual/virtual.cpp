#include <iostream>
#include "A.hpp"
/**         |
 *  Example of misuse:
 *  A               A
 *  |               |
 *  AChild1     AChild2
 *      \     /
 *    AGrandchild
 *
 * AGrandchild will have 2 copies of A
 * which leads to ambiguity
**/
#include "B.hpp"    //

int main() {
    {   // Example of misuse
        AGrandchild ag(5,10);
        // ag.getData();    //  error: request for member ‘getData’ is ambiguous
        //                  //  note: candidates are: int A::getData()
        //                  //  note: candidates are: int A::getData()
        //                  //  even the error message is kind of useless
        int x{ag.AChild1::getData()},
            y{ag.AChild2::getData()};
        std::cout   << "ag.AChild1::getData()=" << x << '\n'
                    << "ag.AChild2::getData()=" << y << '\n';
    }
    std::cout << '\n';
    return 0;
}