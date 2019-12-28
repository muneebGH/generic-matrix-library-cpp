#include<iostream>
using namespace std;
template <typename T>
class Matrix
{
	int rows;
	int cols;
	T ** data;
public:
	Matrix();

	Matrix(int r, int c);

	Matrix(const Matrix<T> & r);


	T & at(int r, int c);


	void reSize(int newRow, int newCol);

	~Matrix();
	
	Matrix<T> transpose();

	Matrix<T> add(Matrix m2);

	Matrix<T> operator = (const Matrix<T> & r);

	T & operator ()(int r, int c);

	void input();

	void display();

	friend ostream & operator<<(ostream & ref, Matrix<T> & r);

	friend istream & operator>>(istream & ref, Matrix<T> & r);

};
