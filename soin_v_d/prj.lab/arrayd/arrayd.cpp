// DynArray.cpp: определяет точку входа для приложения.
//
#include <arrayd/arrayd.hpp>
#include<iostream>


ArrayD::ArrayD(const std::ptrdiff_t cap): capacity(cap),size_(cap){
    if (cap < 0) {
        throw std::out_of_range("out of range");
    }
    arr = new double[cap];
    size_ = cap;
    capacity = cap;
    for (std::ptrdiff_t i = 0; i < size_; i++) {
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
std::ptrdiff_t ArrayD::ssize() const noexcept{
	return size_;
}
double& ArrayD::operator[](const std::ptrdiff_t i) {
    if (i<0 || i>=ssize()) {
        throw std::out_of_range("out of range");
    }
    return arr[i];
}
const double& ArrayD::operator[](const std::ptrdiff_t i) const
{
    if (i<0 || i>=ssize()) {
        throw std::out_of_range("out of range");
    }
    return arr[i];
}
void ArrayD::resize(const std::ptrdiff_t newsize) {
    if (newsize <= 0) {
        throw std::invalid_argument("bad size");
    }
        if (newsize <= capacity) {
            size_ = newsize;
        }
        else {
        
            double* new_arr = new double[newsize];
            for (std::ptrdiff_t i = 0; i < newsize; i++) {
                new_arr[i] = 0;
            }

            
            std::copy(arr, arr + size_, new_arr);
            delete[] arr;
            arr = new_arr;
            size_ = newsize;
            capacity = newsize;
        }
    }
void ArrayD::insert(std::ptrdiff_t i,double a) {
    if (i<0 || i>ssize()) {
        throw std::out_of_range("out of range");
    }
    resize(ssize() + 1);
    for (std::ptrdiff_t b = ssize()-1; b>i; --b) {
        arr[b] = arr[b-1];
    }
    arr[i] = a;
}
void ArrayD::remove(std::ptrdiff_t i) {
    if (i<0 || i>ssize()) {
        throw std::out_of_range("out of range");
    }
    for (std::ptrdiff_t b = i + 1; i < ssize(); ++i) {
        arr[b-1] = arr[b];
    }
    resize(ssize() - 1);
}
std::ostream& ArrayD::writeto(std::ostream& ostrm) const {
    ostrm << "[";
    for (std::ptrdiff_t i = 0; i < ssize()-1; i++) {
        ostrm << arr[i]<<", ";
    }
    ostrm << arr[ssize()-1]<<"]";
    return ostrm;
}
std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs) {
    return rhs.writeto(ostrm);
}