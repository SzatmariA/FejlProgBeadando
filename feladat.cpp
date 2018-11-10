#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;
/**
 * @brief This class is for Matrix addition.
 * 
 * @tparam T 
 * @tparam N rows
 * @tparam M columns
 * @tparam Left left expression
 * @tparam Right right expression
 */
template<class T, int N, int M, class Left, class Right>
/**
 * @brief MatrixSum
 * 
 */
class MatrixSum {
	/**
	 * @brief This is the left expr.
	 * 
	 */
	const Left &left;
	/**
	 * @brief This is the right expr
	 * 
	 */
	const Right &right;
public:
	/**
	 * @brief Construct a new Matrix Sum object
	 * 
	 * @param l left expr
	 * @param r right expr
	 */
	MatrixSum(const Left &l, const Right &r) : left(l), right(r) {}
	/**
	 * @brief This actually adds the numbers in the matrices.
	 * 
	 * @param n rows
	 * @param m columns
	 * @return T with a class.
	 */
	T operator() (int n, int m) const { return (left(n, m) + right(n, m)); }
	/**
	 * @brief Destroy the Matrix Sum object
	 * 
	 */
	~MatrixSum() {};
};

/**
 * @brief something
 * 
 * @tparam T T
 * @tparam N rows
 * @tparam M columns
 * @tparam Left left
 * @tparam Right right
 */
template<class T, int N, int M, class Left, class Right>
/**
 * @brief asd
 * 
 */
class MatrixSub {
	/**
	 * @brief This is the left expr.
	 * 
	 */
	const Left &left;
	/**
	 * @brief This is the right expr
	 * 
	 */
	const Right &right;
public:
	/**
	 * @brief Construct a new Matrix Sub object
	 * 
	 * @param l left
	 * @param r right
	 */
	MatrixSub(const Left &l, const Right &r) : left(l), right(r) {}
	/**
	 * @brief This one does the actual subtraction.
	 * 
	 * @param n rows
	 * @param m cols
	 * @return T Tea
	 */
	T operator() (int n, int m) const { return (left(n, m) - right(n, m)); }
	/**
	 * @brief Destroy the Matrix Sub object
	 * 
	 */
	~MatrixSub() {};
};

/**
 * @brief This class makes the const and matrice multiplication work.
 * 
 * @tparam T T
 * @tparam N row
 * @tparam M col
 * @tparam Left left
 * @tparam Right right
 */
template<class T, int N, int M, class Left, class Right>
/**
 * @brief something
 * 
 */
class MatrixMultWithConstLeft {
	/**
	 * @brief This is the left expr.
	 * 
	 */
	const Left &left;
	/**
	 * @brief This is the right operand
	 * 
	 */
	const Right &right;
public:
	/**
	 * @brief Construct a new Matrix Mult With Const Left object
	 * 
	 * @param l left
	 * @param r right
	 */
	MatrixMultWithConstLeft(const Left &l, const Right &r) : left(l), right(r) {}
	
	/**
	 * @brief This one is for the actual multiplication.
	 * 
	 * @param n row
	 * @param m col
	 * @return T Tea
	 */
	T operator() (int n, int m) const {
		return (left * (Left)right(n, m));
	}
	/**
	 * @brief Destroy the Matrix Mult With Const Left object
	 * 
	 */
	~MatrixMultWithConstLeft() {};
};


/**
 * @brief This class is like the one before but it's from the right.
 * 
 * @tparam T Tea
 * @tparam N row
 * @tparam M col
 * @tparam Left left
 * @tparam Right right
 */
template<class T, int N, int M, class Left, class Right>
/**
 * @brief qwerty
 * 
 */
class MatrixMultWithConstRight {
	/**
	 * @brief This is the left expr.
	 * 
	 */
	const Left &left;
	/**
	 * @brief This is the right epr
	 * 
	 */
	const Right &right;
public:
	/**
	 * @brief Construct a new Matrix Mult With Const Right object
	 * 
	 * @param l left
	 * @param r right
	 */
	MatrixMultWithConstRight(const Left &l, const Right &r) : left(l), right(r) {}
	//
	/**
	 * @brief This one does the multiplication.
	 * 
	 * @param n rows
	 * @param m col
	 * @return T T
	 */
	T operator() (int n, int m) const {
		return ((Right)left(n, m) * right);
	}
	//Ugh, here listen to this: 
	//https://www.youtube.com/watch?v=o3mSLW60i_k
	//That's how I feel about all this rn. Sry mate. (Actually am not.)
	/**
	 * @brief Destroy the Matrix Mult With Const Right object
	 * 
	 */
	~MatrixMultWithConstRight() {};
};

/**
 * @brief And that's for multiplication of matrices.
 * 
 * @tparam T tea
 * @tparam N row
 * @tparam K row/col
 * @tparam M col
 * @tparam Left left
 * @tparam Right right
 */
template<class T, int N, int K, int M, class Left, class Right>
/**
 * @brief dude...
 * 
 */
class MatrixMult {
	/**
	 * @brief This is the left expr.
	 * 
	 */
	const Left &left;
	/**
	 * @brief This is the right epr
	 * 
	 */
	const Right &right;
public:
	
	/**
	 * @brief Construct a new Matrix Mult object
	 * 
	 * @param l left
	 * @param r right
	 */
	MatrixMult(const Left &l, const Right &r) : left(l), right(r) {}
	//Okay, this needs a little explanation:
	//So n stands for row of the first matrix
	//m stands for the column of the first, and the row for the second
	//And last but not least, k is the column of the second matrix. K?
	/**
	 * @brief blabla
	 * 
	 * @param n row
	 * @param m row/col
	 * @param k col
	 * @return T Tea
	 */
	T operator() (int n, int m, int k) const {
		return left(n, m) * right(m, k);
	}
	//This made me mad tbh. 
	//In order to make MatrixMult * my_matrix work, you need to calculate the MatrixMult.
	/**
	 * @brief In order to make MatrixMult * my_matrix work, you need to calculate the MatrixMult.
	 * 
	 * @param n row
	 * @param m col
	 * @return T Tea
	 */
	T operator() (int n, int m) const {
		T leftMatriceValue = (T)0;
		//This calculates the values of the left matrix.
		for (int i = 0; i < K; ++i) {
			leftMatriceValue += left(n, i) * right(i, m);
		}
		
		return leftMatriceValue;
	}
	//Your turn, I forgot what that does.
	/**
	 * @brief Destroy the Matrix Mult object
	 * 
	 */
	~MatrixMult() {};
};

