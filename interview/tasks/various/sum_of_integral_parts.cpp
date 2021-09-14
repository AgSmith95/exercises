#include <iostream>
#include <vector>
#include <list>
#include <numeric>

template <class Container>
int sum_up(const Container& c) {
    int sum = std::accumulate(c.begin(), c.end(), 0,
      [](const typename Container::value_type& a, const typename Container::value_type& b){
          return static_cast<int>(a) + static_cast<int>(b);
    });
    return sum;
}

int main() {
    std::vector<float> vf = {1.1f, 2.2f, 3.3f};
    std::list<double> ld = {1.1, 2.2, 3.3};
    std::cout << sum_up(vf) << '\n';
    std::cout << sum_up(ld) << '\n';
    return 0;
}