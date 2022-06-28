#include <iostream>
using namespace std;

int main()
{
	int K = 2, L = 5;
	int** matrix = new int* [K];

	for (int k = 0; k < K; k++)
	{
		matrix[k] = new int[L];

		for (int l = 0; l < L; l++)
		{
			matrix[k][l] = k + 1;
		}
	}

	int M = 4;
	int** matrix2 = new int* [M];

	for (int l = 0; l < L; l++)
	{
		matrix2[l] = new int[M];

		for (int m = 0; m < M; m++)
		{
			matrix2[l][m] = m + 1;
		}
	}

	// Printing matrix
	cout << "Matrix 1: \n";
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < L; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	// Printing matrix2
	cout << "Matrix 2: \n";
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << matrix2[i][j] << " ";
		}
		cout << endl;
	}

	int mult[10][10];

	// Initializing elements of matrix mult to 0.
	for (int i = 0; i < K; ++i)
		for (int j = 0; j < M; ++j)
		{
			mult[i][j] = 0;
		}

	// Multiplying matrix1 and 2 and storing in array mult.
	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < L; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				mult[i][j] += matrix[i][k] * matrix2[k][j];
			}
		}
	}

	// Displaying the multiplication of two matrix.
	cout << endl << "Multiplication: " << endl;
	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << " " << mult[i][j];
		}
		cout << endl;
	}

	return 0;
}
