#include <cstdio>

int A[100][100], B[100][100], C[100][100], temp;

void mult(int row_A, int cA_rB, int col_B)
{
	for (int i = 0; i < row_A; i++)
		for (int m = 0; m < col_B; m++)
		{
			temp = 0;
			for (int n = 0; n < cA_rB; n++)
				temp += A[i][n] * B[n][m];
			C[i][m] = temp;
		}
}

int main()
{
	int N, M, K;

	scanf("%d %d", &N, &M);
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			scanf("%d", &A[r][c]);

	scanf("%d %d", &M, &K);
	for (int r = 0; r < M; r++)
		for (int c = 0; c < K; c++)
			scanf("%d", &B[r][c]);

	mult(N, M, K);
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < K; c++)
			printf("%d ", C[r][c]);
		printf("\n");
	}
	return 0;
}
