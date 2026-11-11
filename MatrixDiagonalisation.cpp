#include <iostream>
#include <utility>
#include <optional>
#include <cmath>

struct TwoByTwoMatrix
{
	int a{};
	int b{};
	int c{};
	int d{};

	// Coefficients of the matrix's characteristic polynomial
	int quadratic{ 1 };
	int linear{};
	int constant{};

	// Eigenvalues
	std::optional<int> firstEigenvalue{ std::nullopt };
	std::optional<int> secondEigenvalue{ std::nullopt };
};

void getUserInputForMatrix(TwoByTwoMatrix& matrix)
{
	// Form of matrix
	std::cout << "Given a 2x2 matrix of the form:\n";
	std::cout << "[ " << 'a' << ' ' << 'b' << " ]\n";
	std::cout << "[ " << 'c' << ' ' << 'd' << " ]\n";

	std::cout << "Input entry a: ";
	std::cin >> matrix.a;

	std::cout << "Input entry b: ";
	std::cin >> matrix.b;

	std::cout << "Input entry c: ";
	std::cin >> matrix.c;

	std::cout << "Input entry d: ";
	std::cin >> matrix.d;


	// Calculate the linear and constant coefficients in the characteristic polynomial
	matrix.linear   = -(matrix.a + matrix.d);
	matrix.constant = matrix.a * matrix.d - matrix.b * matrix.c;
}

std::ostream& operator<<(std::ostream& out, const TwoByTwoMatrix& matrix)
{
	out << "\nThe inputted matrix is: \n";
	out << matrix.a << '\t' << matrix.b << '\n';
	out << matrix.c << '\t' << matrix.d << '\n';

	out << '\n';
	out << "It's characteristic polynomial is: x^2 ";

	if (matrix.linear > 0)
		out << "+ " << matrix.linear << "x ";
	else if (matrix.linear < 0)
		out << matrix.linear << "x ";

	
	if (matrix.constant > 0)
		out << "+ " << matrix.constant;
	else if (matrix.constant < 0)
		out << matrix.constant;

	out << '\n';

	return out;
}


constexpr int calculateDiscriminantOfCharacteristicPolynomial(const TwoByTwoMatrix& matrix)
{
	return (matrix.linear * matrix.linear) - 4 * (matrix.quadratic * matrix.constant);
}


void calculateEigenvalues(TwoByTwoMatrix& matrix)
{
	int discriminant = calculateDiscriminantOfCharacteristicPolynomial(matrix);

	if (discriminant < 0)
		std::cout << "Matrix has no real eigenvalues.\n";
	else if (discriminant == 0)
	{
		std::cout << "Matrix has one eigenvalue.\n";

		// apply quadratic formula
		matrix.firstEigenvalue = (-matrix.linear + std::sqrt(calculateDiscriminantOfCharacteristicPolynomial(matrix))) / (2 * matrix.quadratic);
	}
		
	else if (discriminant > 0)
	{
		std::cout << "Matrix has two eigenvalues.\n";

		matrix.firstEigenvalue = (-matrix.linear + std::sqrt(calculateDiscriminantOfCharacteristicPolynomial(matrix))) / (2 * matrix.quadratic);
		matrix.secondEigenvalue = (-matrix.linear - std::sqrt(calculateDiscriminantOfCharacteristicPolynomial(matrix))) / (2 * matrix.quadratic);
	}
}



int main()
{
	// Initialize the a 2x2 matrix 
	TwoByTwoMatrix matrix{};

	// Get user input for the 4 entries
	getUserInputForMatrix(matrix);

	// Print out the inputted matrix using overloaded operator<< for TwoByTwoMatrix type
	std::cout << matrix;
	
	// calculate matrix's real eigenvalues and update corresponding members
	calculateEigenvalues(matrix);

	if (matrix.firstEigenvalue.has_value())
		std::cout << (matrix.firstEigenvalue).value() << '\n';

	if (matrix.secondEigenvalue.has_value())
		std::cout << (matrix.secondEigenvalue).value() << '\n';
}