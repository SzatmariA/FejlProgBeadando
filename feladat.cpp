#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;
template<class T, int N, int M, class Left, class Right>
class MatrixSum {
	//This is a class for Matrice addition
	const Left &left;
	const Right &right;
public:
	MatrixSum(const Left &l, const Right &r) : left(l), right(r) {}
	//This actually adds the numbers in the matrices.
	T operator() (int n, int m) const { return (left(n, m) + right(n, m)); }
	~MatrixSum() {};
};

template<class T, int N, int M, class Left, class Right>
class MatrixSub {
	//This class is for Matrice subtraction.
	const Left &left;
	const Right &right;
public:
	//This is the constructor.
	MatrixSub(const Left &l, const Right &r) : left(l), right(r) {}
	//This one does the actual subtraction.
	T operator() (int n, int m) const { return (left(n, m) - right(n, m)); }
	//Just a lonely destructor
	~MatrixSub() {};
};

template<class T, int N, int M, class Left, class Right>
class MatrixMultWithConstLeft {
	//This class makes the const and matrice multiplication work.
	const Left &left;
	const Right &right;
public:
	//It's the constructor...again.
	MatrixMultWithConstLeft(const Left &l, const Right &r) : left(l), right(r) {}
	//This one is for the actual multiplication.
	T operator() (int n, int m) const {

		return (left * (Left)right(n, m));

	}
	//Dude, you already know...
	~MatrixMultWithConstLeft() {};
};

template<class T, int N, int M, class Left, class Right>
class MatrixMultWithConstRight {
	//This class is like the one before but it's from the right.
	const Left &left;
	const Right &right;
public:
	//Mate, it's getting annoying, but it is a CONSTRUCTOR.
	MatrixMultWithConstRight(const Left &l, const Right &r) : left(l), right(r) {}
	//This one does the multiplication.
	T operator() (int n, int m) const {
		return ((Right)left(n, m) * right);
	}
	//Ugh, here listen to this: 
	//https://www.youtube.com/watch?v=o3mSLW60i_k
	//That's how I feel about all this rn. Sry mate. (Actually am not.)
	~MatrixMultWithConstRight() {};
};

template<class T, int N, int K, int M, class Left, class Right>
class MatrixMult {
	//And that's for multiplication of matrices.
	const Left &left;
	const Right &right;
public:
	//Mate, that's a constructor, if you hadn't pay attention the last 1000 times.
	MatrixMult(const Left &l, const Right &r) : left(l), right(r) {}
	//Okay, this needs a little explanation:
	//So n stands for row of the first matrix
	//m stands for the column of the first, and the row for the second
	//And last but not least, k is the column of the second matrix. K?
	T operator() (int n, int m, int k) const {
		//cout << "ez itt az n, m, es k:" << n << m << k << endl;
		
		return left(n, m) * right(m, k);
		//A magic abban rejlik, hogy a leftnek kene atadni az n-t es a k-t
		//de akkor meg a normal szorzas nem jon ki
		//term does not evaluate to a function taking 2 arguments, 
		//mert, hogy a bal oldali az matrixMult
	}
	//This made me mad tbh. 
	//In order to make MatriceMult * my_matrix work, you need to calculate the MatriceMult.
	T operator() (int n, int m) const {
		
		T leftMatriceValue = (T)0;
		for (int i = 0; i < K; ++i) {
			
			leftMatriceValue += left(n, i) * right(i, m);
		}
		
		return leftMatriceValue;
	}
	//Your turn, I forgot what that does.
	~MatrixMult() {};
};

template<class T, int N, int M>
class my_matrix : matrix_base {
	//This is the main class.
	T data[N][M]; //This stores the actual data.
public:
	//That one does the Addition.
	template<class Left, class Right>
	my_matrix<T, N, M>& operator=(const MatrixSum<T, N, M, Left, Right>& m) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				data[i][j] = m(i, j);
		return *this;
	}
	//That one does the Subtraction.
	template<class Left, class Right>
	my_matrix<T, N, M>& operator=(const MatrixSub<T, N, M, Left, Right>& m) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				data[i][j] = m(i, j);
		return *this;
	}
	//That one does the Multiplication with a constant.
	template<class Left, class Right>
	my_matrix<T, N, M>& operator=(const MatrixMultWithConstLeft<T, N, M, Left, Right>& m) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				data[i][j] = m(i, j);
		return *this;
	}
	//The same but from the other side.
	template<class Left, class Right>
	my_matrix<T, N, M>& operator=(const MatrixMultWithConstRight<T, N, M, Left, Right>& m) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				data[i][j] = m(i, j);
		return *this;
	}
	//And the actual multiplication.
	template<int K, class Left, class Right>
	//N - sorok szama az egyikbe
	//K - oszlopok szama az elsobe/ sorok szama a masodikba
	//M - oszlopok szama a masodikba
	my_matrix<T, N, M>& operator=(const MatrixMult<T, N, K, M, Left, Right>  &m) {
		

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) {
				data[i][j] = (T)0;
				for (int l = 0; l < K; ++l) {
					data[i][j] += m(i,l, j); //TODO: m, l, j-re mukodott
				}
			}
		return *this;
	}
	//This way you can reach the data.
	const T& operator()(int n, int m) const { return data[n][m]; }
	//same goes for dat I guess.
	T& operator()(int n, int m) { return data[n][m]; }
};


