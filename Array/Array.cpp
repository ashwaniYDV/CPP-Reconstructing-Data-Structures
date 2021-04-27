#include<iostream>

template<typename T, size_t S>
class Array {
private:
    // stack allocated array
    T m_Data[S];
public:
    constexpr size_t Size() const {
        return S;
    }

    T* Data() {
        return m_Data;
    }
    const T* Data() const {
        return m_Data;
    }

    T& operator[] (size_t index) {
        return m_Data[index];
    }
    const T& operator[] (size_t index) const {
        return m_Data[index];
    }
};

int main() {
    Array<std::string, 5> data;
    std::cout << data.Size() << std::endl;
    data[0] = "ashwani";
    data[1] = "yadav";
    for (int i = 0; i < data.Size(); i++) {
        std::cout << data[i] << std::endl;
    }
    return 0;
}
