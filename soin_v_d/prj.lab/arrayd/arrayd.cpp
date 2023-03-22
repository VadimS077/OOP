// DynArray.cpp: определяет точку входа для приложения.
//
#include <arrayd/arrayd.hpp>
#include<iostream>

ArrayD::ArrayD(): arr(nullptr), size_(0), capacity(0) {}
ArrayD::ArrayD(const ptrdiff_t cap) : arr(new double[cap]), size_(cap), capacity(cap) {
    if (cap < 0) {
        throw std::out_of_range("out of range");
    }
    for (ptrdiff_t i = 0; i < getsize(); i++) {
        arr[i] = 0;
    }
}
ArrayD::ArrayD(const ArrayD& other) : arr(new double[other.capacity]), size_(other.size_), capacity(other.capacity) {
	std::copy(other.arr, other.arr + size_, arr);
}


ArrayD::~ArrayD() {
	delete[] arr;
}

ArrayD& ArrayD::operator=(const ArrayD& other) {
	if (this != &other) {  
		delete[] arr;  
		arr = new double[other.size_];  
		size_ = other.size_;
		std::copy(other.arr, other.arr + size_, arr);
	}
	return *this;
}
ptrdiff_t ArrayD::getsize() const {
	return size_;
}
double& ArrayD::operator[](const ptrdiff_t i) {
    if (i<0 || i>getsize()) {
        throw std::out_of_range("out of range");
    }
    return arr[i];
}
const double& ArrayD::operator[](const ptrdiff_t i) const
{
    if (i<0 || i>getsize()) {
        throw std::out_of_range("out of range");
    }
    return arr[i];
}
void ArrayD::resize(const ptrdiff_t newsize) {
        if (newsize <= capacity) {
            size_ = newsize;
        }
        else {
        
            double* new_arr = new double[newsize];

            
            std::copy(arr, arr + size_, new_arr);
            delete[] arr;
            arr = new_arr;
            size_ = newsize;
            capacity = newsize;
        }
    }
void ArrayD::insert(ptrdiff_t i,double a) {
    if (i<0 || i>getsize()) {
        throw std::out_of_range("out of range");
    }
    resize(getsize() + 1);
    for (ptrdiff_t b = getsize()-1; b>i; --b) {
        arr[b] = arr[b-1];
    }
    arr[i] = a;
}
void ArrayD::remove(ptrdiff_t i) {
    if (i<0 || i>getsize()) {
        throw std::out_of_range("out of range");
    }
    for (ptrdiff_t b = i + 1; i < getsize(); ++i) {
        arr[b-1] = arr[b];
    }
    resize(getsize() - 1);
}
std::ostream& ArrayD::writeto(std::ostream& ostrm) const {
    ostrm << "[";
    for (ptrdiff_t i = 0; i < getsize()-1; i++) {
        ostrm << arr[i]<<", ";
    }
    ostrm << arr[getsize()-1]<<"]";
    return ostrm;
}
std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs) {
    return rhs.writeto(ostrm);
}