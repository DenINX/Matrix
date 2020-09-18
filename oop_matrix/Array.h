#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

/*
This class describes a 2x2 math matrix.
It includes:
	1. Basic math operations, such as
	   addition, subtraction, multiplication of matrices

	2. Finding the determinant;

	3. Transpose, find the inverse matrix, create a diagonal,
	   fill with one specific or random value;

	4. Output matrix as string value.

	Gauss elimination and Gauss-Jordan method were used to
	calculate the determinant and inverse matrix, respectively.
*/

using namespace std;
using UserMethod = double(*)(double, double);	

namespace lab {

	// Basic types for Matrix class
	typedef vector<double> array_t;
	typedef vector<vector<double>> matr_t;
	
	class Matrix {
	private:
		matr_t core_;	
	
		
	private:
		
		matr_t gauss();
		
		
		static bool canMultiply(const Matrix &First, const Matrix &Second);
		
		
		static bool isSameSize(const Matrix &First, const Matrix &Second);
		
		
		void makeMath(Matrix &Result, const Matrix &Object, UserMethod function);

	public:
		
		Matrix() { core_ = matr_t(2, array_t(2, 0)); }
		
		Matrix(size_t rows, size_t cols) { core_ = matr_t(rows, array_t(cols, 0)); }
		
		Matrix(matr_t &Name) { core_ = Name; }
		
		
		size_t rows() const { return core_.size(); }
		
		size_t cols(size_t index = 0) const { return core_[index].size(); }

		
		double get(size_t row, size_t col) const { return core_[row][col]; }
		
		array_t get(size_t row) const { return core_[row]; }
		
		/*	Math operations */
		Matrix operator+ (const Matrix &Object); 
		Matrix operator- (const Matrix &Object); 
		Matrix operator* (const Matrix &Object); 
		Matrix operator* (double value); 

		/*	Math operations */
		void operator+= (const Matrix &Object);
		void operator-= (const Matrix &Object);
		void operator*= (const Matrix &Object);
		void operator*= (double value);

		
		double det();
		
		void transpose();
		
		void fill(double value = 0);
		
		void random(double min = -100.00, double max = 100.00);
		
		void diag();
		
		void inverse();

		
		string str(unsigned short width = 6, unsigned short pointPos = 1) const;
		
		string str(array_t List, unsigned short width = 6, unsigned short pointPos = 1) const;
	};
}

#endif // !ARRAY_H