/**
 * @brief This is the main class.
 * 
 * @tparam T T
 * @tparam N row
 * @tparam M col
 */
template<class T, int N, int M>
/**
 * @brief asd
 * 
 */
class my_matrix : matrix_base {
	/**
	 * @brief This stores the actual data.
	 * 
	 */
	T data[N][M]; 
public:

	/**
	 * @brief That one does the Addition.
	 * 
	 * @tparam Left left
	 * @tparam Right right
	 * @param m Sum of the matrices.
	 * @return my_matrix<T, N, M>& returns a matrix.
	 */
	template<class Left, class Right>
	my_matrix<T, N, M>& operator=(const MatrixSum<T, N, M, Left, Right>& m) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				data[i][j] = m(i, j);
		return *this;
	}
	/**
	 * @brief That one does the Subtraction.
	 * 
	 * @tparam Left left
	 * @tparam Right right
	 * @param m Sub of the matrices.
	 * @return my_matrix<T, N, M>& returns a matrix.
	 */
	template<class Left, class Right>
	my_matrix<T, N, M>& operator=(const MatrixSub<T, N, M, Left, Right>& m) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				data[i][j] = m(i, j);
		return *this;
	}
	/**
	 * @brief That one does the Mult with const..
	 * 
	 * @tparam Left left
	 * @tparam Right right
	 * @param m Mult of the matrix and const.
	 * @return my_matrix<T, N, M>& returns a matrix.
	 */
	template<class Left, class Right>
	my_matrix<T, N, M>& operator=(const MatrixMultWithConstLeft<T, N, M, Left, Right>& m) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				data[i][j] = m(i, j);
		return *this;
	}
	/**
	 * @brief That one does the Mult with const..
	 * 
	 * @tparam Left left
	 * @tparam Right right
	 * @param m Mult of the matrix and const.
	 * @return my_matrix<T, N, M>& returns a matrix.
	 */
	template<class Left, class Right>
	my_matrix<T, N, M>& operator=(const MatrixMultWithConstRight<T, N, M, Left, Right>& m) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				data[i][j] = m(i, j);
		return *this;
	}
	//And the actual multiplication.
	/**
	 * @brief the actual multiplication.
	 * 
	 * @tparam K number of columns and rows
	 * @tparam Left left expr.
	 * @tparam Right right expr
	 * @param m the object of Matrix Mult
	 * @return my_matrix<T, N, M>& returns a matrix.
	 */
	template<int K, class Left, class Right>
	my_matrix<T, N, M>& operator=(const MatrixMult<T, N, K, M, Left, Right>  &m) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) {
				data[i][j] = (T)0;
				for (int l = 0; l < K; ++l) {
					data[i][j] += m(i,l, j); 
				}
			}
		return *this;
	}
	/**
	 * @brief This way you can reach the data.
	 * 
	 * @param n N
	 * @param m M
	 * @return const T& Tea
	 */
	const T& operator()(int n, int m) const { return data[n][m]; }
	/**
	 * @brief This way you can reach the data.
	 * 
	 * @param n N
	 * @param m M
	 * @return const T& Tea
	 */
	T& operator()(int n, int m) { return data[n][m]; }
};

/**
 * @brief Addition matrices.
 * 
 * @tparam T Tea
 * @tparam N En
 * @tparam M Em
 * @param l left
 * @param r right
 * @return auto returns with something.
 */
template<class T, int N, int M>
inline auto operator+(const my_matrix<T, N, M> &l, my_matrix<T, N, M> &r) {
	return MatrixSum<T, N, M, my_matrix<T, N, M>, my_matrix<T, N, M> >(l, r);
}

/**
 * @brief Addition matrices.
 * 
 * @tparam T Tea
 * @tparam N En
 * @tparam M Em
 * @param l left
 * @param r right
 * @return auto returns with something.
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator+(const MatrixSum<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSum<T, N, M, MatrixSum<T, N, M, Left, Right>, my_matrix<T, N, M> >(l, r);
}

/**
 * @brief Addition matrices.
 * 
 * @tparam T Tea
 * @tparam N En
 * @tparam M Em
 * @param l left
 * @param r right
 * @return auto returns with something.
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator+(const my_matrix<T, N, M> &l,const MatrixSum<T, N, M, Left, Right> &r) {
	return MatrixSum<T, N, M, my_matrix<T, N, M>, MatrixSum<T, N, M, Left, Right> >(l, r);
}

/**
 * @brief Something
 * 
 * @tparam T Tea
 * @tparam N Stonehenge
 * @tparam M Mmmm
 * @tparam Left1 left
 * @tparam Right1 right
 * @tparam Left2 left
 * @tparam Right2 right
 * @param l left
 * @param r right
 * @return auto returns with something.
 */
template<class T, int N, int M, class Left1, class Right1, class Left2, class Right2>
inline auto operator+(const MatrixSum<T, N, M, Left1, Right1> &l, const MatrixSum<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSum<T, N, M, Left1, Right1>, MatrixSum<T, N, M, Left2, Right2> >(l, r);
}

/**
 * @brief Something
 * 
 * @tparam T Tea
 * @tparam N Stonehenge
 * @tparam M Mmmm
 * @tparam Left1 left
 * @tparam Right1 right
 * @tparam Left2 left
 * @tparam Right2 right
 * @param l left
 * @param r right
 * @return auto returns with something.
 */
template<class T, int N, int M, class Left1, class Right1, class Left2, class Right2>
inline auto operator+(const MatrixSum<T, N, M, Left1, Right1> &l, const MatrixSub<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSum<T, N, M, Left1, Right1>, MatrixSub<T, N, M, Left2, Right2> >(l, r);
}

/**
 * @brief Something
 * 
 * @tparam T Tea
 * @tparam N Stonehenge
 * @tparam M Mmmm
 * @tparam Left1 left
 * @tparam Right1 right
 * @tparam Left2 left
 * @tparam Right2 right
 * @param l left
 * @param r right
 * @return auto returns with something.
 */
template<class T, int N, int M, class Left1, class Right1, class Left2, class Right2>
inline auto operator+(const MatrixSub<T, N, M, Left1, Right1> &l, const MatrixSum<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSub<T, N, M, Left1, Right1>, MatrixSum<T, N, M, Left2, Right2> >(l, r);
}

