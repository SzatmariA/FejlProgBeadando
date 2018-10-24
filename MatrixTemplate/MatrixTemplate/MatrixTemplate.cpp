

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

	T operator() (int n, int m) const { return left[n][m] + right[n][m]; }
};


template<class T, int N, int M>
class my_matrix {
	//: matrix_base {
	T data[N][M];
public:
	/** A sablonpéldány rendelkezik default konstruktorral. */
	my_matrix();

	template<class Left, class Right>
	my_matrix<T, N, M>& operator=(const MatrixSum<T, N, M, Left, Right>& m) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				data[i][j] = m(i,j);
		return *this;
	}

	/**
	 * A mátrix elemeihez való hozzáférést a kétparaméteres függvényhívás
	 * operátor felüldefiniálása biztosítja.
	 */
	const T& operator()(int n, int m) const;
	T& operator()(int n, int m);
	//TODO: Matrix elemeihez hozzeferes.
};






template<class T, int N, int M>
inline auto operator+(const my_matrix<T, N, M> &l, my_matrix<T, N, M> &r) {
	//TODO: Megirni az osszeadas operatort matrix+matrixra 
	return MatrixSum<T, N, M, my_matrix<T, N, M>, my_matrix<T, N, M>>(l, r);
}

template<class T, int N, int M, class Left, class Right>
inline auto operator+(const MatrixSum<T, N, M, Left, Right> &l, MatrixSum<T, N, M, Left, Right> &r) {
	//TODO: Megirni az osszeadas operatort MatrixSumokra.
	return;
}

int main() {
	my_matrix<int, 2, 2> mtx1;
	my_matrix<int, 2, 2> mtx2;
	my_matrix<int, 2, 2> mtx3;
	my_matrix<int, 2, 2> mtx4;

	mtx4 = mtx1 + mtx2; //+ mtx3;

	return 0;
}
