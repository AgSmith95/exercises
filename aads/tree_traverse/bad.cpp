#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

struct Node {
    int data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int i): data(i), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Tree(): top(nullptr) {}
    Tree(int i): top(new Node{i}) {}

    void insert(int i) {
        if (top == nullptr) top = std::unique_ptr<Node>(new Node{i});
        else insert(i, top);
    }

    std::string to_string() {
        std::stringstream ss;
        ss << '[';
        print_node(ss, top);
        std::string s(ss.str());
        s[s.size() - 1] = ']';
        return s;
    }
private:
    void print_node(std::stringstream& ss, const std::unique_ptr<Node>& v) {
        if (v != nullptr) {
            ss << v->data << ',';
            if (!v->left && !v->right) return;
            else {
                print_node(ss, v->right);
                print_node(ss, v->left);
            }
        }
        else {
            ss << "null,";
        }
    }

    void insert(int i, std::unique_ptr<Node>& v) {
        if (v->data < i) {
            if (v->left == nullptr) v->left = std::unique_ptr<Node>(new Node{i});
            else {
                insert(i, v->left);
            }
        }
        else if (v->data > i) {
            if (v->right == nullptr) v->right = std::unique_ptr<Node>(new Node{i});
            else {
                insert(i, v->right);
            }
        }
    }

    std::unique_ptr<Node> top;
};

std::string generate_trees(int i) {
    std::string s;
    if (i <= 0) {
        s = "[null]";
    }
    else {
        std::vector<int> v(i);
        std::iota(v.begin(), v.end(), 1);
        std::set<std::string> sset;
        do {
            Tree t{};
            for (const auto &item: v) {
                t.insert(item);
            }
            sset.insert(t.to_string());
        } while (std::next_permutation(v.begin(), v.end()));
        
        s = "[";
        for (const auto& item: sset) {
            s.append(item).append(1, ',');
        }
        s[s.size() - 1] = ']';
    }
    return s;
}

int main() {
    std::string s = generate_trees(3);

    std::cout << s << '\n';

    return 0;
}