//Addition
//Addition of two matrices.
template<class T, int N, int M>
inline auto operator+(const my_matrix<T, N, M> &l, my_matrix<T, N, M> &r) {

	return MatrixSum<T, N, M, my_matrix<T, N, M>, my_matrix<T, N, M>>(l, r);
}
//Addition of MatrixSum and my_matrix.
template<class T, int N, int M, class Left, class Right>
inline auto operator+(const MatrixSum<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSum<T, N, M, MatrixSum<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}
//Adding matrix to matrixsum.
template<class T, int N, int M, class Left, class Right>
inline auto operator+(const my_matrix<T, N, M> &l,const MatrixSum<T, N, M, Left, Right> &r) {

	return MatrixSum<T, N, M, my_matrix<T, N, M>, MatrixSum<T, N, M, Left, Right>>(l, r);
}

//Adding two matrixsums.
template<class T, int N, int M, class Left1, class Right1, class Left2, class Right2>
inline auto operator+(const MatrixSum<T, N, M, Left1, Right1> &l, const MatrixSum<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSum<T, N, M, Left1, Right1>, MatrixSum<T, N, M, Left2, Right2>>(l, r);
}

template<class T, int N, int M, class Left1, class Right1, class Left2, class Right2>
inline auto operator+(const MatrixSum<T, N, M, Left1, Right1> &l, const MatrixSub<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSum<T, N, M, Left1, Right1>, MatrixSub<T, N, M, Left2, Right2>>(l, r);
}

template<class T, int N, int M, class Left1, class Right1, class Left2, class Right2>
inline auto operator+(const MatrixSub<T, N, M, Left1, Right1> &l, const MatrixSum<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSub<T, N, M, Left1, Right1>, MatrixSum<T, N, M, Left2, Right2>>(l, r);
}

template<class T, int N, int M, class Left1, class Right1, class Left2, class Right2>
inline auto operator+(const MatrixSub<T, N, M, Left1, Right1> &l, const MatrixSub<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSub<T, N, M, Left1, Right1>, MatrixSub<T, N, M, Left2, Right2>>(l, r);
}
//Addition of MatrixSub and my_matrix.
template<class T, int N, int M, class Left, class Right>
inline auto operator+(const MatrixSub<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSum<T, N, M, MatrixSub<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}

template<class T, int N, int M, class Left, class Right>
inline auto operator+(my_matrix<T, N, M> &l, const MatrixSub<T, N, M, Left, Right> &r) {
	return MatrixSum<T, N, M, my_matrix<T, N, M>,  MatrixSub<T, N, M, Left, Right>>(l, r);
}
//Addition of MatrixMultWithConstLeft and my_matrix.
template<class T, int N, int M, class Left, class Right>
inline auto operator+(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSum<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}

//Addition of  my_matrix and constmult.
template<class T, int N, int M, class Left, class Right>
inline auto operator+(my_matrix<T, N, M> &l, const MatrixMultWithConstLeft<T, N, M, Left, Right> &r) {
	return MatrixSum<T, N, M, my_matrix<T, N, M>, MatrixMultWithConstLeft<T, N, M, Left, Right>>(l, r);
}

