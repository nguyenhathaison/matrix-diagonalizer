#include <iostream>
#include <utility>

struct TwoByTwoMatrix
{
	int a{};
	int b{};
	int c{};
	int d{};
};

void getUserInputForMatrix(TwoByTwoMatrix& matrix)
{
	// Form of matrix
	std::cout << "Given a 2x2 matrix of the form:\n";
	std::cout << "[ " << 'a' << ' ' << 'b' << " ]\n";
	std::cout << "[ " << 'c' << ' ' << 'd' << " ]\n";

	std::cin >> matrix.a;
	std::cin >> matrix.b;
	std::cin >> matrix.c;
	std::cin >> matrix.d;
}

std::ostream& operator<<(std::ostream& out, const TwoByTwoMatrix& matrix)
{
	out << "\nThe inputted matrix is: \n";
	out << matrix.a << '\t' << matrix.b << '\n';
	out << matrix.c << '\t' << matrix.d << '\n';

	return out;
}

int findDeterminantOfMatrix(int a, int b, int c, int d)
{
	return a * c - b * d;
}

int main()
{
	// Initialize the a 2x2 matrix 
	TwoByTwoMatrix matrix{};


	

	// Get user input for the 4 entries
	getUserInputForMatrix(matrix);

	// Print out the inputted matrix
	std::cout << matrix;

	// Output determinant of the matrix
	//std::cout << findDeterminantOfMatrix(a, b, c, d);


	//findEigenvaluesFromEntries();
}