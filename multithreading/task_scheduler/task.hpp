#ifndef TASK_H
#define TASK_H


using callback = void (*)(void*);
void stub(void*) {};


class Task {
public:
    Task(): m_callback(stub), m_args(nullptr) {}
    Task(callback cb, void *args): m_callback(cb), m_args(args) {}

    Task(const Task &other) = default;
    Task& operator=(const Task &other) = default;

    Task(Task&& other) = default;
    Task& operator=(Task&& other) = default;

    friend bool operator==(const Task &x, const Task &y) {
        return x.m_callback == y.m_callback && x.m_args == y.m_args;
    }
    friend bool operator!=(const Task &x, const Task &y) {
        return !(x == y);
    }

    explicit operator bool() const { return m_callback == nullptr; }

    void operator()() {
        if (m_callback) m_callback(m_args);
    }
private:
    callback m_callback;
    void *m_args;
};

#endif//TASK_H
