#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isprime(int x)
{
	int i;
	if ((x % 2 == 0 && x != 2 ) || x == 1)
	{
		return 0;
	}
	else
	{
		for (i = 3; i <= sqrt(x); i+=2)
		{
			if (x % i == 0)
			{
				return 0;
			}
		}
		return 1;
	}
}
int isodd(int x)
{
	return x % 2 != 0 ? 1 : 0;
}
int iseven(int x)
{
	return x % 2 == 0 ? 1 : 0;
}
void filter(int (*function)(int x), int *vector, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if ((*function)(vector[i]) == 1)
		{
			printf("%d ", vector[i]);
		}
	}
	printf("\n");
}
int main()
{
	int n, *vector, i;

	printf("Type the size of your array >> ");
	scanf("%d", &n);

	vector = malloc(n * sizeof(int));
	printf("Type the numbers of your array >> ");

	for (i = 0; i < n; i++)
	{
		scanf("%d", &vector[i]);
	}

	printf("These numbers are even:\n");
	filter(iseven,vector,n);

	printf("These numbers are odd:\n");
	filter(isodd,vector,n);

	printf("These numbers are primes:\n");
	filter(isprime,vector,n);
	
	free(vector);
}
