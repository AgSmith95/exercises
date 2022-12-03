#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(): data(), left(nullptr), right(nullptr) {}
    explicit Node(int i): data(i), left(nullptr), right(nullptr) {}
    Node(int i, Node *l, Node *r): data(i), left(l), right(r) {}

    Node(const Node &other) = default;
    Node& operator=(const Node &other) = default;
};

void print_node(std::stringstream& ss, Node *v) {
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

std::string tree_to_string(Node *v) {
    std::stringstream ss;
    ss << '[';
    print_node(ss, v);
    std::string s(ss.str());
    s[s.size() - 1] = ']';
    return s;
}

void free_tree(Node *top) {
    if (top != nullptr) {
        free_tree(top->right);
        free_tree(top->left);

        free(top);
    }
}

std::vector<Node *> generate_trees(int start, int end) {
    std::vector<Node*> trees;
    if (start > end) trees.push_back(nullptr);
    else {
        for (int i = start; i <= end; ++i) {
            std::vector<Node*> left_trees = generate_trees(start, i - 1);
            std::vector<Node*> right_trees = generate_trees(i + 1, end);

            for (Node *left_node: left_trees) {
                for (Node *right_node: right_trees) {
                    Node *top(new Node(i));
                    top->left = left_node;
                    top->right = right_node;
                    trees.push_back(top);
                }
            }
        }
    }
    return trees;
}

std::vector<Node *> generate_trees(int end) {
    return generate_trees(1, end);
}

int main() {
    if (false) {
        Node* n1(new Node(1));
        Node* n2(new Node(2));
        Node* n3(new Node(3));

        n3->left = n1;
        n1->right = n2;

        std::cout << tree_to_string(n3) << "\n";
        free_tree(n3);
    }
    if (true) {
        std::vector<Node *> generated = generate_trees(4);
        unsigned i = 1;
        for (Node *tree : generated) {
            std::cout << std::setw(3) << i << ": " << tree_to_string(tree) << "\n";
            ++i;
        }
        for (Node *tree : generated) {
            free_tree(tree);
        }
    }
}
