/*
Michael Lewis
Discrete Structures - Wuthrich
October 25,2016
The purpose of this program is to determine if the first 5 square matricies are
symmetric then with te next 5 pairs of matricies being square zero-one matricies
calculate the join of the pair of matricies.
*/
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;
	infile.open("symJoin.dat");
	outfile.open("Lewis_Michael_symJoin.txt");
	outfile << "Michael Lewis\n \n";
	//variable to control size of matrix, set off of infile later.
	int xy = 0;

	//Loop for symmetry portion of program.
	for (int i = 0; i < 5; i++)
	{
		//variable for the row/col of the square matrix from infile.
		infile >> xy;
		//creation of the dynamic square matrix 2d array based on xy value.
		int **matrix = new int* [xy];
		for (int i = 0; i < xy; ++i)
			matrix[i] = new int [xy];
		//population of the matrix with values from infile.
		for (int row = 0; row < xy; row++)
		{
			for (int col = 0; col < xy; col++)
			{
				infile >> matrix[col][row];
			}
		}
		//variable check value for symmetry.
		int check = 0;
		//check for symmetry in matrix.
		for (int y = 0; y < xy; y++)
		{
			for (int x = 0; x < xy; x++)
			{
				if (matrix[y][x] == matrix[x][y])
					check++;
				else
					goto fail;
			}
		}
	fail:
		if (check == (xy * xy))
			outfile << "Symmetric \n";
		else
			outfile << "Non Symmetric \n";
			//freeing memory from the matrix creation.
			for (int i = 0; i < xy; i++)
				delete[] matrix[i];
		delete[] matrix;
		matrix = NULL;
		outfile << endl;
	}
	// loop for join of 2 zero-one matricies
	for (int i = 0; i < 5; i++)
	{
		//variable for the row/col of the square matrix from infile.
		infile >> xy;
		//creation of the right side dynamic zero-one matrix 
		int **matrixR = new int*[xy];
		for (int i = 0; i < xy; ++i)
			matrixR[i] = new int[xy];
		//population of the right matrix with values from infile.
		for (int row = 0; row < xy; row++)
		{
			for (int col = 0; col < xy; col++)
			{
				infile >> matrixR[col][row];
			}
		}
		//creation of the left side dynamic zero-one matrix
		int **matrixL = new int*[xy];
		for (int i = 0; i < xy; ++i)
			matrixL[i] = new int[xy];	
		//population of the left matrix with values from infile.
		for (int row = 0; row < xy; row++)
		{
			for (int col = 0; col < xy; col++)
			{
				infile >> matrixL[col][row];
			}
		}
		//creation of the joined dynamic zero-one matrix
		int **matrixJ = new int*[xy];
		for (int i = 0; i < xy; ++i)
			matrixJ[i] = new int[xy];
		//joining of the matricies
		for (int row = 0; row < xy; row++)
		{
			for (int col = 0; col < xy; col++)
			{
				matrixJ[col][row] = matrixR[col][row] | matrixL[col][row];
			}
		}
		//display the joined matrix in outfile
		outfile << "Join \n";
		for (int row = 0; row < xy; row++)
		{
			for (int col = 0; col < xy; col++)
			{
				outfile << matrixJ[col][row] << ' ';
			}
			outfile << endl;
		}
		outfile << endl;
		//freeing memory from the right matrix creation.
		for (int i = 0; i < xy; i++)
			delete[] matrixR[i];
		delete[] matrixR;
		matrixR = NULL;
		//freeing memory from the left matrix creation.
		for(int i = 0; i < xy; i++)
			delete[] matrixL[i];
		delete[] matrixL;
		matrixL = NULL;
	}
	// Close files
	outfile.close();
	infile.close();
	return 0;
}
