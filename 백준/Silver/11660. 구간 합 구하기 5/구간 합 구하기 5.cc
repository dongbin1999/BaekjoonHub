#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int sz = (1 << 10);

int a[sz + 1][sz + 1], sum[sz + 1][sz + 1];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
        {
            scanf("%d", &a[x][y]);
            sum[x][y] = sum[x - 1][y] + sum[x][y - 1] - sum[x - 1][y - 1] + a[x][y];
        }

    int x, y, x2, y2;
    while (m--)
    {
        scanf("%d %d %d %d", &x, &y, &x2, &y2);
        printf("%d\n", sum[x2][y2] - sum[x2][y - 1] - sum[x - 1][y2] + sum[x - 1][y - 1]);
    }
}