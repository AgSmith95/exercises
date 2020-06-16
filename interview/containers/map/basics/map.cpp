#include <iostream>
#include <map>
#include <limits>
#include <iterator>

template <class Key, class Value>
void print_map(const std::map<Key,Value>& my_map) {
    std::cout << "\nmap: ";
    for(const auto& item: my_map) {
        std::cout << item.first  << "->";
        std::cout << item.second << ' ';
    }
    std::cout << '\n';
    std::cout << '\n';
}

int main() {
    std::cout << "map basics\n";
    std::map<unsigned short, char> my_map;

    {
        std::cout << "===== 1 =====\n";
        my_map.insert(my_map.begin(), std::make_pair(0, 'B'));
        std::cout << my_map[0] << '\n'; // B
        my_map.insert(my_map.begin(), std::make_pair(0, 'C'));
        std::cout << my_map[0] << '\n'; // B
    }

    {
        std::cout << "===== 2 =====\n";
        my_map[10] = 'C';
        std::cout << my_map.upper_bound(5)->second << '\n'; // C
        std::cout << my_map.upper_bound(5)->first << '\n'; // 10
        std::cout << (my_map.upper_bound(10) == my_map.end()) << '\n'; // 1 (true)
    }

    {
        std::cout << my_map.lower_bound(5)->second << '\n'; // C
        std::cout << my_map.lower_bound(5)->first << '\n'; // 10
        std::cout << my_map.lower_bound(10)->second << '\n'; // C
        std::cout << my_map.lower_bound(10)->first << '\n'; // 10
    }

    {
        std::cout << "===== 3 =====\n";
        my_map[20] = 'C';
        auto lb_beg = my_map.lower_bound(12);
        auto lb_end = my_map.lower_bound(17);
        std::cout << lb_beg->second << '\n'; // C
        std::cout << lb_beg->first << '\n'; // 20
        std::cout << lb_end->second << '\n'; // C
        std::cout << lb_end->first << '\n'; // 20
        --lb_end;
        std::cout << lb_end->second << '\n'; // C
        std::cout << lb_end->first << '\n'; // 10
        --lb_end;
        std::cout << lb_end->second << '\n'; // B
        std::cout << lb_end->first << '\n'; // 0
    }

    {
        std::cout << "===== 4 =====\n";
        auto it = my_map.insert({30, 'D'});
        std::cout << it.first->first << '\n'; // 30
        std::cout << it.first->second << '\n'; // D
        std::cout << it.second << '\n'; // 1
    }

    {
        std::cout << "===== 5 =====\n";
        my_map.insert(my_map.end(), {40, 'E'});
        std::cout << '\n';
        print_map(my_map);
        // map: 0->B 10->C 20->C 30->D 40->E
    }

    {
        std::cout << "===== 6 =====\n";
        my_map.begin()->second = 'Z';
        std::cout << "changed begin value to 'Z'\n";
        print_map(my_map);
        // map: 0->Z 10->C 20->C 30->D 40->E
    }

    {
        std::cout << "===== 7 =====\n";
        auto hint = my_map.insert({100, 'X'}).first;
        auto insert_ret = my_map.insert(hint, {100, 'Y'});
        std::cout << "insert same key result: " <<
                  insert_ret->first << "->" << insert_ret->second << '\n'; // 100->X
    }

    {
        std::cout << "===== 8 =====\n";
        std::cout << "before begin\n";
        auto before_beg = std::prev(my_map.begin());
        std::cout << "before_beg: " << before_beg->first << "->" << before_beg->second << '\n';
        // before_beg: 6->
        // basically, this iterator is INVALID!
    }

    {
        std::cout << "\n\n===== 9 =====\n";
        std::cout << "Erasing elements + iterators\n";
        print_map(my_map);
        auto it1 = std::prev(my_map.end(), 2);
        auto it2 = std::prev(it1, 2);
        std::cout << "it1: " << it1->first << "->" << it1->second << '\n'; // 40->E
        std::cout << "it2: " << it2->first << "->" << it2->second << '\n'; // 20->C
        my_map.erase(std::next(it2));
        print_map(my_map);
        std::cout << "it1: " << it1->first << "->" << it1->second << '\n'; // 40->E
        std::cout << "it2: " << it2->first << "->" << it2->second << '\n'; // 20->C
        std::cout << "it1 == next it2 ? : " << (it1 == std::next(it2)) << '\n'; // 1 - true

        // in this case iterators are not invalidated
        /**
         * map: 0->Z 10->C 20->C 30->D 40->E 100->X
         * it1: 40->E
         * it2: 20->C
         * map: 0->Z 10->C 20->C 40->E 100->X
         * it1: 40->E
         * it2: 20->C
         * it1 == next it2 ? : 1
         **/
    }

    {
        std::cout << "===== 10 =====\n";
        std::cout << "Distance\n";
        std::cout << "dist[begin, begin+3] : "
                  << std::distance(my_map.begin(), ++ ++ ++my_map.begin()) << '\n'; // 3
//    std::cout << "dist[end, end-2] : " << std::distance(my_map.end(), ----my_map.end()) << '\n'; // WOW! deadlock
        std::cout << "dist[end-2, end] : "
                  << std::distance(-- --my_map.end(), my_map.end()) << '\n'; // 2
//    std::cout << "dist[begin-2, begin+3] : " << std::distance(----my_map.begin(), ++++++my_map.begin()) << '\n'; // also deadlock
    }
}
