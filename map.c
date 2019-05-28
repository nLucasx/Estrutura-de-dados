#include <stdio.h>
#include <stdlib.h>
int factorial(int x)
{
	if (x < 0)
	{
		return -1;
	}
	else if (x == 0 || x == 1)
	{
		return 1;
	}
	else
	{
		return x * factorial(x-1);
	}
}
int square(int x)
{
	return x * x;
}
void map(int (*function)(int x), int *vector, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", (*function)(vector[i]));
	}
	printf("\n");
}
int main(){
	int n, *vector,i;

	printf("Type the size of your array >> ");
	scanf("%d", &n);
	printf("Type your numbers >> ");
	vector = malloc(n * sizeof(int));
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &vector[i]);
	}

	printf("Factorials of the numbers in your array:\n");
	map(factorial,vector,n);

	printf("The square of numbers in your array:\n");
	map(square,vector,n);
	free(vector);



}
