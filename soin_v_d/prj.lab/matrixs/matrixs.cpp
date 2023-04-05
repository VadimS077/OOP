#include <matrixs/matrixs.hpp>


MatrixS::MatrixS(const SizeType& size){
    
}

MatrixS::MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n) {
    

}

MatrixS::~MatrixS() {
    
}

MatrixS::MatrixS(const MatrixS& other)
{

}

MatrixS& MatrixS::operator=(const MatrixS& other)
{
    

    
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
     
 }
 const int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) const {
     if (i < 0 || i >= nRows() || j < 0 || j >= nCols()) {
         throw std::out_of_range{ "Index out of range" };
     }
     
 }
 void MatrixS::resize(const SizeType& new_size) {
     if (std::get<0>(new_size) < 0 || std::get<1>(new_size) < 0) {
         throw std::invalid_argument("invalid size");
     }
     

 }
 void MatrixS::resize(const std::ptrdiff_t i, const std::ptrdiff_t j) {
     if (i < 0 || j < 0) {
         throw std::invalid_argument("invalid size");
     }
     

 }
 const MatrixS::SizeType& MatrixS::ssize() const noexcept {
     return size_;
 }
 std::ptrdiff_t MatrixS::nRows() const noexcept {
     return std::get<0>(size_);
 }
 std::ptrdiff_t MatrixS::nCols() const noexcept {
     return std::get<1>(size_);
 }