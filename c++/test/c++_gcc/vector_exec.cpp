// day1 - day3
#include <iostream>
using namespace std;
template<typename T>
class MyVector {
private:
    T* _data;
public:
    size_t _size = 0;
    size_t _capacity = 0;

    // Iterator class
    class iterator {
    private:
        T* ptr;
    public:
        iterator(T* p) : ptr(p) {}
        iterator& operator++() { ptr++; return *this; }
        iterator operator++(int) { iterator tmp = *this; ptr++; return tmp; }
        T& operator*() { return *ptr; }
        bool operator!=(const iterator& other) const { return ptr != other.ptr; }
        bool operator==(const iterator& other) const { return ptr == other.ptr; }
    };

    // Iterator methods
    iterator begin() { return iterator(_data); }
    iterator end() { return iterator(_data + _size); }

    void reserve(size_t new_capacity) {
        if (new_capacity <= _capacity) return;
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < _size; ++i) {
            new_data[i] = _data[i];
        }
        // delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

    void push_back(const T& val) {
        if (_size == _capacity)
            reserve(_capacity * 2 + 1);
        _data[_size++] = val;
    }

    MyVector() : _data(nullptr), _size(0), _capacity(0) {}
};

int main() {
    MyVector<string> vec;
    vec.push_back("1");
    vec.push_back("2");
    vec.push_back("3");
    vec.push_back("4");

    cout<<"vector.size :"<<vec._size<<endl;
    cout<<"vector._capacity :"<<vec._capacity<<endl;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}