//Addition of MatrixMultWithConstRight and my_matrix.
template<class T, int N, int M, class Left, class Right>
inline auto operator+(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSum<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}
//Addition of  my_matrix and constRight.
template<class T, int N, int M, class Left, class Right>
inline auto operator+(my_matrix<T, N, M> &l, const MatrixMultWithConstRight<T, N, M, Left, Right> &r) {
	return MatrixSum<T, N, M, my_matrix<T, N, M>, MatrixMultWithConstRight<T, N, M, Left, Right>>(l, r);
}
//Addition of MatrixMultWithConstRight and MatrixConstR.
template<class T, int N, int M, class Left, class Right>
inline auto operator+(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left, Right> &r) {
	return MatrixSum<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left, Right>>(l, r);
}
//Addition of MatrixMultWithConstLeft and Right.
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left2, Right2>>(l, r);
}
//Addition of MatrixMultWithConstRight and Left.
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2>>(l, r);
}
//Addition of sum and left.
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixSum<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSum<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2>>(l, r);
}
//Addition of sum and right
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixSum<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSum<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left2, Right2>>(l, r);
}
//Addition of left and left
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2>>(l, r);
}
//Addition of right and left
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixSub<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSub<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2>>(l, r);
}
//Addition of sub and right
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixSub<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSub<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left2, Right2>>(l, r);
}

template<class T, int N, int M, int K, int E, class Right, class Left2, class Right2>
inline auto operator+(const MatrixMultWithConstLeft<T, N, M, T, Right> &l, const MatrixMult<T, N, K, E, Left2, Right2> &r) {
	return MatrixSum<T, N, E, MatrixMultWithConstLeft<T, N, M, T, Right>, MatrixMult<T, N, K, E, Left2, Right2>>(l, r);
}

template<class T, int N, int M, int K, int E, class Right, class Left2, class Right2>
inline auto operator+(const MatrixMultWithConstRight<T, N, M, T, Right> &l, const MatrixMult<T, N, K, E, Left2, Right2> &r) {
	return MatrixSum<T, N, E, MatrixMultWithConstRight<T, N, M, T, Right>, MatrixMult<T, N, K, E, Left2, Right2>>(l, r);
}

template<class T, int N, int M, int K, class Left, class Right, class Right2>
inline auto operator+(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixMultWithConstLeft<T,  M, K,  T, Right2> &r) {
	return MatrixSum<T, N, K, MatrixMult<T, N, M, K, Left, Right>, MatrixMultWithConstLeft<T, M, K, T, Right2>>(l, r);
}

template<class T, int N, int M, int K, class Left, class Right, class Left2>
inline auto operator+(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixMultWithConstRight<T, M, K, Left2, T> &r) {
	return MatrixSum<T, N, K, MatrixMult<T, N, M, K, Left, Right>, MatrixMultWithConstRight<T, M, K, Left2, T>>(l, r);
}

template<class T, int N, int M, int K, class Left, class Right>
inline auto operator+(const MatrixMult<T, N, M, K, Left, Right> &l, const my_matrix<T, N, K> &r) {
	return MatrixSum<T, N, K, MatrixMult<T, N, M, K, Left, Right>, my_matrix<T, N, K>>(l, r);
}

template<class T, int N, int M, int K, class Left, class Right>
inline auto operator+(const my_matrix<T, N, K> &l, const MatrixMult<T, N, M, K, Left, Right> &r) {
	return MatrixSum<T, N, K, my_matrix<T, N, K>, MatrixMult<T, N, M, K, Left, Right>>(l, r);
}


//This is getting annoying now...
template<class T, int N, int M>
inline auto operator-(const my_matrix<T, N, M> &l, my_matrix<T, N, M> &r) {

	return MatrixSub<T, N, M, my_matrix<T, N, M>, my_matrix<T, N, M>>(l, r);
}
//Lorem ipsum
template<class T, int N, int M, class Left, class Right>
inline auto operator-(const MatrixSub<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSub<T, N, M, MatrixSub<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}

template<class T, int N, int M, class Left, class Right>
inline auto operator-(const my_matrix<T, N, M> &l, const MatrixSub<T, N, M, Left, Right> &r) {

	return MatrixSub<T, N, M, my_matrix<T, N, M>, MatrixSub<T, N, M, Left, Right>>(l, r);
}

template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixSub<T, N, M, Left, Right> &l, const MatrixSub<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixSub<T, N, M, Left, Right>, MatrixSub<T, N, M, Left2, Right2>>(l, r);
}

//It does what it does
template<class T, int N, int M, class Left, class Right>
inline auto operator-(const MatrixSum<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSub<T, N, M, MatrixSum<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}

template<class T, int N, int M, class Left, class Right>
inline auto operator-(my_matrix<T, N, M> &l,  const MatrixSum<T, N, M, Left, Right> &r) {
	return MatrixSub<T, N, M, my_matrix<T, N, M>,  MatrixSum<T, N, M, Left, Right>>(l, r);
}

