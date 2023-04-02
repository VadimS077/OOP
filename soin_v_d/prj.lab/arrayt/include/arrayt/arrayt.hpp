// DynArray.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once
#ifndef ARRAYT_T
#define ARRAYT_T

#include <iosfwd>
#include<iostream>



//typedef double T;
template<typename T>
class ArrayT {
public:


	ArrayT()=default;
	ArrayT(const ArrayT& rhs);
	explicit ArrayT(const std::ptrdiff_t cap);
	~ArrayT();
	std::ptrdiff_t ssize() const noexcept;
	void insert(std::ptrdiff_t i,T a);
	void remove(std::ptrdiff_t i);
	void resize(const std::ptrdiff_t newsize);
	T& operator[](const std::ptrdiff_t i);
	const T& operator[](const std::ptrdiff_t i) const;
	std::ostream& writeto(std::ostream& ostrm) const;
	ArrayT& operator=(const ArrayT& rhs);
	
public:
	std::ptrdiff_t size_ = 0;
	T* arr = nullptr;
	std::ptrdiff_t capacity = 0;

};
template<typename T>
std::ostream& operator<<(std::ostream& ostrm, const ArrayT<T>& rhs);



template<typename T>
ArrayT<T>::ArrayT(const std::ptrdiff_t cap) {
    if (cap < 0) {
        throw std::out_of_range("out of range");
    }
    arr = new T[cap];
    capacity = cap;
    size_ = cap;
    for (std::ptrdiff_t i = 0; i < size_; i++) {
        arr[i] = 0;
    }
}
template<typename T>
ArrayT<T>::ArrayT(const ArrayT& other) : arr(new T[other.capacity]), size_(other.size_), capacity(other.capacity) {
    std::copy(other.arr, other.arr + size_, arr);
    arr = new T[other.capacity];
}

template<typename T>
ArrayT<T>::~ArrayT() {
    delete[] arr;
}
template<typename T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT& other) {
    if (this != &other) {
        delete[] arr;
        arr = new T[other.size_];
        size_ = other.size_;
        std::copy(other.arr, other.arr + size_, arr);
    }
    return *this;
}
template<typename T>
std::ptrdiff_t ArrayT<T>::ssize() const noexcept{
    return size_;
}
template<typename T>
T& ArrayT<T>::operator[](const std::ptrdiff_t i) {
    if (i<0 || i>=ssize()) {
        throw std::out_of_range("out of range");
    }
    return arr[i];
}
template<typename T>
const T& ArrayT<T>::operator[](const std::ptrdiff_t i) const
{
    if (i<0 || i>=ssize()) {
        throw std::out_of_range("out of range");
    }
    return arr[i];
}
template<typename T>
void ArrayT<T>::resize(const std::ptrdiff_t newsize) {
    if (newsize <= 0) {
        throw std::invalid_argument("bad size");
    }
    if (newsize <= capacity) {
        size_ = newsize;
    }
    else {

        T* new_arr = new T[newsize];


        std::copy(arr, arr + size_, new_arr);
        delete[] arr;
        arr = new_arr;
        size_ = newsize;
        capacity = newsize;
    }
}
template<typename T>
void ArrayT<T>::insert(std::ptrdiff_t i, T a) {
    if (i<0 || i>ssize()) {
        throw std::out_of_range("out of range");
    }
    resize(ssize() + 1);
    for (std::ptrdiff_t b = ssize() - 1; b > i; b--) {
        arr[b] = arr[b - 1];
    }
    arr[i] = a;
}
template<typename T>
void ArrayT<T>::remove(std::ptrdiff_t i) {
    if (i<0 || i>=ssize()) {
        throw std::out_of_range("out of range");
    }
    for (std::ptrdiff_t b = i + 1; i < ssize(); i++) {
        arr[b - 1] = arr[b];
    }
    resize(ssize() - 1);
}
template<typename T>
std::ostream& ArrayT<T>::writeto(std::ostream& ostrm) const {
    ostrm << "[";
    for (std::ptrdiff_t i = 0; i < ssize() - 1; i++) {
        ostrm << arr[i] << ", ";
    }
    ostrm << arr[ssize() - 1] << "]";
    return ostrm;
}
template<typename T>
std::ostream& operator<<(std::ostream& ostrm, const ArrayT<T>& rhs) {
    return rhs.writeto(ostrm);
}
#endif