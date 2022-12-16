#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	if (!input)
	{
		cout << "error";
		return 0;
	}

	int m;
	input >> m;
	while (m % 2 == 0)
		m /= 2;

	while (m % 5 == 0)
		m /= 5;

	if (m != 1)
		output << "YES";
	else
		output << "NO";

	input.close();
	output.close();
}

