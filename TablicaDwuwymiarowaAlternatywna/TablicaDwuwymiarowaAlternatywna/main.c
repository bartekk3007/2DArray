#include <stdio.h>
#include <stdlib.h>

int **zwrocTabele(int **arr, int m, int n)
{
	int **t = (int**) malloc(sizeof(int*) * n);
	*t = (int*) malloc(sizeof(int) * m * n);
	for (int i = 0; i < n; i++)
	{
		t[i] = (*t + m * i);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			t[j][i] = arr[i][j];
		}
	}
	return t;
}

void funkcja(int **arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = arr[m - i - 1][n - j - 1];
		}
	}
}

int main()
{
	int m = 3;
	int n = 4;

	int** p = (int**)malloc(sizeof(int*) * m);
	*p = (int*)malloc(sizeof(int) * m * n);

	for (int i = 0; i < m; i++)
	{
		p[i] = (*p + i * n);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p[i][j] = i * (m+1) + j;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	int **t = zwrocTabele(p, m, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", t[i][j]);
		}
		printf("\n");
	}

	free(*t);
	free(t);

	free(*p);
	free(p);
	
	return 0;
}