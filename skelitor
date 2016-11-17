/*
Michael Lewis
Discrete Structures - Wuthrich
November 17,2016
The purpose of this program is to determine if a matrix is of a valid undirected
simple graph, if it is we determine the degree of the verticies and how many 
edges overall are in the graph, if it is not a valid simple graph then we 
display that it is an INVALID graph.
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
	int iter
	bool invalid = false;
	infile << iter;
	//Loop for symmetry portion of program.
	for (int i = 0; i < iter; i++)
	{
		//variable for the row/col of the square matrix from infile.
		infile >> xy;
		//creation of the dynamic square matrix 2d array based on xy value.
		int **matrix = new int* [xy];
		for (int i = 0; i < xy; ++i)
			matrix[i] = new int [xy];
		//population of the matrix with values from infile.
		for (int row = 0; row < xy && !invalid; row++)
		{
			for (int col = 0; col < xy && !invalid; col++)
			{
				infile >> matrix[col][row];
			}
		}
		for(int i = 0; i < xy && !invalid; i++)
		{
			if(matrix[i][i] != 0)
				invalid = true;
		//variable check value for symmetry.
		int check = 0;
		//check for symmetry in matrix.
		for (int y = 0; y < xy && !invalid; y++)
		{
			for (int x = 0; x < xy && !invalid; x++)
			{
				if (matrix[y][x] == matrix[x][y])
				{
					if(matrix[y][x] == 1 || matrix[y][x] == 0)
						check++;
				}
				else 
					invalid = true;
			}
		}
		//change to where instead of symmetry the degrees of the verticies are determined.
		if (check == (xy * xy))
			outfile << "Symmetric \n";
		else
			outfile << "INVALID \n";
			//freeing memory from the matrix creation.
			for (int i = 0; i < xy; i++)
				delete[] matrix[i];
		delete[] matrix;
		matrix = NULL;
		outfile << endl;
	}
	// Close files
	outfile.close();
	infile.close();
	return 0;
}
