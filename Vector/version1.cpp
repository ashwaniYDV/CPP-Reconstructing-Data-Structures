#include<iostream>
#include <assert.h>
using namespace std;

template<typename T>
class Vector {
private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
public:
    Vector() {
        // allocate 2 elements initially
        ReAlloc(2);
    }

    Vector(size_t initSize) {
        m_Size = initSize;
        m_Data =  new T[m_Size];
        ReAlloc(m_Size);
    }

    ~Vector() {
        Clear();
    }

    void Clear() {
        delete[] m_Data;
        m_Size = 0;
    }

    void PushBack(const T& value) {
        if (m_Size >= m_Capacity) {
            // growing by 1.5 times
            ReAlloc(m_Capacity + m_Capacity / 2 + 1);
        }
        m_Data[m_Size++] = value;
    }

    void PopBack() {
        assert(m_Size > 0);
        m_Size--;
        m_Data[m_Size].~T();
    }

    constexpr size_t Size() const {
        return m_Size;
    }

    T* Data() {
        return m_Data;
    }
    const T* Data() const {
        return m_Data;
    }

    T& operator[] (size_t index) {
        assert(index < m_Size);
        return m_Data[index];
    }
    const T& operator[] (size_t index) const {
        assert(index < m_Size);
        return m_Data[index];
    }

private:
    void ReAlloc(size_t newCapacity) {
        // 1. allocate a new block of memory
        // 2. copy/move old elements into new block
        // 3. delete old block of memory

        T* newBlock =  new T[newCapacity];

        // if realloc is downsizing
        if (newCapacity < m_Size) {
            m_Size = newCapacity;
        }

        for (size_t i = 0; i < m_Size; i++) {
            newBlock[i] = m_Data[i];
        }

        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
};

struct line {
    int x, y;
    line() {
        x = 0, y = 0;
    }
    line(int _x, int _y) {
        x = _x, y = _y;
    }
};

int main() {
    Vector<std::string> a;
    a.PushBack("ashwani");
    a.PushBack("yadav");
    for (int i = 0; i < a.Size(); i++) {
        cout << a[i] << endl;
    }

    Vector<int> b(3);
    b[0] = 2;
    b[1] = 4;

    for (int i = 0; i < b.Size(); i++) {
        cout << b[i] << endl;
    }

    Vector<line> c;
    line l1 = {2, 3};
    c.PushBack(l1);
    c.PushBack(line(4, 5));
    c.PushBack({5, 6});
    c.PopBack();

    for (int i = 0; i < c.Size(); i++) {
        cout << c[i].x << " " << c[i].y << endl;
    }
    return 0;
}
