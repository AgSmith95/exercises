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
/**         |
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
#include "C.hpp"
/**         |
 * Weird totally unusable cases
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
         * This happens because constructors for virtual base classes are always called from the most derived class,
         *  using any arguments it might pass in.
         * In this case "BGrandchild(const int& x, const int& y): BChild1{x}, BChild2{y}" does not provide arguments
         *  for constructor of class B, hence default constructor B::B() is called.
         */
        std::cout << '\n';
        BGrandchild bg2{15};
        std::cout << "bg2.getData()=" << bg2.getData() << '\n';
    }
    std::cout << '\n';
    {
        /**
         * If at least one of the intermediate classes is not "virtual"ly inherited, ambiguity occurs :
         */
        CGrandchild1 cg1{5,10}; //  CGrandchild1 inherits from CChild1 (non-virtual) and CChild2 (virtual)
        // std::cout << "cg1.getData()=" << cg1.getData() << '\n'; //  error: request for member ‘getData’ is ambiguous
        cg1.CChild1::getData();
        std::cout << '\n';
        CGrandchild2 cg2{5,10};
        // std::cout << "cg2.getData()=" << cg2.getData() << '\n'; //  error: request for member ‘getData’ is ambiguous
        cg2.CChild1::getData();
        std::cout << '\n';
        /**
         * Turns out the most derived class isn't required to "virtual"ly inherit intermediate classes :
         */
        CGrandchild3 cg31{5,10};
        std::cout << "cg31.getData()=" << cg31.getData() << '\n';
        std::cout << '\n';
        CGrandchild3 cg32{15};
        std::cout << "cg32.getData()=" << cg32.getData() << '\n';
        std::cout << '\n';
        CGrandchild3 cg41{5,10};
        std::cout << "cg41.getData()=" << cg41.getData() << '\n';
        std::cout << '\n';
        CGrandchild3 cg42{15};
        std::cout << "cg42.getData()=" << cg42.getData() << '\n';
        std::cout << '\n';
    }
    std::cout << '\n';
    return 0;
}