/**
 * @brief Something
 * 
 * @tparam T Tea
 * @tparam N Stonehenge
 * @tparam M Mmmm
 * @tparam Left1 left
 * @tparam Right1 right
 * @tparam Left2 left
 * @tparam Right2 right
 * @param l left
 * @param r right
 * @return auto returns with something.
 */
template<class T, int N, int M, class Left1, class Right1, class Left2, class Right2>
inline auto operator+(const MatrixSub<T, N, M, Left1, Right1> &l, const MatrixSub<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSub<T, N, M, Left1, Right1>, MatrixSub<T, N, M, Left2, Right2> >(l, r);
}
/**
 * @brief Something
 * 
 * @tparam T T
 * @tparam N N
 * @tparam M M
 * @tparam Left left 
 * @tparam Right Right
 * @param l l
 * @param r r
 * @return auto Honda.
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator+(const MatrixSub<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSum<T, N, M, MatrixSub<T, N, M, Left, Right>, my_matrix<T, N, M> >(l, r);
}

/**
 * @brief oh my oh my
 * 
 * @tparam T T
 * @tparam N N
 * @tparam M M
 * @tparam Left  l
 * @tparam Right r
 * @param l l
 * @param r e
 * @return auto auto 
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator+(my_matrix<T, N, M> &l, const MatrixSub<T, N, M, Left, Right> &r) {
	return MatrixSum<T, N, M, my_matrix<T, N, M>,  MatrixSub<T, N, M, Left, Right> >(l, r);
}
/**
 * @brief asd
 * 
 * @tparam T T
 * @tparam N n
 * @tparam M m
 * @tparam Left l
 * @tparam Right r
 * @param l l
 * @param r r
 * @return auto auto
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator+(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSum<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, my_matrix<T, N, M> >(l, r);
}

/**
 * @brief breif
 * 
 * @tparam T T
 * @tparam N r
 * @tparam M e
 * @tparam Left w
 * @tparam Right q
 * @param l w
 * @param r r
 * @return auto q
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator+(my_matrix<T, N, M> &l, const MatrixMultWithConstLeft<T, N, M, Left, Right> &r) {
	return MatrixSum<T, N, M, my_matrix<T, N, M>, MatrixMultWithConstLeft<T, N, M, Left, Right> >(l, r);
}

/**
 * @brief qwerty
 * 
 * @tparam T z
 * @tparam N uo
 * @tparam M p
 * @tparam Left a
 * @tparam Right s
 * @param l d
 * @param r f
 * @return auto g
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator+(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSum<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, my_matrix<T, N, M> >(l, r);
}

/**
 * @brief Whaddup
 * 
 * @tparam T s
 * @tparam N d
 * @tparam M f
 * @tparam Left g
 * @tparam Right h
 * @param l j
 * @param r k
 * @return auto l
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator+(my_matrix<T, N, M> &l, const MatrixMultWithConstRight<T, N, M, Left, Right> &r) {
	return MatrixSum<T, N, M, my_matrix<T, N, M>, MatrixMultWithConstRight<T, N, M, Left, Right> >(l, r);
}

/**
 * @brief ad
 * 
 * @tparam T y
 * @tparam N x
 * @tparam M c
 * @tparam Left v
 * @tparam Right b
 * @param l n
 * @param r m
 * @return auto m
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator+(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left, Right> &r) {
	return MatrixSum<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left, Right> >(l, r);
}

/**
 * @brief asd
 * 
 * @tparam T q
 * @tparam N w
 * @tparam M e
 * @tparam Left r
 * @tparam Right t
 * @tparam Left2 y
 * @tparam Right2 z
 * @param l u
 * @param r i
 * @return auto o
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left2, Right2> >(l, r);
}

/**
 * @brief sd
 * 
 * @tparam T sd
 * @tparam N sd
 * @tparam M sd
 * @tparam Left sd
 * @tparam Right sd
 * @tparam Left2 sd
 * @tparam Right2 sd
 * @param l sd
 * @param r sd
 * @return auto sd
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2> >(l, r);
}

/**
 * @brief xD
 * 
 * @tparam T xD
 * @tparam N xD
 * @tparam M xD
 * @tparam Left xD
 * @tparam Right xD
 * @tparam Left2 xD
 * @tparam Right2 xD
 * @param l xD
 * @param r xD
 * @return auto xD
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixSum<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSum<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2> >(l, r);
}

/**
 * @brief lol
 * 
 * @tparam T lol
 * @tparam N lol
 * @tparam M lol
 * @tparam Left lol
 * @tparam Right lol
 * @tparam Left2 lol
 * @tparam Right2 lol
 * @param l lol
 * @param r lol
 * @return auto lol
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixSum<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSum<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left2, Right2> >(l, r);
}

/**
 * @brief lol
 * 
 * @tparam T lol
 * @tparam N lol
 * @tparam M lol
 * @tparam Left lol
 * @tparam Right lol
 * @tparam Left2 lol
 * @tparam Right2 lol
 * @param l lol
 * @param r lol
 * @return auto lol
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2> >(l, r);
}

/**
 * @brief lol
 * 
 * @tparam T lol
 * @tparam N lol
 * @tparam M lol
 * @tparam Left lol
 * @tparam Right lol
 * @tparam Left2 lol
 * @tparam Right2 lol
 * @param l lol
 * @param r lol
 * @return auto lol
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixSub<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSub<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2> >(l, r);
}
/**
 * @brief lol
 * 
 * @tparam T lol
 * @tparam N lol
 * @tparam M lol
 * @tparam Left lol
 * @tparam Right lol
 * @tparam Left2 lol
 * @tparam Right2 lol
 * @param l lol
 * @param r lol
 * @return auto lol
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator+(const MatrixSub<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left2, Right2> &r) {
	return MatrixSum<T, N, M, MatrixSub<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left2, Right2> >(l, r);
}

/**
 * @brief lol
 * 
 * @tparam T lol
 * @tparam N lol
 * @tparam M lol
 * @tparam K lol
 * @tparam E lol
 * @tparam Right lol
 * @tparam Left2 lol
 * @tparam Right2 lol
 * @param l lol
 * @param r lol
 * @return auto lol
 */
template<class T, int N, int M, int K, int E, class Right, class Left2, class Right2>
inline auto operator+(const MatrixMultWithConstLeft<T, N, M, T, Right> &l, const MatrixMult<T, N, K, E, Left2, Right2> &r) {
	return MatrixSum<T, N, E, MatrixMultWithConstLeft<T, N, M, T, Right>, MatrixMult<T, N, K, E, Left2, Right2> >(l, r);
}

