#ifndef LISTS_MERGE_SINGLYLINKEDLIST_HPP
#define LISTS_MERGE_SINGLYLINKEDLIST_HPP

#include <iostream>
#include <vector>

// this is awful, I know
// don't judge

struct ListNode {
    int val;
    ListNode* next;

    explicit ListNode(int v): val{v}, next{nullptr} {}
    ListNode(int v, ListNode* node): val{v}, next{node} {}

    ListNode* rewind() {
        ListNode *curr = this,
                 *Next = this->next;
        while (Next != nullptr) {
            Next = Next->next;
            curr = curr->next;
        }
        return curr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedList(): mHead{nullptr} {}
    explicit SinglyLinkedList(const std::vector<int>& l) {
        unsigned long len = l.size();
        if (len == 0) {
            return;
        }

        mHead = new ListNode(l.front());
        ListNode *curr = mHead;
        for (auto it = l.begin()+1; it != l.end(); ++it) {
            curr->next = new ListNode(*it);
            curr = curr->next;
        }
    }
    SinglyLinkedList(const SinglyLinkedList& other) {
        if (other.mHead == nullptr) {
            mHead = nullptr;
            return;
        }

        mHead = new ListNode(other.mHead->val);
        ListNode *curr_o = other.mHead->next,
                 *curr = mHead;
        while (curr_o != nullptr) {
            curr->next = new ListNode(curr_o->val);
            curr = curr->next;
            curr_o = curr_o->next;
        }
    }
    ~SinglyLinkedList() {
        ListNode *curr = mHead,
                *next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            delete curr;
            curr = next;
        }
    }

    SinglyLinkedList& append(const SinglyLinkedList& other) {
        if (other.mHead == nullptr) {
            return *this;
        }

        ListNode *curr = mHead->rewind(),
                 *curr_o = other.mHead;
        while (curr_o != nullptr) {
            curr->next = new ListNode(curr_o->val);
            curr = curr->next;
            curr_o = curr_o->next;
        }

        return *this;
    }
    SinglyLinkedList& append(const ListNode* other) {
        if (other == nullptr) {
            return *this;
        }

        ListNode *curr = mHead->rewind(),
                 *curr_o = const_cast<ListNode *>(other);
        while (curr_o != nullptr) {
            curr->next = new ListNode(curr_o->val);
            curr = curr->next;
            curr_o = curr_o->next;
        }

        return *this;
    }

    [[nodiscard]] bool isSorted() const {
        if ((mHead == nullptr) || (mHead->next == nullptr)) {
            return true;
        }
        ListNode *curr = mHead,
                 *next = mHead->next;
        while (next != nullptr) {
            if (curr->val > next->val) {
                return false;
            }
            curr = next;
            next = curr->next;
        }
        return true;
    }

    SinglyLinkedList& mergeSorted(const SinglyLinkedList& second) {
        // 0.1) check length not 0
        if (second.mHead == nullptr) {
            return *this;
        }
        // 0.2) check if sorted
        if (!isSorted() || !second.isSorted()) {
            return *this;
        }
        // 0.3) if length of this is 0 - append
        if (mHead == nullptr) {
            return append(second);
        }
        // 1) check if second.mHead->val <= mHead->val
        ListNode *curr_s = second.mHead;
        // if YES - prepend and shift head
        if (curr_s->val <= mHead->val) {
            mHead = new ListNode(curr_s->val, mHead);
            curr_s = curr_s->next;
        }
        // 2) main cycle -
        ListNode *curr = mHead->next;
        ListNode *prev = mHead;
        while ((curr != nullptr) && (curr_s != nullptr)) {
            if (curr_s->val <= curr->val) {
                prev->next = new ListNode(curr_s->val, curr);
                curr = prev->next;
                curr_s = curr_s->next;
            }
            curr = curr->next;
            prev = prev->next;
        }
        // 3) append remaining nodes
        while (curr_s != nullptr) {
            prev->next = new ListNode(curr_s->val);
            prev = prev->next;
            curr_s = curr_s->next;
        }
        return *this;
    }

    void print() {
        ListNode* curr = mHead;
        if (curr == nullptr) {
            return;
        }
        while (curr->next != nullptr) {
            std::cout << curr->val << " -> ";
            curr = curr->next;
        }
        std::cout << curr->val << '\n';
    }
private:
    ListNode* mHead{};
};

#endif //LISTS_MERGE_SINGLYLINKEDLIST_HPP
