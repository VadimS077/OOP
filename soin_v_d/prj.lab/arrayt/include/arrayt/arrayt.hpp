// DynArray.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once
#ifndef ARRAYD_H
#define ARRAYD_H

#include <iosfwd>
#include<iostream>



//typedef double T;
template<typename T>
class ArrayT {
public:


	ArrayT();
	ArrayT(const ArrayT& rhs);
	ArrayT(const ptrdiff_t cap);
	~ArrayT();
	ptrdiff_t getsize() const;
	void insert(ptrdiff_t i,T a);
	void remove(ptrdiff_t i);
	void resize(const ptrdiff_t newsize);
	T& operator[](const ptrdiff_t i);
	const T& operator[](const ptrdiff_t i) const;
	std::ostream& writeto(std::ostream& ostrm) const;
	ArrayT& operator=(const ArrayT& rhs);
	
public:
	ptrdiff_t size_;
	T* arr;
	ptrdiff_t capacity;

};
template<typename T>
std::ostream& operator<<(std::ostream& ostrm, const ArrayT<T>& rhs);


template<typename T>
ArrayT<T>::ArrayT() : arr(nullptr), size_(0), capacity(0) {}
template<typename T>
ArrayT<T>::ArrayT(const ptrdiff_t cap) : size_(cap), capacity(cap) {
    if (cap < 0) {
        throw std::out_of_range("out of range");
    }
    arr = new T[cap];
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
ptrdiff_t ArrayT<T>::getsize() const {
    return size_;
}
template<typename T>
T& ArrayT<T>::operator[](const ptrdiff_t i) {
    if (i<0 || i>getsize()) {
        throw std::out_of_range("out of range");
    }
    return arr[i];
}
template<typename T>
const T& ArrayT<T>::operator[](const ptrdiff_t i) const
{
    if (i<0 || i>getsize()) {
        throw std::out_of_range("out of range");
    }
    return arr[i];
}
template<typename T>
void ArrayT<T>::resize(const ptrdiff_t newsize) {
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
void ArrayT<T>::insert(ptrdiff_t i, T a) {
    if (i<0 || i>getsize()) {
        throw std::out_of_range("out of range");
    }
    resize(getsize() + 1);
    for (ptrdiff_t b = getsize() - 1; b > i; b--) {
        arr[b] = arr[b - 1];
    }
    arr[i] = a;
}
template<typename T>
void ArrayT<T>::remove(ptrdiff_t i) {
    if (i<0 || i>getsize()) {
        throw std::out_of_range("out of range");
    }
    for (ptrdiff_t b = i + 1; i < getsize(); i++) {
        arr[b - 1] = arr[b];
    }
    resize(getsize() - 1);
}
template<typename T>
std::ostream& ArrayT<T>::writeto(std::ostream& ostrm) const {
    ostrm << "[";
    for (ptrdiff_t i = 0; i < getsize() - 1; i++) {
        ostrm << arr[i] << ", ";
    }
    ostrm << arr[getsize() - 1] << "]";
    return ostrm;
}
template<typename T>
std::ostream& operator<<(std::ostream& ostrm, const ArrayT<T>& rhs) {
    return rhs.writeto(ostrm);
}
#endif