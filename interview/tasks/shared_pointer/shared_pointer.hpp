#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

template<class T>
class shared_pointer {
private:
    T *data = nullptr;
    size_t *strong_counter = nullptr;
public:
    shared_pointer(): shared_pointer(nullptr) {}

    explicit shared_pointer(T* data)
    try
        : data(data)
        , strong_counter(new size_t(1))
    {}
    catch (...)
    {
        if (data != nullptr) delete data;
        throw;
    }

    ~shared_pointer()
    {
        if (strong_counter && --*strong_counter == 0) {
            if (data) delete data;
            delete strong_counter;
        }
    }

    // swap
    void swap(shared_pointer& rhs) noexcept
    {
        std::swap(data, rhs.data);
        std::swap(strong_counter, rhs.strong_counter);
    }

    // copy constructor and assignment
    shared_pointer(const shared_pointer& rhs)
        : data(rhs.data)
        , strong_counter(rhs.strong_counter)
    {
        ++*strong_counter;
    }

    shared_pointer& operator=(const shared_pointer& rhs)
    {
        if (this == &rhs) return *this;
        if (strong_counter && --*strong_counter == 0) {
            if (data) delete data;
            delete strong_counter;
        }
        data = rhs.data;
        strong_counter = rhs.strong_counter;
        ++*strong_counter;
        return *this;
    }
    shared_pointer& operator=(T* newData)
    {
        shared_pointer tmp(newData);
        tmp.swap(*this);
        return *this;
    }

    // move constructor
    shared_pointer(shared_pointer&& rhs) noexcept
    {
        rhs.swap(*this);
        rhs.data = nullptr;
    }

    shared_pointer& operator=(shared_pointer&& rhs) noexcept
    {
        if (this == &rhs) return *this;
        if (strong_counter && --*strong_counter == 0) {
            if (data) delete data;
            delete strong_counter;
        }
        data = rhs.data;
        strong_counter = rhs.strong_counter;
        rhs.data = nullptr;
        rhs.strong_counter = nullptr;
        return *this;
    }

    // operators -> and *
    T* operator->() const { return  data; }
    T& operator*()  const { return *data; }

    // access to the pointer's state
    T* get() const { return data; }
    explicit operator bool() const { return data; }
    size_t get_count() const { return strong_counter ? *strong_counter : 0; }
};

#endif
