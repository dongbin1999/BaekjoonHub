#include <cstdio>
#include <algorithm>
using namespace std;

int dp[500001], temp[500001];

int main(void)
{
    int N, h;
    scanf("%d", &N);
    fill(dp, dp + 500001, -1e9);
    while (N--)
    {
        scanf("%d", &h);
        for (int i = 0; i <= 500000; i++)
            temp[i] = dp[i];

        for (int i = 0; i <= 500000; i++)
            if (temp[i] != -1e9)
            {
                if (i + h <= 500000)
                    dp[i + h] = max(dp[i + h], temp[i]);
                if (i > h)
                    dp[i - h] = max(dp[i - h], temp[i] + h);
                else
                    dp[h - i] = max(dp[h - i], temp[i] + i);
            }
        dp[h] = max(dp[h], 0);
    }
    printf("%d", dp[0] == -1e9 ? -1 : dp[0]);
    return 0;
}