#include <iostream>
#include <string>
#include <sstream>

#include <mutex>
#include <thread>
#include <deque>
#include <functional>
#include <condition_variable>
#include <atomic>

using namespace std;
using lock_t = unique_lock<mutex>;
using task_t = function<void()>;

class notification_queue {
    deque<task_t> _q;
    bool _done{false};
    mutex _mutex;
    condition_variable _ready;

public:
    void done() {
        {
            lock_t lock{_mutex};
            _done = true;
        }
        _ready.notify_all();
    }

    bool pop(task_t& x) {
        lock_t  lock{_mutex};
        while (_q.empty() && !_done) _ready.wait(lock);
        if (_q.empty()) return false;
        x = move(_q.front());
        _q.pop_front();
        return true;
    }

    bool try_pop(task_t& x) {
        lock_t lock{_mutex, try_to_lock};
        if (!lock || _q.empty()) return false;
        x = move(_q.front());
        _q.pop_front();
        return true;
    }

    template<typename F>
    void push(F&& f) {
        {
            lock_t lock{_mutex};
            _q.template emplace_back(forward<F>(f));
        }
        _ready.notify_one();
    }

    template<typename F>
    bool try_push(F&& f) {
        {
            lock_t lock{_mutex, try_to_lock};
            if (!lock) return false;
            _q.template emplace_back(forward<F>(f));
        }
        _ready.notify_one();
        return true;
    }
};

class task_system {
    const unsigned              _count{thread::hardware_concurrency()};
    const unsigned              K{100};
    vector<thread>              _threads;
    vector<notification_queue>  _q{_count};
    atomic<unsigned>            _index{0};

    void run(unsigned i) {
        while (true) {
            task_t f;

            for (unsigned n = 0; n != _count; ++n) {
                if (_q[(i + n) % _count].try_pop(f)) break;
            }
            if (!f && !_q[i].pop(f)) break;

            f();
        }
    }

public:
    task_system() {
        for (unsigned n = 0; n != _count; ++n) {
            _threads.emplace_back([&, n]{ run(n); });
        }
    }

    ~task_system() {
        for (auto& e: _q) e.done();
        for (auto& e: _threads) e.join();
    }

    template<typename F>
    void async_(F&& f) {
        auto i = _index++;

        for (unsigned n = 0; n != _count * K; ++n) {
            if (_q[(i + n) % _count].try_push(forward<F>(f))) return;
        }

        _q[i % _count].push(forward<F>(f));
    }
};

void dummy_work() {
    stringstream ss;
    ss << "dummy_work() on thread_id=";
    ss << this_thread::get_id();
    ss << '\n';
    cout << ss.rdbuf();
}

int main() {
	std::cout << "Input number of dummy tasks to spawn\n";
	std::cout << "\tPress ENTER to quit\n";

    task_system ts;

    string line;
    int n = 0;
    while (getline(cin, line)) {
        if (line.empty()) break;
        try {
            n = abs(stoi(line));
            for (int i = 0; i < n; ++i) {
                ts.async_(dummy_work);
            }
        }
        catch (...) {}
    }

    return 0;
}