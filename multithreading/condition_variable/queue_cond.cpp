// Build: 
// g++ -std=c++17 inherit_ec.cpp -o inherit_ec

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>
#include <queue>

using namespace std;

mutex mut;
condition_variable cv;
queue<char> q;

void produce(int i=0) {
	while(true) {
		string s;
		cin >> s;
		for (char c: s) {
			std::lock_guard<mutex> lk(mut);
			// produce
			cout << "p[" << i << "]: " << c << '\n';
			q.push(c);
			// notify
			cv.notify_one();
		}
	}
}

void consume(int i=0) {
	while(true) {
		unique_lock<mutex> lk(mut);
		cv.wait(lk, []{ return !q.empty(); });
		// consume
		cout << "c[" << i << "]: " << q.front() << '\n';
		q.pop();
		// notify
		lk.unlock();
		cv.notify_one();
	}
}

int main() {
	thread producer(produce,0);
	thread consumer(consume,0);

	consumer.join();
	producer.join();
}
