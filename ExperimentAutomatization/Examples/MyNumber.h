#pragma once

#include <iostream>

template <class T> class MyNumber {
public:
    MyNumber(); // Default constructor
    MyNumber(const T &new_value); // Constructor from T
    MyNumber(const MyNumber<T>& new_value); // Copy constructor
    // MyNumber(MyNumber < T > &&new_value) noexcept; // Move constructor
    ~MyNumber();

    T getValue() const;
    void setValue(const T& new_value);

    MyNumber<T>& operator= (const MyNumber<T>& rhs); // Copy assignment
    //MyNumber < T > &operator = (MyNumber < T > &&rhs) noexcept; // Move assignment

    MyNumber<T> operator+ (const MyNumber < T > &rhs);

    template < class V >
    friend MyNumber < V > operator - (const MyNumber < V > &lhs, const MyNumber < V > &rhs);

    template < class V >
    friend std::ostream &operator << (std::ostream &os, const MyNumber < V > &rhs);

protected:
    T value;
};

template < class T >
MyNumber<T>::MyNumber(): value(0) {
    std::cerr << "Default constructor\n";
}

template < class T >
MyNumber<T>::MyNumber(const T& new_value)) {
    value = new_value;
    std::cerr << "Constructor from T\n";
}

template < class T >
MyNumber<T>::MyNumber(const MyNumber<T>& another_my_number): value(another_my_number.value) {
    std::cerr << "Copy constructor\n";
}

template < class T >
MyNumber < T > ::MyNumber(MyNumber < T > &&new_value) noexcept : value(new_value.value) {
    std::cerr << "Move constructor\n";
}

template < class T >
MyNumber < T > ::~MyNumber() {

}

template < class T >
T MyNumber < T > ::getValue() const {
    return value;
}

template < class T >
void MyNumber < T > ::setValue(const T &new_value) {
    value = new_value;
}

template < class T >
MyNumber < T >& MyNumber < T > ::operator = (const MyNumber < T > &rhs) {
    std::cerr << "Copy assignment" << std::endl;

    if (this == &rhs) {
        return *this;
    }

    value = rhs.value;

    return *this;�
}

template < class T >
MyNumber < T >& MyNumber < T > ::operator = (MyNumber < T > &&rhs) noexcept {
    std::cerr << "Move assignment" << std::endl;

    if (this == &rhs) {
        return *this;
    }

    value = rhs.value;

    return *this;
}

template < class T >
MyNumber < T > MyNumber < T > ::operator + (const MyNumber < T > &rhs) {
    return MyNumber < T >(this->value + rhs.value);
}

template < class T >
MyNumber < T > operator - (const MyNumber < T > &lhs, const MyNumber < T > &rhs) {
    return MyNumber < T >(lhs.value - rhs.value);
}

template < class T >
std::ostream &operator << (std::ostream &os, const MyNumber < T > &rhs) {
    os << rhs.value;

    return os;
}
