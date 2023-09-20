//Author: Jan Jasa
//Assignment Title: Matrix Arithmetic with objects
//Assignment Description: Add matrix functions and class
//Due Date: 11/18/22
//Date Created: 11/16/22
//Date Last Modified: 11/18/22

#include "matrix.h"

matrix_t::matrix_t(){

}
/*
* description: construct a default matrix
* return: matrix
* precondition: N/A
* postcondition: makes a matrix
*/

matrix_t::matrix_t(int row, int col) {
    this->row = row;
    this->col = col;
}
/*
* description: construct a matrix
* return: matrix
* precondition: two ints, row and col
* postcondition: makes a row x col matrix
*/

void matrix_t::setRow(int row){
    this->row = row;
}
/*
* description: set the value of row
* return: N/A
* precondition: value of row is valid
* postcondition: sets row to input
*/

void matrix_t::setCol(int col){
    this->col = col;
}
/*
* description: set the value of col
* return: N/A
* precondition: value of col is valid
* postcondition: sets col to input
*/

void matrix_t::setValue(int row, int col, double value){
    data[row][col] = value;
}
/*
* description: set the value of a spot
* return: N/A
* precondition: row col and value are valid
* postcondition: sets data[row][col] to value
*/

int matrix_t::getRow() const{
    return row;
}
/*
* description: returns the value of row
* return: integer
* precondition: matrix is valid
* postcondition: returns row
*/

int matrix_t::getCol() const{
    return col;
}
/*
* description: returns the value of col
* return: integer
* precondition: matrix is valid
* postcondition: returns col
*/

double matrix_t::getValue(int row, int col) const{
    return data[row][col];
}
/*
* description: returns the value of a spot
* return: double
* precondition: matrix is valid
* postcondition: returns value of data[r][c]
*/

void matrix_t::display(ostream& out) const {
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            out << data[i][j];
        }
        out << endl;
    }
}
/*
* description: returns the value of each data
* return: ostream
* precondition: matrix is valid
* postcondition: returns matrix
*/

matrix_t matrix_t::add(const matrix_t& other) const{
    matrix_t junk(row,col);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            junk[i][j]=data[i][j]+other.getValue(i,j);
        }
    }
    return junk;
}
/*
* description: add two matrixes
* return: matrix
* precondition: matrix is valid
* postcondition: returns both matrixes added
*/

matrix_t matrix_t::subtract(const matrix_t& other) const{
    matrix_t junk(row,col);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            junk[i][j]=data[i][j]-other.getValue(i,j);
        }
    }
    return junk;
}
/*
* description: subtract two matrixes
* return: matrix
* precondition: matrix is valid
* postcondition: returns both matrixes subtracted
*/

matrix_t matrix_t::multiply(const matrix_t& other) const{
    double product;
    matrix_t junk(row,other.getCol());
    for(int i=0; i<row; i++){
        for(int j=0; j<other.getCol(); j++){
            product = 0;
            for(int k=0; k<col; k++){
                product+=data[i][k] *
                other.getValue(k, j);
            }
            junk[i][j] = product;
        }
    }
    return junk;
}
/*
* description: multiply two matrixes
* return: matrix
* precondition: matrix is valid
* postcondition: returns both matrixes multiply
*/

matrix_t matrix_t::operator+(const matrix_t& other) const {
    matrix_t junk = add(other);
    return junk;
}
/*
* description: add two matrixes
* return: matrix
* precondition: matrix is valid
* postcondition: returns both matrixes added
*/

matrix_t matrix_t::operator-(const matrix_t& other) const {
    matrix_t junk = subtract(other);
    return junk;
}
/*
* description: subtract two matrixes
* return: matrix
* precondition: matrix is valid
* postcondition: returns both matrixes subtracted
*/

matrix_t matrix_t::operator*(const matrix_t& other) const {
    matrix_t junk = multiply(other);
    return junk;
}
/*
* description: multiply two matrixes
* return: matrix
* precondition: matrix is valid
* postcondition: returns both matrixes multiply
*/

double* matrix_t::operator[](int n){
    return data[n];
}
/*
* description: return operator
* return: double
* precondition: matrix is valid
* postcondition: returns operator
*/
