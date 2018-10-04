//Benjamin Jimenez

#include<stdio.h>
int deter(int a[3][3]); //finds determinant of 3x3 matrix
void transpose(int a[3][3], int t[3][3]); //creates transpose matrix

int main()
{
  	int a[3][3], t[3][3]; //a = matrix, t = transpose matrix
	int i,j; //temporaries
	int determinant=0; //answer

 	printf("Enter the 9 elements of a 3x3 matrix!\n");
 	for(i=0;i<3;i++){ //row
		for(j=0;j<3;j++){ //columns
		printf("Element %dx%d: ", i+1, j+1); //tells which element in
        	scanf("%d",&a[i][j]); //stores number in 2D array
		}
	}
	/* shows matrix */
	printf("\nMatrix:\n");
	for(i=0;i<3;i++){ // prints rows
	printf("\n");
		for(j=0;j<3;j++)
		printf("%d\t",a[i][j]); //prints columns
	}

	determinant = deter(a); //call to function finds determinant
	printf("\nDeterminant of matrix is: %d\n",determinant);

	transpose(a, t); //call to make transpose matrix
	determinant = deter(t); //finds determinant of transpose matrix
	printf("\nDeterminant of transposed matrix is: %d\n",determinant);


	return 0;
}


int deter(int a[3][3])
{
	int d;
	/* formula finds determinant */
	d = a[0][0] * ((a[1][1]*a[2][2]) - (a[2][1]*a[1][2])) - a[0][1] * (a[1][0]
   	* a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);

	return d;
}

void transpose(int a[3][3], int t[3][3])
{
	int i, j;

	/* creates transpose matrix */
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		t[j][i] = a[i][j]; //flips all numbers
	}
	/* prints transpose matrix */
	printf("\nTranspose Matrix:\n");
	for(i=0;i<3;i++){
	printf("\n");
		for(j=0;j<3;j++)
		printf("%d\t",t[i][j]);
	}
	return;
}





//http://www.cquestions.com/2011/09/c-program-to-find-determinant-of-matrix.html