/**
 * @brief we're on easy street
 * 
 * @tparam T x
 * @tparam N x
 * @tparam M x
 * @tparam K x
 * @tparam E x
 * @tparam Right x
 * @tparam Left2 x
 * @tparam Right2 x
 * @param l x
 * @param r x
 * @return auto x
 */
template<class T, int N, int M, int K, int E, class Right, class Left2, class Right2>
inline auto operator+(const MatrixMultWithConstRight<T, N, M, T, Right> &l, const MatrixMult<T, N, K, E, Left2, Right2> &r) {
	return MatrixSum<T, N, E, MatrixMultWithConstRight<T, N, M, T, Right>, MatrixMult<T, N, K, E, Left2, Right2> >(l, r);
}

/**
 * @brief x
 * 
 * @tparam T x
 * @tparam N x
 * @tparam M x
 * @tparam K x
 * @tparam Left x
 * @tparam Right x
 * @tparam Right2 x
 * @param l x
 * @param r x
 * @return auto x
 */
template<class T, int N, int M, int K, class Left, class Right, class Right2>
inline auto operator+(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixMultWithConstLeft<T,  M, K,  T, Right2> &r) {
	return MatrixSum<T, N, K, MatrixMult<T, N, M, K, Left, Right>, MatrixMultWithConstLeft<T, M, K, T, Right2> >(l, r);
}

/**
 * @brief x
 * 
 * @tparam T x
 * @tparam N x
 * @tparam M x
 * @tparam K x
 * @tparam Left x
 * @tparam Right x
 * @tparam Left2 x
 * @param l c
 * @param r c
 * @return auto c
 */
template<class T, int N, int M, int K, class Left, class Right, class Left2>
inline auto operator+(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixMultWithConstRight<T, M, K, Left2, T> &r) {
	return MatrixSum<T, N, K, MatrixMult<T, N, M, K, Left, Right>, MatrixMultWithConstRight<T, M, K, Left2, T> >(l, r);
}

/**
 * @brief c
 * 
 * @tparam T c
 * @tparam N c
 * @tparam M c
 * @tparam K c
 * @tparam Left c
 * @tparam Right c
 * @param l c
 * @param r c
 * @return auto c
 */
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator+(const MatrixMult<T, N, M, K, Left, Right> &l, const my_matrix<T, N, K> &r) {
	return MatrixSum<T, N, K, MatrixMult<T, N, M, K, Left, Right>, my_matrix<T, N, K> >(l, r);
}

/**
 * @brief v
 * 
 * @tparam T v
 * @tparam N v
 * @tparam M v
 * @tparam K v
 * @tparam Left v
 * @tparam Right v
 * @param l v
 * @param r vv
 * @return auto v
 */
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator+(const my_matrix<T, N, K> &l, const MatrixMult<T, N, M, K, Left, Right> &r) {
	return MatrixSum<T, N, K, my_matrix<T, N, K>, MatrixMult<T, N, M, K, Left, Right> >(l, r);
}


//This is getting annoying now...
/**
 * @brief v
 * 
 * @tparam T v
 * @tparam N b
 * @tparam M b
 * @param l b
 * @param r b
 * @return auto b
 */
template<class T, int N, int M>
inline auto operator-(const my_matrix<T, N, M> &l, my_matrix<T, N, M> &r) {
	return MatrixSub<T, N, M, my_matrix<T, N, M>, my_matrix<T, N, M> >(l, r);
}

