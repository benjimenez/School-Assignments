//Benjamin Jimenez

#include <stdio.h>
int series(int a, int x, int y); //x=x, y=final answer, a=a

int main()
{

	int a, x, y = 0;
	/* prompt and store A and X*/
	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter x: ");
	scanf("%d", &x);

	printf("y = %d\n", series(a,x,y));	//call to series function

	return 0;
}


int series(int a, int x, int y)
{

	int i, temp;

	if(a == 1) //adds power of 1 and 0
	return (1 + x + y);

	else
	{
		temp=1;
		for(i=0;i<a;i++) //power loop
		temp = (temp*x); //power multiplication

		y+=temp;	//stores temp into y
		return series(a-1,x,y); //recursion call and subtract 1 from a
	}
}
