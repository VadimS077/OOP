#include <matrixs/matrixs.hpp>


MatrixS::MatrixS(const SizeType& size){
    if (std::get<0>(size) <= 0 || std::get<1>(size) <= 0) {
        throw std::invalid_argument("invalid size");
    }
    r = std::get<0>(size);
    c = std::get<1>(size);
    size_ = size;
    newmem();
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            matrix[i][j] = 0;
        }
    }

}
void MatrixS::newmem() {
    matrix = new int* [r];
    for (int i = 0; i < r; ++i) {
        matrix[i] = new int[c];
    }
}


MatrixS::MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n) {
    if (m <= 0 || n <= 0) {
        throw std::invalid_argument("invalid size");
    }
    r = m;
    c = n;
    size_ = std::make_tuple(r, c);
    newmem();
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            matrix[i][j] = 0;
        }
    }
    

}

MatrixS::~MatrixS() {
    for (int i = 0; i < r; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

MatrixS::MatrixS(const MatrixS& other):r(other.r),c(other.c)
{
    size_ = std::make_tuple(r, c);
    newmem();
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

MatrixS& MatrixS::operator=(const MatrixS& other)
{
    if (this == &other) {
        return *this;
    }
    if (r != other.r || c != other.c) {
        for (int i = 0; i < r; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
        r = other.r;
        c = other.c;
        size_ = std::make_tuple(r, c);
        newmem();
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }


    
}

int& MatrixS::at(const SizeType& elem) {
    return at(std::get<0>(elem), std::get<1>(elem));
}

 const int& MatrixS::at(const SizeType& elem) const {
    return at(std::get<0>(elem), std::get<1>(elem));
}

 int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) {
     if (i < 0 || i >= nRows() || j < 0 || j >= nCols()) {
         throw std::out_of_range{ "Index out of range" };
     }
     return matrix[i][j];
     
 }
 const int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) const {
     if (i < 0 || i >= nRows() || j < 0 || j >= nCols()) {
         throw std::out_of_range{ "Index out of range" };
     }
     return matrix[i][j];
     
 }
 void MatrixS::resize(const SizeType& new_size) {
     if (std::get<0>(new_size) <= 0 || std::get<1>(new_size) <= 0) {
         throw std::invalid_argument("invalid size");
     }
     int i = std::get<0>(new_size);
     int j= std::get<1>(new_size);

     MatrixS other(i, j);
     for (std::ptrdiff_t a = 0; a < i; ++a) {
         for (std::ptrdiff_t b = 0; b < j; ++b) {
             if (r <= a || c <= b) {
                 other.at(a,b) = 0;
             }
             else {
                 other.at(a, b) = at(a, b);

             }
         }


     }
     *this = other;
 }
 void MatrixS::resize(const std::ptrdiff_t i, const std::ptrdiff_t j) {
     if (i <= 0 || j <= 0) {
         throw std::invalid_argument("invalid size");
     }
     
     MatrixS other(i, j);
     for (std::ptrdiff_t a = 0; a < i; ++a) {
         for (std::ptrdiff_t b = 0; b < j; ++b) {
             if (r <= a || c <= b) {
                 other.at(a,b) = 0;
             }
             else {
                 other.at(a,b) = at(a,b);

             }
         }
         

     }
     *this = other;
 }
 const MatrixS::SizeType& MatrixS::ssize() const noexcept {
     return size_;
 }
 std::ptrdiff_t MatrixS::nRows() const noexcept {
     return r;
 }
 std::ptrdiff_t MatrixS::nCols() const noexcept {
     return c;
 }