/**
 * @brief b
 * 
 * @tparam T b
 * @tparam N b
 * @tparam M b
 * @tparam Left b
 * @tparam Right b
 * @param l b
 * @param r b
 * @return auto b
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator-(const MatrixSub<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSub<T, N, M, MatrixSub<T, N, M, Left, Right>, my_matrix<T, N, M> >(l, r);
}

/**
 * @brief n
 * 
 * @tparam T n
 * @tparam N n
 * @tparam M n
 * @tparam Left n
 * @tparam Right n
 * @param l n
 * @param r n
 * @return auto n
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator-(const my_matrix<T, N, M> &l, const MatrixSub<T, N, M, Left, Right> &r) {
	return MatrixSub<T, N, M, my_matrix<T, N, M>, MatrixSub<T, N, M, Left, Right> >(l, r);
}

//His palms are sweaty, knees week, arms are heavy...
/**
 * @brief n
 * 
 * @tparam T n
 * @tparam N n
 * @tparam M n
 * @tparam Left n
 * @tparam Right n
 * @tparam Left2 n
 * @tparam Right2 n
 * @param l n
 * @param r n
 * @return auto n
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixSub<T, N, M, Left, Right> &l, const MatrixSub<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixSub<T, N, M, Left, Right>, MatrixSub<T, N, M, Left2, Right2> >(l, r);
}

//It does what it does
/**
 * @brief m
 * 
 * @tparam T m
 * @tparam N m
 * @tparam M m
 * @tparam Left m
 * @tparam Right m
 * @param l m
 * @param r m
 * @return auto m
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator-(const MatrixSum<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSub<T, N, M, MatrixSum<T, N, M, Left, Right>, my_matrix<T, N, M> >(l, r);
}

//Why can't a tyranosaurus clap? :O
/**
 * @brief a
 * 
 * @tparam T a
 * @tparam N a
 * @tparam M a
 * @tparam Left a
 * @tparam Right a
 * @param l a
 * @param r a
 * @return auto a
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator-(my_matrix<T, N, M> &l,  const MatrixSum<T, N, M, Left, Right> &r) {
	return MatrixSub<T, N, M, my_matrix<T, N, M>,  MatrixSum<T, N, M, Left, Right> >(l, r);
}

//It's extinct. LOL.
/**
 * @brief q
 * 
 * @tparam T q
 * @tparam N q
 * @tparam M q
 * @tparam Left q
 * @tparam Right q
 * @tparam Left2 q
 * @tparam Right2 q
 * @param l q
 * @param r q
 * @return auto q
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixSum<T, N, M, Left, Right> &l, const MatrixSum<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixSum<T, N, M, Left, Right>, MatrixSum<T, N, M, Left2, Right2> >(l, r);
}

//What stays in the corner, but travels all over the world?
/**
 * @brief w
 * 
 * @tparam T w
 * @tparam N w
 * @tparam M w
 * @tparam Left w
 * @tparam Right w
 * @tparam Left2 w
 * @tparam Right2 w
 * @param l w
 * @param r w
 * @return auto w
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixSum<T, N, M, Left, Right> &l, const MatrixSub<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixSum<T, N, M, Left, Right>, MatrixSub<T, N, M, Left2, Right2> >(l, r);
}

//A stamp.
/**
 * @brief e
 * 
 * @tparam T e
 * @tparam N ee
 * @tparam M e
 * @tparam Left e
 * @tparam Right e
 * @tparam Left2 e
 * @tparam Right2 e
 * @param l e
 * @param r e
 * @return auto e
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixSub<T, N, M, Left, Right> &l, const MatrixSum<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixSub<T, N, M, Left, Right>, MatrixSum<T, N, M, Left2, Right2> >(l, r);
}

//Just a lonely comment.
/**
 * @brief x
 * 
 * @tparam T x
 * @tparam N x
 * @tparam M x
 * @tparam Left x
 * @tparam Right x
 * @param l x
 * @param r x
 * @return auto x
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator-(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, my_matrix<T, N, M> >(l, r);
}
//Could you recommend some good shows?
/**
 * @brief d
 * 
 * @tparam T d
 * @tparam N d
 * @tparam M d
 * @tparam Left d
 * @tparam Right d
 * @param l d
 * @param r d
 * @return auto d
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator-(my_matrix<T, N, M> &l, const MatrixMultWithConstLeft<T, N, M, Left, Right> &r) {
	return MatrixSub<T, N, M, my_matrix<T, N, M>, MatrixMultWithConstLeft<T, N, M, Left, Right> >(l, r);
}

//I'm out of series on Netflix.
/**
 * @brief e
 * 
 * @tparam T e
 * @tparam N e
 * @tparam M e
 * @tparam Left e
 * @tparam Right e
 * @param l e
 * @param r e
 * @return auto e
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator-(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, my_matrix<T, N, M> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, my_matrix<T, N, M> >(l, r);
}
//Wanna hear a joke?
/**
 * @brief e
 * 
 * @tparam T e
 * @tparam N e
 * @tparam M e
 * @tparam Left e
 * @tparam Right e
 * @param l e
 * @param r e
 * @return auto e
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator-(my_matrix<T, N, M> &l, const MatrixMultWithConstRight<T, N, M, Left, Right> &r) {
	return MatrixSub<T, N, M, my_matrix<T, N, M>, MatrixMultWithConstRight<T, N, M, Left, Right> >(l, r);
}
//No?
/**
 * @brief e
 * 
 * @tparam T r
 * @tparam N t
 * @tparam M t
 * @tparam Left t
 * @tparam Right t
 * @param l t
 * @param r t
 * @return auto t
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator-(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left, Right> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left, Right> >(l, r);
}
//Okay, whatever.
/**
 * @brief e
 * 
 * @tparam T w
 * @tparam N e
 * @tparam M w
 * @tparam Left e
 * @tparam Right w
 * @tparam Left2 e
 * @tparam Right2 w
 * @param l e
 * @param r w
 * @return auto e
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left2, Right2> >(l, r);
}
//Q. What's the difference between a hippo and a Zippo?
/**
 * @brief e
 * 
 * @tparam T e
 * @tparam N r
 * @tparam M e
 * @tparam Left w
 * @tparam Right q
 * @tparam Left2 w
 * @tparam Right2 wq
 * @param l wq
 * @param r wq
 * @return auto qw
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2> >(l, r);
}
//A.A hippo is really heavy, and a Zippo is a little lighter.
/**
 * @brief we
 * 
 * @tparam T we
 * @tparam N we
 * @tparam M we
 * @tparam Left we
 * @tparam Right we
 * @tparam Left2 we
 * @tparam Right2 we
 * @param l ew
 * @param r ew
 * @return auto ew
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixSub<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixSub<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2> >(l, r);
}
//Yada yada yada
/**
 * @brief ew
 * 
 * @tparam T ew
 * @tparam N ew
 * @tparam M ew
 * @tparam Left ew
 * @tparam Right ew
 * @tparam Left2 ew
 * @tparam Right2 ew
 * @param l 
 * @param r 
 * @return auto r
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixSub<T, N, M, Left, Right> &l, const MatrixMultWithConstRight<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixSub<T, N, M, Left, Right>, MatrixMultWithConstRight<T, N, M, Left2, Right2> >(l, r);
}
//F is for Family season 3 comes out on 30th of November.
/**
 * @brief q
 * 
 * @tparam T e
 * @tparam N w
 * @tparam M we
 * @tparam Left ew
 * @tparam Right ew
 * @tparam Left2 eww
 * @tparam Right2 ew
 * @param l ew
 * @param r ew
 * @return auto ew
 */
template<class T, int N, int M, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, const MatrixMultWithConstLeft<T, N, M, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, MatrixMultWithConstLeft<T, N, M, Left2, Right2> >(l, r);
}

//What do you call an old snowman?
/**
 * @brief q
 * 
 * @tparam T we
 * @tparam N ew
 * @tparam M ewe
 * @tparam K ew
 * @tparam Left ew
 * @tparam Right ew
 * @tparam Left2 ew
 * @tparam Right2 ew
 * @param l ew
 * @param r ew
 * @return auto w
 */
template<class T, int N, int M, int K, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, const MatrixMult<T, N, M, K, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstLeft<T, N, M, Left, Right>, MatrixMult<T, N, M, K, Left2, Right2> >(l, r);
}

//Water.
/**
 * @brief w
 * 
 * @tparam T w
 * @tparam N w
 * @tparam M w
 * @tparam K w
 * @tparam Left w
 * @tparam Right w
 * @tparam Left2 w
 * @tparam Right2 w
 * @param l w
 * @param r w
 * @return auto w
 */
template<class T, int N, int M, int K, class Left, class Right, class Left2, class Right2>
inline auto operator-(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, const MatrixMult<T, N, M, K, Left2, Right2> &r) {
	return MatrixSub<T, N, M, MatrixMultWithConstRight<T, N, M, Left, Right>, MatrixMult<T, N, M, K, Left2, Right2> >(l, r);
}

//Multiplication of matrices
//You should really check it out. F is for family I mean.
/**
 * @brief q
 * 
 * @tparam T w
 * @tparam N e
 * @tparam M r
 * @tparam K t
 * @param l z
 * @param r y
 * @return auto x
 */