template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixSum<T, N, M, Left, Right> &l, const MatrixSum<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixSum<T, N, M, Left, Right>, MatrixSum<T, N, M, Left2, Right2>>(l, r);
}

template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixSum<T, N, M, Left, Right> &l, const MatrixSub<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixSum<T, N, M, Left, Right>, MatrixSub<T, N, M, Left2, Right2>>(l, r);
}

template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixSub<T, N, M, Left, Right> &l, const MatrixSum<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixSub<T, N, M, Left, Right>, MatrixSum<T, N, M, Left2, Right2>>(l, r);
}

//Just a lonely comment.
template<class T, int N, int M, class Left, class Right>
inline auto operator-(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}
//Could you recommend some good shows?
template<class T, int N, int M, class Left, class Right>
inline auto operator-(my_matrix<T, N, M> &l, const MatrixMultWithConstLeft<T, N, M, Left, Right> &r) {
	return MatrixSub<T, N, M, my_matrix<T, N, M>, MatrixMultWithConstLeft<T, N, M, Left, Right>>(l, r);
}

//I'm out of series on Netflix.
template<class T, int N, int M, class Left, class Right>
inline auto operator-(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}
//Wanna hear a joke?
template<class T, int N, int M, class Left, class Right>
inline auto operator-(my_matrix<T, N, M> &l, const MatrixMultWithConstRight<T, N, M, Left, Right> &r) {
	return MatrixSub<T, N, M, my_matrix<T, N, M>, MatrixMultWithConstRight<T, N, M, Left, Right>>(l, r);
}
//No?
template<class T, int N, int M, class Left, class Right>
inline auto operator-(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left, Right> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left, Right>>(l, r);
}
//Okay, whatever.
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left2, Right2>>(l, r);
}
//Q. What's the difference between a hippo and a Zippo?
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2>>(l, r);
}
//A.A hippo is really heavy, and a Zippo is a little lighter.
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixSub<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixSub<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2>>(l, r);
}
//Yada yada yada
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixSub<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixSub<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left2, Right2>>(l, r);
}
//F is for Family season 3 comes out on 30th of November.
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2>>(l, r);
}
template<class T, int N, int M, int K, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, const MatrixMult<T, N, M, K, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, MatrixMult<T, N, M, K, Left2, Right2>>(l, r);
}

template<class T, int N, int M, int K, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, const MatrixMult<T, N, M, K, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, MatrixMult<T, N, M, K, Left2, Right2>>(l, r);
}


//Multiplication of matrices
//You should really check it out.
template<class T, int N, int M, int K>
inline auto operator*(const my_matrix<T, N, M> &l, my_matrix<T, M, K> &r) {
	return MatrixMult<T, N, M, K, my_matrix<T, N, M>, my_matrix<T, M, K>>(l, r);
	//hiba lehet, hogy nem N*M es M*N a masik.
}

template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const MatrixSum<T,N,M, Left, Right> &l, my_matrix<T, M, K> &r) {
	return MatrixMult<T, N, M, K, MatrixSum<T, N, M, Left, Right>, my_matrix<T, M, K>>(l, r);
	//hiba lehet, hogy nem N*M es M*N a masik.
}

template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const my_matrix<T, N, M> &l, const MatrixSum<T, M, K, Left, Right>  &r) {
	return MatrixMult<T, N, M, K, my_matrix<T, N, M>, MatrixSum<T, M, K, Left, Right>>(l, r);
	//hiba lehet, hogy nem N*M es M*N a masik.
}

template<class T, int N, int M, int K, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixSum<T, N, M, Left, Right> &l, const MatrixSum<T, M, K, Left2, Right2> &r) {
	return MatrixMult<T, N, M, K, MatrixSum<T, N, M, Left, Right>, MatrixSum<T, M, K, Left2, Right2>>(l, r);
	//hiba lehet, hogy nem N*M es M*N a masik.
}

template<class T, int N, int M, int K, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixSum<T, N, M, Left, Right> &l, const MatrixSub<T, M, K, Left2, Right2> &r) {
	return MatrixMult<T, N, M, K, MatrixSum<T, N, M, Left, Right>, MatrixSub<T, M, K, Left2, Right2>>(l, r);
	//hiba lehet, hogy nem N*M es M*N a masik.
}

