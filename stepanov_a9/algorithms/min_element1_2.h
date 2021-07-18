#ifndef MIN_ELEMENT_1_2_H
#define MIN_ELEMENT_1_2_H

#include "list_pool.h"
#include "binary_counter.h"

template <typename Compare>
class compare_dereference {
private:
    Compare cmp;
public:
    compare_dereference(const Compare& cmp): cmp(cmp) {}

    template<typename I> // I is forward iterator
    bool operator()(I x, I y) {
        return cmp(*x, *y);
    }
};

template<typename I, typename N>
using pair_list_type = std::pair<I, list_type_t<I, N>>;

template<typename I, typename N>
pair_list_type<I, N> combine(const pair_list_type<I, N>& x,
                             const pair_list_type<I, N>& y,
                             list_pool<I, N>& pool) {
    free_list(pool, y.second);
    return std::make_pair(x.first, pool.allocate(y.first, x.second));
}

template<typename I, typename N, typename Compare>
class op_min1_2 {
private:
    Compare cmp;
    list_pool<I, N> *pool;
public:
    typedef pair_list_type<I, N> argument_type;
    op_min1_2(Compare cmp, list_pool<I, N>& pool): cmp(cmp), pool(&pool) {}

    argument_type operator()(const argument_type& x, const argument_type& y) {
        return cmp(y.first, x.first) ? combine(y, x, *pool) : combine(x, y, *pool);
    }
};

template <typename I, typename Compare>
std::pair<I, I> min_element1_2(I first, I last, Compare cmp) {
    typedef compare_dereference<Compare> compare_dereference_type;
    typedef op_min1_2<I, std::size_t, compare_dereference_type> counter_operation_type;
    typedef binary_counter<counter_operation_type> counter_type;
    typedef list_type_t<I, std::size_t> list_type;

    list_pool<I, std::size_t> pool;
    compare_dereference_type cmp_deref(cmp);
    counter_operation_type op(cmp_deref, pool);
    counter_type counter(op, std::make_pair(last, pool.end()));

    while (first != last) counter.add(std::make_pair(first++, pool.end()));
    std::pair<I, list_type> min1 = counter.reduce();
    I m2 = pool.is_end(min1.second) ? last : pool.value(min_element_list(pool, min1.second, cmp_deref));
    return std::make_pair(min1.first, m2);
}

#endif
