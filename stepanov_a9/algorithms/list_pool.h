#ifndef LIST_POOL_H
#define LIST_POOL_H

#include <vector>
#include <cstddef>

template<typename T, typename N = std::size_t>
// Requires T to be semi-regular
// Requires N to be an integral type (unsigned)
class list_pool {
public:
    typedef N list_type;
private:
    struct node_t {
        T value;
        list_type next;
    };

    std::vector<node_t> pool;

    list_type free_list;

    node_t& node(list_type x) {
        return pool[x - 1];
    }
    const node_t& node(list_type x) const {
        return pool[x - 1];
    }

    list_type new_list() {
        pool.push_back(node_t());
        return list_type(pool.size());
    }
public:
    // empty
    list_type empty() const {
        return list_type(0);
    }

    bool is_empty(list_type x) const {
        return x == empty();
    }

    // constructor
    list_pool() {
        free_list = empty();
    }

    // Basic operations:
    // cons, car, cdr, free

    // value. 2 types: return ref and const
    T& value(list_type x) {
        return node(x).value;
    }
    const T& value(list_type x) const {
        return node(x).value;
    }

    // next
    list_type& next(list_type x) {
        return node(x).next;
    }
    const list_type& next(list_type x) const {
        return node(x).next;
    }

    // free
    list_type free(list_type x) {
        list_type cdr = next(x);
        next(x) = free_list;
        free_list = x;
        return cdr;
    }

    // allocate
    list_type allocate(const T& value, list_type tail) {
        list_type list = free_list;
        if (is_empty(free_list)) {
            list = new_list();
        }
        else {
            free_list = next(free_list);
        }
        value(list) = value;
        next(list) = tail;
        return list;
    }
};

template<typename T, typename N>
void free_list(list_pool<T, N>& pool,
               typename list_pool<T, N>::list_type x)
{
    while (!pool.is_empty()) x = pool.free(x);
}

//template<typename T, typename N, typename Cmp>
//void min_element_list(list_pool<T, N>& pool,
//               typename list_pool<T, N>::list_type x,
//               Cmp c)
//{
//
//}

#endif//LIST_POOL_H
