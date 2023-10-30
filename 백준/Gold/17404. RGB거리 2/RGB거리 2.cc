#include <cstdio>
#include <algorithm>
#define RED 0
#define GREEN 1
#define BLUE 2
using namespace std;

int cost[3][1002];
int answer = 1000000;

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int c = 0; c < 3; c++)
            scanf("%d", &cost[c][i]);

    for (int start = 0; start < 3; start++)
    {
        int dp[3][1002] = { {0} };

        dp[start][1] = cost[start][1];
        dp[(start + 1) % 3][1] = 1000000;
        dp[(start + 2) % 3][1] = 1000000;

        for (int i = 2; i <= N - 1; i++)
        {
            dp[RED][i] = min(dp[GREEN][i - 1], dp[BLUE][i - 1]) + cost[RED][i];
            dp[GREEN][i] = min(dp[RED][i - 1], dp[BLUE][i - 1]) + cost[GREEN][i];
            dp[BLUE][i] = min(dp[RED][i - 1], dp[GREEN][i - 1]) + cost[BLUE][i];
        }

        dp[(start + 1) % 3][N] = min(dp[(start + 2) % 3][N - 1], dp[start][N - 1]) + cost[(start + 1) % 3][N];
        dp[(start + 2) % 3][N] = min(dp[(start + 1) % 3][N - 1], dp[start][N - 1]) + cost[(start + 2) % 3][N];
        answer = min(answer, min(dp[(start + 1) % 3][N], dp[(start + 2) % 3][N]));
    }

    printf("%d", answer);
    return 0;
}