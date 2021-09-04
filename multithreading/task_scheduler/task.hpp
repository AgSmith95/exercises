#ifndef TASK_H
#define TASK_H


typedef void (*callback)(void*);
void stub(void*) {};


class Task {
public:
    Task(): m_callback(stub), m_args(nullptr) {}
    Task(callback cb, void *args): m_callback(cb), m_args(args) {}

    Task(Task&& other) = default;
    Task& operator=(Task&& other) = default;

    explicit operator bool() const { return m_callback == nullptr; }

    void operator()() {
        if (m_callback) m_callback(m_args);
    }
private:
    callback m_callback;
    void *m_args;
};

#endif//TASK_H
