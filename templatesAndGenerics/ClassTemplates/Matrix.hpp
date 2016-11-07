
template<class T>
class Matrix
{
public:
	Matrix(T m11_, T m12_, T m21_, T m22_);
	Matrix(T matrix[2][2]);
	Matrix();

	~Matrix() = default;

	Matrix add(Matrix m);
	Matrix multiply(Matrix m);
	void print();

	T getElement(int row, int column)
	{
		return matrix_[row][column];
	}

	void setElement(int row, int column, T element)
	{
		matrix_[row][column] = element;
	}

private:
	T matrix_[2][2];
	std::pair<int,int> ref = {0xffff, 0xffff};
};

template<class T>
Matrix<T>::Matrix(T m11, T m12, T m21, T m22)
{
	matrix_[0][0] =  m11;
	matrix_[0][1] =  m12;
	matrix_[1][0] =  m21;
	matrix_[1][1] =  m22;
}

template<class T>
Matrix<T>::Matrix(T matrix[2][2])
{
	matrix_[0][0] = matrix.getElement(0,0);
	matrix_[0][1] = matrix.getElement(0,1);
	matrix_[1][0] = matrix.getElement(1,0);
	matrix_[1][1] = matrix.getElement(1,1);
}

template<class T>
Matrix<T>::Matrix()
{
	matrix_[0][0] = 0;
	matrix_[0][1] = 0;
	matrix_[1][0] = 0;
	matrix_[1][1] = 0;
}

template<class T>
Matrix<T> Matrix<T>::add(Matrix<T> matrix)
{
	Matrix<T> sum;
	sum.setElement(0, 0 , matrix_[0][0] + matrix.getElement(0,0));
	sum.setElement(0, 1 , matrix_[0][1] + matrix.getElement(0,1));
	sum.setElement(1, 0 , matrix_[1][0] + matrix.getElement(1,0));
	sum.setElement(1, 1 , matrix_[1][1] + matrix.getElement(1,1));

	return sum;
}

template<class T>
Matrix<T> Matrix<T>::multiply(Matrix<T> matrix)
{
	Matrix<T> prod;
	prod.setElement(0, 0, (matrix_[0][0] * matrix.getElement(0,0) + matrix_[0][1] * matrix.getElement(1,0)));
	prod.setElement(0, 1, (matrix_[0][0] * matrix.getElement(0,1) + matrix_[0][1] * matrix.getElement(1,1)));
	prod.setElement(1, 0, (matrix_[1][0] * matrix.getElement(0,0) + matrix_[1][1] * matrix.getElement(1,0)));
	prod.setElement(1, 1, (matrix_[1][0] * matrix.getElement(0,1) + matrix_[1][1] * matrix.getElement(1,1)));

	return prod;
}

template<class T>
void Matrix<T>::print()
{
	std::cout << "|" << matrix_[0][0] << " " << matrix_[0][1] << "|" << std::endl;
	std::cout << "|" << matrix_[1][0] << " " << matrix_[1][1] << "|" << std::endl;
	std::cout << std::endl;
}
