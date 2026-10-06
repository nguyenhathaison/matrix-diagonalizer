#include <iostream>
#include <utility>

//std::pair<int, int> findEigenvaluesFromEntries()
//{
//
//}

int main()
{
	// Initialize the entries of the matrix
	int a{};
	int b{};
	int c{};
	int d{};

	// Form of matrix
	std::cout << "Given a 2x2 matrix of the form:\n";
	std::cout << "[ " << 'a' << ' ' << 'b' << " ]\n";
	std::cout << "[ " << 'c' << ' ' << 'd' << " ]\n";

	// Get user input for the 4 entries
	for (char entry{ 'a' }; entry <= 'd'; ++entry)
	{
		std::cout << "Enter entry " << entry << " of the matrix: ";

		switch (entry)
		{
		case 'a':
			std::cin >> a;
			continue;
		case 'b':
			std::cin >> b;
			continue;
		case 'c':
			std::cin >> c;
			continue;
		case 'd':
			std::cin >> d;
			continue;
		}
	}

	// Print out the inputted matrix
	std::cout << "\nInput matrix is: \n";
	std::cout << a << '\t' << b << '\n';
	std::cout << c << '\t' << d << '\n';


	//findEigenvaluesFromEntries();
}