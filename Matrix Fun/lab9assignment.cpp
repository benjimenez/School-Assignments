//Benjamin Jimenez


#include <iostream>
#include <stdlib.h>
using namespace std;

void Menu();
void prntMatrix(int **matrix);
void sumOf(int **matrix);
void showUpper(int **matrix);
void midRow(int **matrix);
void midCol(int **matrix);

int row, col; //global declaration
int **matrix;
int main(int argc, char *argv[])
{

	int choice;
	int x, y;
	int i = 3;
	row = atoi(argv[1]);
	col = atoi(argv[2]);

	if (argc < ((row*col)+3))
  	{
		cout<<"Did not fill matrix."<<endl;
    		return 0;
  	}

	//matrix[row][col];

	int** matrix = new int*[row];
	for(int a = 0; a < row; a++)
	{
		matrix[a] = new int[col];
	}

	for(x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			matrix[x][y] = atoi(argv[i]);
			i++;
		}
	}
	
	choice = 1;

	while (choice != 0)	{
		Menu();
		cin >> choice;
		cout << endl;

		switch(choice) {
		case 0: //close program..
			break;
		case 1: prntMatrix(matrix);
			break;
		case 2: sumOf(matrix);
			break;
		case 3: showUpper(matrix);
			break;
		case 4: midRow(matrix);
			break;
		case 5: midCol(matrix);
			break;
		default: cout << "Invalid option. Try again." << endl;
	}
}


return 0;
}


void Menu()
{

	cout << "\n0. Exit program.\n";
	cout << "1. Print the matrix.\n";
	cout << "2. Show sum of all of the elements.\n";
	cout << "3. Show the upper half.\n";
	cout << "4. Show middle row.\n";
	cout << "5. Show middle column.\n";
	cout << "\nChoose an option by entering a number between 0 and 5, inclusively: ";
}

void prntMatrix(int **matrix)
{
	int x, y;

	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			cout << matrix[x][y] << " ";
		}
		cout << endl;
	}
}

void sumOf(int **matrix)
{
	int x, y, sum = 0;

	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			sum = sum + matrix[x][y];
		}
	}

	cout << sum << endl;	

}

void showUpper(int **matrix)
{
	int x, y;

	if(row != col)
  	{ 
		cout<<"Matrix must be a square."<<endl;
		return;
  	}

	for (x = 0; x < (row/2); x++)
	{
		for (y = 0; y < col; y++)
		{
			cout << matrix[x][y] << " ";
		}
		cout << endl;
	}
}
void midRow(int **matrix)
{

	int y;

	if((row%2) == 0)
	{
		cout<<"Matrix must have an odd number of rows."<<endl;
    		return;
  	}

		for (y = 0; y < col; y++)
		{
			cout << matrix[row/2][y] << " ";
		}
		cout << endl;

	
}

void midCol(int **matrix)
{

	int x;
	if((col%2) == 0)
  	{
		cout<<"Matrix must have an odd number of columns."<<endl;
    		return;
  	}

	for (x = 0; x < row; x++)
		{
			cout << matrix[x][col/2] << endl;
		}
	cout << endl;
}





