#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <unordered_set>
#include <sstream>

using namespace std;

/**
 * Implement cache with the following interface:
 *
 *   Add|element
 *      Returns true/false if the element was not/was in the cache
 *
 *   Get|element
 *      Returns element if found or "NULL"
 *
 *   Has|element
 *      Returns true/false
 *
 *   Remove|element
 *      Returns true/false if the element was/was not in the cache
 */

class Cache {
public:
    void Add(const string& val) {
        auto ret = data.insert(val);
        if (ret.second) {
            cout << "True\n";
        }
        else {
            cout << "Fase\n";
        }
    }
    void Get(const string& val) {
        auto find = data.find(val);
        if (find != data.end()) {
            cout << val << '\n';
        }
        else {
            cout << "NULL\n";
        }
    }
    void Has(const string& val) {
        auto find = data.find(val);
        if (find != data.end()) {
            cout << "True\n";
        }
        else {
            cout << "False\n";
        }
    }
    void Remove(const string& val) {
        auto ret = data.erase(val);
        if (ret == 1) {
            cout << "True\n";
        }
        else {
            cout << "False\n";
        }
    }

    void parse_command(const string& command) {
        std::stringstream command_stream(command.c_str());
        std::string function;
        getline(command_stream, function, '|');

        if (function == "Add") {
            getline(command_stream, function);
            Add(function);
        }
        else if (function == "Get") {
            getline(command_stream, function);
            Get(function);
        }
        else if (function == "Has") {
            getline(command_stream, function);
            Has(function);
        }
        else if (function == "Remove") {
            getline(command_stream, function);
            Remove(function);
        }
        else if (function == "Reset") {
            cout << data.size() << '\n';
            data.clear();
        }

    }
private:
    unordered_set<string> data;
};

int main() {
    Cache cache;
    string line;
    while (getline(cin, line)) {
        cache.parse_command(line);
    }
    return 0;
}