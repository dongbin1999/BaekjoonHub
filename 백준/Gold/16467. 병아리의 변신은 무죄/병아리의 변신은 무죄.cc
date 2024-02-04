#include <cstdio>
#define MOD 100000007

long long f[11][11];
long long mat[11][11];
long long ans[11][1];
long long R[11][1];

void power(long long n, int K)
{
    if (n <= 1)
        return;
    power(n / 2, K);
    long long temp[11][11] = { {0} };
    for (int i = 0; i <= K; i++)
        for (int j = 0; j <= K; j++)
            for (int k = 0; k <= K; k++)
                temp[i][j] += mat[i][k] * mat[k][j];
    for (int i = 0; i <= K; i++)
        for (int j = 0; j <= K; j++)
            mat[i][j] = temp[i][j] % MOD;
    if (n % 2)
    {
        long long temp[11][11] = { {0} };
        for (int i = 0; i <= K; i++)
            for (int j = 0; j <= K; j++)
                for (int k = 0; k <= K; k++)
                    temp[i][j] += mat[i][k] * f[k][j];
        for (int i = 0; i <= K; i++)
            for (int j = 0; j <= K; j++)
                mat[i][j] = temp[i][j] % MOD;
    }
}

void mult(int row_A, int cA_rB, int col_B)
{
    for (int i = 0; i < row_A; i++)
        for (int j = 0; j < col_B; j++)
        {
            long long temp = 0;
            for (int k = 0; k < cA_rB; k++)
                temp += mat[i][k] * R[k][j];
            ans[i][j] = temp % MOD;
        }
}

long long pow2(long long n, long long k)
{
    if (n == 0)
        return 1;
    long long temp = pow2(n / 2, k);
    temp = (temp * temp) % MOD;
    if (n % 2)
        return (temp * 2) % MOD;
    else
        return temp;
}

int main(void)
{
    for (int x = 0; x <= 10; x++)
        for (int y = 0; y <= 10; y++)
            if (x >= y && y)
                f[x][y] = 0;
            else
                f[x][y] = 1;

    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long K, N;
        scanf("%lld %lld", &K, &N);
        for (int x = 0; x <= K; x++)
            for (int y = 0; y <= K; y++)
                mat[x][y] = f[x][y];

        long long temp[20];
        for (long long i = 0; i <= K; i++)
            temp[i] = 1;
        for (long long i = K + 1; i < 2 * K; i++)
            temp[i] = temp[i - 1] + temp[i - K - 1];

        if (!K)
        {
            printf("%lld\n", pow2(N, 1));
            continue;
        }

        if (N < 2 * K)
        {
            printf("%lld\n", temp[N]);
            continue;
        }

        for (long long i = N, j = 0; i >= N - K; i--, j++)
            R[j][0] = temp[i - (N / K - 1) * K];
                
        power(N / K - 1, K);
        mult(K + 1, K + 1, 1);

        printf("%lld\n", ans[0][0]);
    }
    return 0;
}