template<class T, int N, int M, int K>
inline auto operator*(const my_matrix<T, N, M> &l, my_matrix<T, M, K> &r) {
	return MatrixMult<T, N, M, K, my_matrix<T, N, M>, my_matrix<T, M, K> >(l, r);
}

//It's like one of the best dramedies I've seen.
/**
 * @brief q
 * 
 * @tparam T w
 * @tparam N w
 * @tparam M e
 * @tparam K e
 * @tparam Left e
 * @tparam Right e
 * @param l ww
 * @param r ww
 * @return auto ee
 */
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const MatrixSum<T,N,M, Left, Right> &l, my_matrix<T, M, K> &r) {
	return MatrixMult<T, N, M, K, MatrixSum<T, N, M, Left, Right>, my_matrix<T, M, K> >(l, r);
	
}

//What gets wetter as it dries?
/**
 * @brief q
 * 
 * @tparam T w
 * @tparam N e
 * @tparam M r
 * @tparam K t
 * @tparam Left w
 * @tparam Right q
 * @param l e
 * @param r r
 * @return auto t
 */
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const my_matrix<T, N, M> &l, const MatrixSum<T, M, K, Left, Right>  &r) {
	return MatrixMult<T, N, M, K, my_matrix<T, N, M>, MatrixSum<T, M, K, Left, Right> >(l, r);
}

//A towel.
/**
 * @brief q
 * 
 * @tparam T w
 * @tparam N e
 * @tparam M r
 * @tparam K t
 * @tparam Left y
 * @tparam Right y
 * @tparam Left2 yy
 * @tparam Right2 yy
 * @param l yyy
 * @param r yy
 * @return auto y 
 */
template<class T, int N, int M, int K, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixSum<T, N, M, Left, Right> &l, const MatrixSum<T, M, K, Left2, Right2> &r) {
	return MatrixMult<T, N, M, K, MatrixSum<T, N, M, Left, Right>, MatrixSum<T, M, K, Left2, Right2> >(l, r);
}

//What's harder to catch the faster you run?
/**
 * @brief a
 * 
 * @tparam T s
 * @tparam N s
 * @tparam M s
 * @tparam K s
 * @tparam Left e
 * @tparam Right e
 * @tparam Left2 e
 * @tparam Right2 w
 * @param l q
 * @param r w
 * @return auto e
 */
template<class T, int N, int M, int K, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixSum<T, N, M, Left, Right> &l, const MatrixSub<T, M, K, Left2, Right2> &r) {
	return MatrixMult<T, N, M, K, MatrixSum<T, N, M, Left, Right>, MatrixSub<T, M, K, Left2, Right2> >(l, r);
}

//Your breath.
/**
 * @brief w
 * 
 * @tparam T w
 * @tparam N w
 * @tparam M w
 * @tparam K w
 * @tparam Left w
 * @tparam Right w
 * @param l w
 * @param r w
 * @return auto w
 */
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const MatrixSub<T, N, M, Left, Right> &l, my_matrix<T, M, K> &r) {
	return MatrixMult<T, N, M, K, MatrixSub<T, N, M, Left, Right>, my_matrix<T, M, K> >(l, r);
}

//What has a head and a tail, but no legs?
/**
 * @brief w
 * 
 * @tparam T q
 * @tparam N w
 * @tparam M e
 * @tparam K q
 * @tparam Left q
 * @tparam Right q
 * @param l w
 * @param r w
 * @return auto w
 */
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const my_matrix<T, N, M> &l, const MatrixSub<T, M, K, Left, Right>  &r) {
	return MatrixMult<T, N, M, K, my_matrix<T, N, M>, MatrixSub<T, M, K, Left, Right> >(l, r);
}

//A penny.
/**
 * @brief q
 * 
 * @tparam T w
 * @tparam N e
 * @tparam M r
 * @tparam K tq
 * @tparam Left qq
 * @tparam Right q
 * @tparam Left2 q
 * @tparam Right2 q
 * @param l q
 * @param r q
 * @return auto q
 */
template<class T, int N, int M, int K, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixSub<T, N, M, Left, Right> &l, const MatrixSum<T, M, K, Left2, Right2> &r) {
	return MatrixMult<T, N, M, K, MatrixSub<T, N, M, Left, Right>, MatrixSum<T, M, K, Left2, Right2> >(l, r);
}

//The fear of Halloween is called "samhainophobia".
/**
 * @brief q
 * 
 * @tparam T q
 * @tparam N q
 * @tparam M q
 * @tparam K q
 * @tparam Left q
 * @tparam Right q
 * @tparam Left2 q
 * @tparam Right2 q
 * @param l q
 * @param r q
 * @return auto q
 */
template<class T, int N, int M, int K, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixSub<T, N, M, Left, Right> &l, const MatrixSub<T, M, K, Left2, Right2> &r) {
	return MatrixMult<T, N, M, K, MatrixSub<T, N, M, Left, Right>, MatrixSub<T, M, K, Left2, Right2> >(l, r);
}

//Okay this might need a little explanation.
//N stands for the first Mult's rows.
//M stands for the first Mult's columns
//K stands for the Mult's right coluns.
//E stands for the my_matrix's columns.
/**
 * @brief q
 * 
 * @tparam T q
 * @tparam N q
 * @tparam M q
 * @tparam K q
 * @tparam E q
 * @tparam Left q
 * @tparam Right q
 * @param l q
 * @param r q
 * @return auto q
 */
template<class T, int N, int M, int K, int E, class Left, class Right>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, my_matrix<T, K, E> &r) {
	return MatrixMult<T, N, K, E, MatrixMult<T, N, M, K, Left, Right>, my_matrix<T, K, E> >(l, r);
}

//How many books can you put into an empty backpack?
/**
 * @brief a
 * 
 * @tparam T a
 * @tparam N aa
 * @tparam M a
 * @tparam K a
 * @tparam E a
 * @tparam Left a
 * @tparam Right a
 * @tparam Left2 a
 * @tparam Right2 a
 * @param l a
 * @param r a
 * @return auto a
 */
template<class T, int N, int M, int K, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixSum<T, K, E, Left2, Right2> &r) {
	return MatrixMult<T, N, K, E, MatrixMult<T, N, M, K, Left, Right>, MatrixSum<T, K, E, Left2, Right2> >(l, r);
}