template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const MatrixSub<T, N, M, Left, Right> &l, my_matrix<T, M, K> &r) {
	return MatrixMult<T, N, M, K, MatrixSub<T, N, M, Left, Right>, my_matrix<T, M, K>>(l, r);
	//hiba lehet, hogy nem N*M es M*N a masik.
}

template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const my_matrix<T, N, M> &l, const MatrixSub<T, M, K, Left, Right>  &r) {
	return MatrixMult<T, N, M, K, my_matrix<T, N, M>, MatrixSub<T, M, K, Left, Right>>(l, r);
	//hiba lehet, hogy nem N*M es M*N a masik.
}

template<class T, int N, int M, int K, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixSub<T, N, M, Left, Right> &l, const MatrixSum<T, M, K, Left2, Right2> &r) {
	return MatrixMult<T, N, M, K, MatrixSub<T, N, M, Left, Right>, MatrixSum<T, M, K, Left2, Right2>>(l, r);
	//hiba lehet, hogy nem N*M es M*N a masik.
}

template<class T, int N, int M, int K, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixSub<T, N, M, Left, Right> &l, const MatrixSub<T, M, K, Left2, Right2> &r) {
	return MatrixMult<T, N, M, K, MatrixSub<T, N, M, Left, Right>, MatrixSub<T, M, K, Left2, Right2>>(l, r);
	//hiba lehet, hogy nem N*M es M*N a masik.
}
//Okay this might need a little explanation.
//N stands for the first Mult's rows.
//M stands for the first Mult's columns
//K stands for the Mult's right coluns.
//E stands for the my_matrix's columns.
template<class T, int N, int M, int K, int E, class Left, class Right>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, my_matrix<T, K, E> &r) {

	return MatrixMult<T, N, K, E, MatrixMult<T, N, M, K, Left, Right>, my_matrix<T, K, E>>(l, r);;
	//TODO: Szorzasra is megcsinalni.
	//MatrixSum<T, N, M, MatrixSum<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}

template<class T, int N, int M, int K, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixSum<T, K, E, Left2, Right2> &r) {
	return MatrixMult<T, N, K, E, MatrixMult<T, N, M, K, Left, Right>, MatrixSum<T, K, E, Left2, Right2>>(l, r);;
}

template<class T, int N, int M, int K, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixSub<T, K, E, Left2, Right2> &r) {
	return MatrixMult<T, N, K, E, MatrixMult<T, N, M, K, Left, Right>, MatrixSub<T, K, E, Left2, Right2>>(l, r);;
}

//balrol valo szorzas
template<class T, int N, int M, int K, int E, class Left, class Right>
inline auto operator*(my_matrix<T, N, M> &l, const MatrixMult<T, M, K, E, Left, Right> &r) {
	
	return MatrixMult<T, N, M, E, my_matrix<T, N, M>, MatrixMult<T, M, K, E, Left, Right>>(l, r);;
	//TODO: Szorzasra is megcsinalni.
	//MatrixSum<T, N, M, MatrixSum<T, N, M, Left, Right>, my_matrix<T, N, M>>(l, r);
}
//summal valo balrol szorzas.
template<class T, int N, int M, int K, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixSum<T, N, M, Left, Right> &l, const MatrixMult<T, M, K, E, Left2, Right2> &r) {
	return MatrixMult<T, N, M, E, MatrixSum<T, N, M, Left, Right>, MatrixMult<T, M, K, E, Left2, Right2>>(l, r);;
}

//subbal valo balrol szorzas.
template<class T, int N, int M, int K, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixSub<T, N, M, Left, Right> &l, const MatrixMult<T, M, K, E, Left2, Right2> &r) {
	return MatrixMult<T, N, M, E, MatrixSub<T, N, M, Left, Right>, MatrixMult<T, M, K, E, Left2, Right2>>(l, r);;
}
//MatrixLeftConsttal szorzas matrixra.
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, my_matrix<T, M, K> &r) {
	return MatrixMult<T, N, M, K, MatrixMultWithConstLeft<T, N, M, Left, Right>, my_matrix<T, M, K>>(l, r);
}
//MatrixRightConsttal szorzas matrixra.
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, my_matrix<T, M, K> &r) {
	return MatrixMult<T, N, M, K, MatrixMultWithConstRight<T, N, M, Left, Right>, my_matrix<T, M, K>>(l, r);
}

