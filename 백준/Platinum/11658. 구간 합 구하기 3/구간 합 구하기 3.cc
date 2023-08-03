#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int sz = (1 << 10);

int a[sz + 1][sz + 1], tree[sz + 1][sz + 1], n, m;

int sum(int x, int y)
{
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
            ret += tree[i][j];
    return ret;
}

void update(int x, int y, int diff)
{
    for (int i = x; i <= sz; i += i & -i)
        for (int j = y; j <= sz; j += j & -j)
            tree[i][j] += diff;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
        {
            scanf("%d", &a[x][y]);
            update(x, y, a[x][y]);
        }

    int x, y, x2, y2, c, v;
    while (m--)
    {
        scanf("%d", &c);
        if (c)
        {
            scanf("%d %d %d %d", &x, &y, &x2, &y2);
            printf("%d\n", sum(x2, y2) - sum(x2, y - 1) - sum(x - 1, y2) + sum(x - 1, y - 1));
        }
        else
        {
            scanf("%d %d %d", &x, &y, &v);
            update(x, y, v - a[x][y]);
            a[x][y] = v;
        }
    }
}