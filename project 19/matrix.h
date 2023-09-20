//Author: Jan Jasa
//Assignment Title: Matrix Arithmetic with objects
//Assignment Description: Add matrix functions and class
//Due Date: 11/18/22
//Date Created: 11/16/22
//Date Last Modified: 11/18/22

#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <ostream>
using namespace std;

const int MAX_SIZE = 100;
const int WIDTH = 4;

class matrix_t{
private:
	int row, col;
	double data[MAX_SIZE][MAX_SIZE] = {{0}};

public:
	matrix_t();
	matrix_t(int, int);
	/*
    * description: construct a matrix
    * return: matrix
    * precondition: two ints, row and col
    * postcondition: makes a row x col matrix
    */

	void setRow(int);
	/*
    * description: set the value of row
    * return: N/A
    * precondition: value of row is valid
    * postcondition: sets row to input
    */

	void setCol(int);
	/*
    * description: set the value of col
    * return: N/A
    * precondition: value of col is valid
    * postcondition: sets col to input
    */

	void setValue(int, int, double);
	/*
    * description: set the value of a spot
    * return: N/A
    * precondition: row col and value are valid
    * postcondition: sets data[row][col] to value
    */


	int getRow() const;
	/*
    * description: returns the value of row
    * return: integer
    * precondition: matrix is valid
    * postcondition: returns row
    */

	int getCol() const;
	/*
    * description: returns the value of col
    * return: integer
    * precondition: matrix is valid
    * postcondition: returns col
    */

	double getValue(int, int) const;
	/*
    * description: returns the value of a spot
    * return: double
    * precondition: matrix is valid
    * postcondition: returns value of data[r][c]
    */


	void display(ostream&) const;
	/*
    * description: returns the value of each data
    * return: ostream
    * precondition: matrix is valid
    * postcondition: returns matrix
    */

	matrix_t add(const matrix_t&) const;
    /*
    * description: add two matrixes
    * return: matrix
    * precondition: matrix is valid
    * postcondition: returns both matrixes added
    */

	matrix_t subtract(const matrix_t&) const;
    /*
    * description: subtract two matrixes
    * return: matrix
    * precondition: matrix is valid
    * postcondition: returns both matrixes subtracted
    */

    matrix_t multiply(const matrix_t&) const;
    /*
    * description: multiply two matrixes
    * return: matrix
    * precondition: matrix is valid
    * postcondition: returns both matrixes multiply
    */

	matrix_t operator+(const matrix_t&) const;
    /*
    * description: add two matrixes
    * return: matrix
    * precondition: matrix is valid
    * postcondition: returns both matrixes added
    */

	matrix_t operator-(const matrix_t&) const;
    /*
    * description: subtract two matrixes
    * return: matrix
    * precondition: matrix is valid
    * postcondition: returns both matrixes subtracted
    */

	matrix_t operator*(const matrix_t&) const;
    /*
    * description: multiply two matrixes
    * return: matrix
    * precondition: matrix is valid
    * postcondition: returns both matrixes multiply
    */

	double*  operator[](int n);
    /*
    * description: return operator
    * return: double
    * precondition: matrix is valid
    * postcondition: returns operator
    */

};

#endif // MATRIX_H_INCLUDED