//MatrixLeftConsttal szorzas matrixra.
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const my_matrix<T, N, M >  &l,  const MatrixMultWithConstLeft<T, M, K, Left, Right> &r) {
	return MatrixMult<T, N, M, K, my_matrix<T, N, M>, MatrixMultWithConstLeft<T, M, K, Left, Right>>(l, r);
}
//MatrixLeftConsttal szorzas matrixra.
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const my_matrix<T, N,M>  &l, const MatrixMultWithConstRight<T, M, K, Left, Right> &r) {
	return MatrixMult<T, N, M, K, my_matrix<T, N,M>, MatrixMultWithConstRight<T, M ,K, Left, Right>>(l, r);
}

template<class T, int N, int M, int K, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixMultWithConstLeft<T, K, E, Left2, Right2> &r) {
	return MatrixMult<T, N, K, E, MatrixMult<T, N, M, K, Left, Right>, MatrixMultWithConstLeft<T, K, E, Left2, Right2>>(l, r);;
}

template<class T, int N, int M, int K, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixMultWithConstRight<T, K, E, Left2, Right2> &r) {
	return MatrixMult<T, N, K, E, MatrixMult<T, N, M, K, Left, Right>, MatrixMultWithConstRight<T, K, E, Left2, Right2>>(l, r);;
}



template<class T, int N, int M, int K, int F, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixMult < T, K, F, E, Left2, Right2> &r) {
	return MatrixMult<T, N, K, E, MatrixMult<T, N, M, K, Left, Right>, MatrixMult<T, K, F, E, Left2, Right2>>(l, r);;
}


//Multiplication of matrice and a constant
template<class T, int N, int M>
inline auto operator*(const my_matrix<T, N, M> &l, const T &r) {
	return MatrixMultWithConstRight<T, N, M, my_matrix<T, N, M>, T>(l, r);
}

template<class T, int N, int M, class Left>
inline auto operator*(const MatrixMultWithConstRight<T, N, M, Left, T> &l, const T &r) {
	return MatrixMultWithConstRight<T, N, M, MatrixMultWithConstRight<T, N, M, Left, T>, T>(l, r);
}

template<class T, int N, int M, class Left, class Right>
inline auto operator*(const MatrixSum<T, N, M, Left, Right> &l, const T &r) {
	return MatrixMultWithConstRight<T, N, M, MatrixSum<T, N, M, Left, Right>, T>(l, r);
}

template<class T, int N, int M, class Left, class Right>
inline auto operator*(const MatrixSub<T, N, M, Left, Right> &l, const T &r) {
	return MatrixMultWithConstRight<T, N, M, MatrixSub<T, N, M, Left, Right>, T>(l, r);
}

template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, const T &r) {
	return MatrixMultWithConstRight<T, N, K, MatrixMult<T, N, M, K, Left, Right> ,T>(l, r);
}

template<class T, int N, int M, class Right>
inline auto operator*(const MatrixMultWithConstLeft<T, N, M, T, Right> &l, const T &r) {
	return MatrixMultWithConstRight<T, N, M, MatrixMultWithConstLeft<T, N, M, T, Right>, T>(l, r);
}

//Multiplication of constant and a matrice
template<class T, int N, int M>
inline auto operator*(const T &l, const my_matrix<T, N, M> &r) {
	return MatrixMultWithConstLeft<T, N, M, T, my_matrix<T, N, M>>(l, r);
}

template<class T, int N, int M, class Right>
inline auto operator*(const T &l, const MatrixMultWithConstLeft<T, N, M, T, Right> &r) {
	return MatrixMultWithConstLeft<T, N, M, T, MatrixMultWithConstLeft<T, N, M, T, Right>>(l, r);
}

template<class T, int N, int M, class Left, class Right>
inline auto operator*(const T &l, const MatrixSum<T, N, M, Left, Right> &r) {
	return MatrixMultWithConstLeft<T, N, M, T, MatrixSum<T, N, M, Left, Right>>(l, r);
}

template<class T, int N, int M, class Left, class Right>
inline auto operator*(const T &l, const MatrixSub<T, N, M, Left, Right> &r) {
	return MatrixMultWithConstLeft<T, N, M, T, MatrixSub<T, N, M, Left, Right>>(l, r);
}

template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const T &l, const MatrixMult<T, N, M, K, Left, Right> &r) {
	return MatrixMultWithConstLeft<T, N, K, T, MatrixMult<T, N, M, K, Left, Right>>(l, r);
}


template<class T, int N, int M, class Left>
inline auto operator*(const T &l, const MatrixMultWithConstRight<T, N, M, Left, T> &r) {
	return MatrixMultWithConstLeft<T, N, M, T, MatrixMultWithConstRight<T, N, M, Left, T>>(l, r);
}