//One! After that it's not empty.
/**
 * @brief a
 * 
 * @tparam T a
 * @tparam N a
 * @tparam M a
 * @tparam K a
 * @tparam E a
 * @tparam Left a
 * @tparam Right a
 * @tparam Left2 a
 * @tparam Right2 a
 * @param l a
 * @param r a
 * @return auto a
 */
template<class T, int N, int M, int K, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixSub<T, K, E, Left2, Right2> &r) {
	return MatrixMult<T, N, K, E, MatrixMult<T, N, M, K, Left, Right>, MatrixSub<T, K, E, Left2, Right2> >(l, r);;
}

//balrol valo szorzas
/**
 * @brief a
 * 
 * @tparam T a
 * @tparam N a
 * @tparam M aa
 * @tparam K a
 * @tparam E a
 * @tparam Left a
 * @tparam Right a
 * @param l a
 * @param r a
 * @return auto a
 */
template<class T, int N, int M, int K, int E, class Left, class Right>
inline auto operator*(my_matrix<T, N, M> &l, const MatrixMult<T, M, K, E, Left, Right> &r) {
	return MatrixMult<T, N, M, E, my_matrix<T, N, M>, MatrixMult<T, M, K, E, Left, Right> >(l, r);;
}
//summal valo balrol szorzas.
/**
 * @brief q
 * 
 * @tparam T w
 * @tparam N r
 * @tparam M e
 * @tparam K r
 * @tparam E r
 * @tparam Left r
 * @tparam Right r
 * @tparam Left2 r
 * @tparam Right2 r
 * @param l r
 * @param r r
 * @return auto r
 */
template<class T, int N, int M, int K, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixSum<T, N, M, Left, Right> &l, const MatrixMult<T, M, K, E, Left2, Right2> &r) {
	return MatrixMult<T, N, M, E, MatrixSum<T, N, M, Left, Right>, MatrixMult<T, M, K, E, Left2, Right2> >(l, r);;
}

//subbal valo balrol szorzas.
/**
 * @brief r
 * 
 * @tparam T r
 * @tparam N r
 * @tparam M r
 * @tparam K r
 * @tparam E r
 * @tparam Left r
 * @tparam Right r
 * @tparam Left2 r
 * @tparam Right2 r
 * @param l r
 * @param r r
 * @return auto r
 */
template<class T, int N, int M, int K, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixSub<T, N, M, Left, Right> &l, const MatrixMult<T, M, K, E, Left2, Right2> &r) {
	return MatrixMult<T, N, M, E, MatrixSub<T, N, M, Left, Right>, MatrixMult<T, M, K, E, Left2, Right2> >(l, r);;
}
//MatrixLeftConsttal szorzas matrixra.
/**
 * @brief r
 * 
 * @tparam T r
 * @tparam N r
 * @tparam M r
 * @tparam K r
 * @tparam Left r
 * @tparam Right r
 * @param l r
 * @param r r
 * @return auto r
 */
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const MatrixMultWithConstLeft<T, N, M, Left, Right> &l, my_matrix<T, M, K> &r) {
	return MatrixMult<T, N, M, K, MatrixMultWithConstLeft<T, N, M, Left, Right>, my_matrix<T, M, K> >(l, r);
}
//MatrixRightConsttal szorzas matrixra.
/**
 * @brief r
 * 
 * @tparam T r
 * @tparam N r
 * @tparam M r
 * @tparam K r
 * @tparam Left r
 * @tparam Right q
 * @param l q
 * @param r q
 * @return auto q
 */
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const MatrixMultWithConstRight<T, N, M, Left, Right> &l, my_matrix<T, M, K> &r) {
	return MatrixMult<T, N, M, K, MatrixMultWithConstRight<T, N, M, Left, Right>, my_matrix<T, M, K> >(l, r);
}

//MatrixLeftConsttal szorzas matrixra.
/**
 * @brief q
 * 
 * @tparam T q
 * @tparam N q
 * @tparam M q
 * @tparam K q
 * @tparam Left q
 * @tparam Right q
 * @param l q
 * @param r q
 * @return auto q
 */
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const my_matrix<T, N, M >  &l,  const MatrixMultWithConstLeft<T, M, K, Left, Right> &r) {
	return MatrixMult<T, N, M, K, my_matrix<T, N, M>, MatrixMultWithConstLeft<T, M, K, Left, Right> >(l, r);
}
//MatrixLeftConsttal szorzas matrixra.
/**
 * @brief q
 * 
 * @tparam T q
 * @tparam N q
 * @tparam M q
 * @tparam K q
 * @tparam Left q
 * @tparam Right q
 * @param l q
 * @param r q
 * @return auto q
 */
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const my_matrix<T, N,M>  &l, const MatrixMultWithConstRight<T, M, K, Left, Right> &r) {
	return MatrixMult<T, N, M, K, my_matrix<T, N,M>, MatrixMultWithConstRight<T, M ,K, Left, Right> >(l, r);
}

//The first therapy dog was a Yorkshire Terrier named Smoky,
/**
 * @brief q
 * 
 * @tparam T q
 * @tparam N q
 * @tparam M q
 * @tparam K q
 * @tparam E q
 * @tparam Left q
 * @tparam Right q
 * @tparam Left2 q
 * @tparam Right2 q
 * @param l q
 * @param r q
 * @return auto q
 */
template<class T, int N, int M, int K, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixMultWithConstLeft<T, K, E, Left2, Right2> &r) {
	return MatrixMult<T, N, K, E, MatrixMult<T, N, M, K, Left, Right>, MatrixMultWithConstLeft<T, K, E, Left2, Right2> >(l, r);;
}

//helping wounded soldiers during World War II.
/**
 * @brief q
 * 
 * @tparam T q
 * @tparam N q
 * @tparam M q
 * @tparam K q
 * @tparam E q
 * @tparam Left w
 * @tparam Right w
 * @tparam Left2 w
 * @tparam Right2 w
 * @param l w
 * @param r ww
 * @return auto w
 */
template<class T, int N, int M, int K, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixMultWithConstRight<T, K, E, Left2, Right2> &r) {
	return MatrixMult<T, N, K, E, MatrixMult<T, N, M, K, Left, Right>, MatrixMultWithConstRight<T, K, E, Left2, Right2> >(l, r);;
}

