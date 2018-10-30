

#include "pch.h"
#include <iostream>

#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

template<class T, int N, int M, class Left, class Right>
class MatrixSum {
	const Left &left;
	const Right &right;
public:
	MatrixSum(const Left &l, const Right &r) : left(l), right(r) {}

	T operator() (int n, int m) const { return (left(n,m) + right(n,m)); }
};


template<class T, int N, int M, class Left, class Right>
class MatrixSub {
	const Left &left;
	const Right &right;
public:
	MatrixSub(const Left &l, const Right &r) : left(l), right(r) {}

	T operator() (int n, int m) const { return (left(n, m) - right(n, m)); }
};

template<class T, int N, int M, class Left, class Right>
class MatrixMultWithConstLeft {
	const Left &left;
	const Right &right;
public:
	MatrixMultWithConstLeft(const Left &l, const Right &r) : left(l), right(r) {}

	T operator() (int n, int m) const { 
		
			return (left * (Left)right(n, m));
		
	}
};


template<class T, int N, int M>
class my_matrix {
	//: matrix_base {
	T data[N][M];
public:
	/** A sablonpéldány rendelkezik default konstruktorral. */
	//my_matrix();

	template<class Left, class Right>
	my_matrix<T, N, M>& operator=(const MatrixSum<T, N, M, Left, Right>& m) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				data[i][j] = m(i,j);
		return *this;
	}

	template<class Left, class Right>
	my_matrix<T, N, M>& operator=(const MatrixSub<T, N, M, Left, Right>& m) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				data[i][j] = m(i, j);
		return *this;
	}

	template<class Left, class Right>
	my_matrix<T, N, M>& operator=(const MatrixMultWithConstLeft<T, N, M, Left, Right>& m) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				data[i][j] = m(i, j);
		return *this;
	}

	/**
	 * A mátrix elemeihez való hozzáférést a kétparaméteres függvényhívás
	 * operátor felüldefiniálása biztosítja.
	 */
	const T& operator()(int n, int m) const { return data[n][m]; }
	T& operator()(int n, int m) { return data[n][m]; }
	//TODO: Matrix elemeihez hozzeferes.
};





//**********************Addition***********************
template<class T, int N, int M>
inline auto operator+(const my_matrix<T, N, M> &l, my_matrix<T, N, M> &r) {
	
	return MatrixSum<T, N, M, my_matrix<T, N, M>, my_matrix<T, N, M>>(l, r);
}

template<class T, int N, int M, class Left, class Right>
inline auto operator+(const MatrixSum<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSum<T, N, M, MatrixSum<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}

template<class T, int N, int M, class Left, class Right>
inline auto operator+(const MatrixSub<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSum<T, N, M, MatrixSub<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}
//********************************************************




//**********************Subtraction***********************
template<class T, int N, int M>
inline auto operator-(const my_matrix<T, N, M> &l, my_matrix<T, N, M> &r) {

	return MatrixSub<T, N, M, my_matrix<T, N, M>, my_matrix<T, N, M>>(l, r);
}

template<class T, int N, int M, class Left, class Right>
inline auto operator-(const MatrixSub<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSub<T, N, M, MatrixSub<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}


template<class T, int N, int M, class Left, class Right>
inline auto operator-(const MatrixSum<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSub<T, N, M, MatrixSum<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}
//********************************************************



//**************Multiplication of matrices****************
template<class T, int N, int M>
inline auto operator*(const my_matrix<T, N, M> &l, my_matrix<T, N, M> &r) {

	return;
	//TODO: szorzasra matrix matrixxal
	//hiba lehet, hogy nem N*M es M*N a masik.
	//MatrixSum<T, N, M, my_matrix<T, N, M>, my_matrix<T, N, M>>(l, r);
}

template<class T, int N, int M, class Left, class Right>
inline auto operator*(const MatrixSum<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return; 
	//TODO: Szorzasra is megcsinalni.
	//MatrixSum<T, N, M, MatrixSum<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}
//********************************************************


//**************Multiplication of matrice and a constant****************
template<class T, int N, int M>
inline auto operator*(const my_matrix<T, N, M> &l, T &r) {

	return 1; //MatrixMultWithConstLeft<T, N, M, my_matrix<T, N, M>, T>(l, r);
	//TODO: szorzasra matrix matrixxal
	//hiba lehet, hogy nem N*M es M*N a masik.
	//MatrixSum<T, N, M, my_matrix<T, N, M>, my_matrix<T, N, M>>(l, r);
}

//**************Multiplication of constant and a matrice****************
template<class T, int N, int M, class Left>
inline auto operator*(const Left &l, const my_matrix<T, N, M> &r) {

	return MatrixMultWithConstLeft<T, N, M, Left, my_matrix<T, N, M>>(l, r);
}

template<class T, int N, int M, class Left, class Right>
inline auto operator*(Left &l, const MatrixMultWithConstLeft<T, N, M, Left, Right> &r) {

	return MatrixMultWithConstLeft<T, N, M, Left, MatrixMultWithConstLeft<T, N, M, Left, Right>>(l, r);
}

//********************************************************


//**********************Other methods***********************
template<class T, int N, int M>
void init(my_matrix<T, N, M>& m) {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			m(i, j) = rand() % 100;
}

template<class T, int N, int M>
void print(string s, my_matrix<T, N, M>& m) {
	cout << s;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cout << setw(4) << m(i, j);
	cout << endl;
}
//********************************************************

int main() {
	my_matrix<int, 2, 2> mtx1;
	init(mtx1);
	print("Elso matrix: " , mtx1);
	my_matrix<int, 2, 2> mtx2;
	init(mtx2);
	print("Masodik matrix: ", mtx2);
	my_matrix<int, 2, 2> mtx3;
	init(mtx3);
	print("Harmadik matrix: ", mtx3);
	my_matrix<int, 2, 2> mtx4;
	init(mtx4);
	print("Negyedik matrix: ", mtx4);
	my_matrix<int, 2, 2> mtx5;
	my_matrix<int, 2, 2> mtx6;
	my_matrix<int, 2, 2> mtx7;
	my_matrix<int, 2, 2> mtx8;
	int a = 2;
	
	//TODO: Kulonbozo meretu matrixokra hibakezeles...
	mtx5 = mtx1 + mtx2 + mtx3 + mtx4;
	mtx6 = mtx1 - mtx2 + mtx4 - mtx3 + mtx1; 
	mtx7 = a * mtx1;
	mtx8 = 5.0 *a * mtx1;
	
	print("Osszeg matrix: ", mtx5);
	print("Kulonbseg matrix: ", mtx6);
	print("Szorzat matrix: ", mtx7);
	print("Szorzat matrix: ", mtx8);

	return 0;
}
