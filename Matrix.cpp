#include"Matrix.h"
template<typename T>
Matrix<T>::Matrix()
{
	rows = cols = 0;
	data = nullptr;
}

template<typename T>
Matrix<T>::Matrix(int r, int c)
{
	rows = r > 0 ? r : 2;
	cols = c > 0 ? c : 2;
	data = new T *[r];
	for (int i = 0; i < rows; i = i + 1)
	{
		data[i] = new T[cols];
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> & r)
{
	if (this == &r || data == nullptr)
	{
		return;

	}

	rows = r.rows;
	cols = r.cols;

	data = new T *[rows];
	for (int i = 0; i < rows; i = i + 1)
	{

		data[i] = new T[cols];
	}


	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			data[i][j] = r.data[i][j];
		}
	}
}


template<typename T>
T & Matrix<T>::at(int r, int c)
{
	return data[r][c];
}


template<typename T>
void Matrix<T>::reSize(int newRow, int newCol)
{
	Matrix temp(*this);
	this->~Matrix();
	rows = newRow;
	cols = newCol;
	data = new T *[rows];
	for (int i = 0; i < cols; i = i + 1)
	{
		data[i] = new T[cols];
	}

	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			data[i][j] = temp.data[i][j];
		}
	}

}

template<typename T>
Matrix<T>::~Matrix()
{
	if (!data)
	{
		return;
	}

	for (int i = 0; i < rows; i = i + 1)
	{
		delete data[i];
	}
	delete[] data;
}

template<typename T>
Matrix<T> Matrix<T>::transpose()
{

	Matrix<T> t(rows, cols);
	int index = 0;
	for (int i = 0; i < cols; i = i + 1)
	{
		for (int j = 0; j < rows; j = j + 1)
		{
			t.data[i][j] = (*data)[index];
			index = index + 1;
		}
	}

	return t;
}


template<typename T>
Matrix<T> Matrix<T>::add(Matrix m2)
{

	Matrix<T> added(rows, cols);
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			added.at(i, j) = data[i][j] + m2.at(i, j);
		}

	}


	return added;
}



template<typename T>
Matrix<T> Matrix<T>::operator = (const Matrix<T> & r)
{
	rows = r.rows;
	cols = r.cols;

	data = new T *[rows];
	for (int i = 0; i < rows; i = i + 1)
	{
		data[i] = new T[cols];
	}

	return *this;

}



template<typename T>
T & Matrix<T>::operator ()(int r, int c)
{
	return data[r][c];
}



template<typename T>
void Matrix<T>::input()
{
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			cin >> data[i][j];
		}
	}
}



template<typename T>
void Matrix<T>::display()
{
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			cout << data[i][j];
			cout << ":";
		}
		cout << endl;
	}
}



template <typename T>
ostream & operator<<(ostream & ref, Matrix<T> & r)
{
	r.display();
	return cout;
}

template<typename T>
istream & operator>>(istream & ref, Matrix<T> & r)
{
	r.input();
	return cin;
}