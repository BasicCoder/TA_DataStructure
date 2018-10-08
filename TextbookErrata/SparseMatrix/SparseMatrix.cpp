# define MaxTerms 100
template <class Type> 
class SparseMatrix; //教材中前向引用声明错误，去掉 <Type>

template <class Type> 
class Trituple{
	friend class SparseMatrix <Type>;
	private:
		int row, col;
		Type data;
};
template <class Type> 
class SparseMatrix {
	public:		
		SparseMatrix(int MaxRow, int MaxCol){};
	private:
		int Rows, Cols, NonZero_Terms;
		Trituple <Type> SMArray[MaxTerms];
};

int main(){
	SparseMatrix<int> M(10, 10);
	return 0;
}
