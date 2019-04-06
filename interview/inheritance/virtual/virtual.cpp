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
#include "B.hpp"
/**
 * Example of use:
 *           B
 *        /    \
 *      /       \
 * BChild1     BChild2
 *      \     /
 *    BGrandchild
 *
 * BGrandchild will have only 1 copy of B
 */

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
    {   // Example of use
        BGrandchild bg1{5,10};
        std::cout << "bg1.getData()=" << bg1.getData() << '\n';
        /**
         * Despite {5,10} in constructor this happens:
         *
         * B()
         * BChild1(0)
         * BChild2(0)
         * BGrandchild(5,10)
         *
         * Interesting
         */
        std::cout << '\n';
        BGrandchild bg2{15};
        std::cout << "bg2.getData()=" << bg2.getData() << '\n';
    }
    return 0;
}