//After the war, she performed on various TV shows.
/**
 * @brief w
 * 
 * @tparam T w
 * @tparam N e
 * @tparam M r
 * @tparam K r
 * @tparam F r
 * @tparam E r
 * @tparam Left rr
 * @tparam Right r
 * @tparam Left2 r
 * @tparam Right2 r
 * @param l r
 * @param r r
 * @return auto r
 */
template<class T, int N, int M, int K, int F, int E, class Left, class Right, class Left2, class Right2>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, const MatrixMult < T, K, F, E, Left2, Right2> &r) {
	return MatrixMult<T, N, K, E, MatrixMult<T, N, M, K, Left, Right>, MatrixMult<T, K, F, E, Left2, Right2> >(l, r);;
}

//Multiplication of matrice and a constant
/**
 * @brief q
 * 
 * @tparam T q
 * @tparam N q
 * @tparam M q
 * @param l w
 * @param r w
 * @return auto w
 */
template<class T, int N, int M>
inline auto operator*(const my_matrix<T, N, M> &l, const T &r) {
	return MatrixMultWithConstRight<T, N, M, my_matrix<T, N, M>, T>(l, r);
}

//The combined strength of all the hair on a human head could support two elephants.
/**
 * @brief w
 * 
 * @tparam T e
 * @tparam N e
 * @tparam M e
 * @tparam Left e
 * @param l e
 * @param r e
 * @return auto e
 */
template<class T, int N, int M, class Left>
inline auto operator*(const MatrixMultWithConstRight<T, N, M, Left, T> &l, const T &r) {
	return MatrixMultWithConstRight<T, N, M, MatrixMultWithConstRight<T, N, M, Left, T>, T>(l, r);
}

//What's the snake's favourite subject?
/**
 * @brief e
 * 
 * @tparam T e
 * @tparam N e
 * @tparam M e
 * @tparam Left 3
 * @tparam Right e
 * @param l e
 * @param r e
 * @return auto e
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator*(const MatrixSum<T, N, M, Left, Right> &l, const T &r) {
	return MatrixMultWithConstRight<T, N, M, MatrixSum<T, N, M, Left, Right>, T>(l, r);
}

//Hiss-story.
/**
 * @brief r
 * 
 * @tparam T r
 * @tparam N r
 * @tparam M r
 * @tparam Left r
 * @tparam Right r
 * @param l r
 * @param r r
 * @return auto r
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator*(const MatrixSub<T, N, M, Left, Right> &l, const T &r) {
	return MatrixMultWithConstRight<T, N, M, MatrixSub<T, N, M, Left, Right>, T>(l, r);
}

//Why couldn't the leopard play hide and seek?
/**
 * @brief a
 * 
 * @tparam T a
 * @tparam N a
 * @tparam M a
 * @tparam K a
 * @tparam Left a
 * @tparam Right a
 * @param l a
 * @param r a
 * @return auto a
 */
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const MatrixMult<T, N, M, K, Left, Right> &l, const T &r) {
	return MatrixMultWithConstRight<T, N, K, MatrixMult<T, N, M, K, Left, Right> ,T>(l, r);
}

//Cuz it was always spotted.
/**
 * @brief a
 * 
 * @tparam T a
 * @tparam N a
 * @tparam M a
 * @tparam Right aa
 * @param l a
 * @param r a
 * @return auto a
 */
template<class T, int N, int M, class Right>
inline auto operator*(const MatrixMultWithConstLeft<T, N, M, T, Right> &l, const T &r) {
	return MatrixMultWithConstRight<T, N, M, MatrixMultWithConstLeft<T, N, M, T, Right>, T>(l, r);
}

//Multiplication of constant and a matrice
/**
 * @brief a
 * 
 * @tparam T a
 * @tparam N a
 * @tparam M a
 * @param l a
 * @param r a
 * @return auto a
 */
template<class T, int N, int M>
inline auto operator*(const T &l, const my_matrix<T, N, M> &r) {
	return MatrixMultWithConstLeft<T, N, M, T, my_matrix<T, N, M> >(l, r);
}

//What goes up, but never comes down?
/**
 * @brief a
 * 
 * @tparam T a
 * @tparam N a
 * @tparam M aa
 * @tparam Right a
 * @param l a
 * @param r a
 * @return auto a
 */
template<class T, int N, int M, class Right>
inline auto operator*(const T &l, const MatrixMultWithConstLeft<T, N, M, T, Right> &r) {
	return MatrixMultWithConstLeft<T, N, M, T, MatrixMultWithConstLeft<T, N, M, T, Right> >(l, r);
}

//Your age. 
/**
 * @brief a
 * 
 * @tparam T a
 * @tparam N a
 * @tparam M a
 * @tparam Left a
 * @tparam Right a
 * @param l a
 * @param r a
 * @return auto a
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator*(const T &l, const MatrixSum<T, N, M, Left, Right> &r) {
	return MatrixMultWithConstLeft<T, N, M, T, MatrixSum<T, N, M, Left, Right> >(l, r);
}

//LoL, gotti.
/**
 * @brief w
 * 
 * @tparam T w
 * @tparam N w
 * @tparam M w
 * @tparam Left w
 * @tparam Right w
 * @param l w
 * @param r w
 * @return auto w
 */
template<class T, int N, int M, class Left, class Right>
inline auto operator*(const T &l, const MatrixSub<T, N, M, Left, Right> &r) {
	return MatrixMultWithConstLeft<T, N, M, T, MatrixSub<T, N, M, Left, Right> >(l, r);
}

//Okay I should really write useful comments now.
/**
 * @brief r
 * 
 * @tparam T r
 * @tparam N r
 * @tparam M r
 * @tparam K r
 * @tparam Left r
 * @tparam Right r
 * @param l r
 * @param r r
 * @return auto r
 */
template<class T, int N, int M, int K, class Left, class Right>
inline auto operator*(const T &l, const MatrixMult<T, N, M, K, Left, Right> &r) {
	return MatrixMultWithConstLeft<T, N, K, T, MatrixMult<T, N, M, K, Left, Right> >(l, r);
}

//This is a multiplication of a Constant and the MultwithConstant.
/**
 * @brief r
 * 
 * @tparam T t
 * @tparam N t
 * @tparam M t
 * @tparam Left t
 * @param l t
 * @param r t
 * @return auto t
 */
template<class T, int N, int M, class Left>
inline auto operator*(const T &l, const MatrixMultWithConstRight<T, N, M, Left, T> &r) {
	return MatrixMultWithConstLeft<T, N, M, T, MatrixMultWithConstRight<T, N, M, Left, T> >(l, r);
}