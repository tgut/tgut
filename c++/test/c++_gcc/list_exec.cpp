//实现 `list`（节点内存分配、双向迭代器）

#include <iostream>
#include <cassert>
#include <memory>
#include <algorithm>

template <typename T>
class list {
public:
    struct node {
        T data;
        std::shared_ptr<node> prev;
        std::shared_ptr<node> next;
        node(const T& data) : data(data) {}
    };

    class iterator {
    public:
        iterator(std::shared_ptr<node> p) : p(p) {}
        T& operator*() { return p->data; }
        iterator& operator++() { p = p->next; return *this; }
        iterator& operator--() { p = p->prev; return *this; }
        bool operator==(const iterator& rhs) const { return p == rhs.p; }
        bool operator!=(const iterator& rhs) const { return p != rhs.p; }
    private:
        std::shared_ptr<node> p;
    };

    list() : head(std::make_shared<node>(T())), tail(std::make_shared<node>(T())) {
        head->next = tail;
        tail->prev = head;
    }

    void push_back(const T& data) {
        std::shared_ptr<node> n = std::make_shared<node>(data);
        n->prev = tail->prev;
        n->next = tail;
        tail->prev->next = n;
        tail->prev = n;
    }

    void push_front(const T& data) {
        std::shared_ptr<node> n = std::make_shared<node>(data);
        n->prev = head;
        n->next = head->next;
        head->next->prev = n;
        head->next = n;
    }

    iterator begin() { return iterator(head->next); }
    iterator end() { return iterator(tail); }

private:
    std::shared_ptr<node> head;
    std::shared_ptr<node> tail;
};  

int main() {
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_front(0);
    l.push_front(-1);
    l.push_front(-2);

    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}