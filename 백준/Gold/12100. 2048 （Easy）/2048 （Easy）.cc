#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

int ans;

void go(int temp[21][21], int dir, int size, int it)
{
    if (it > 5)
        return;
    int moved[21][21] = { {0} }, map[21][21];

    switch (dir)
    {
    case 1:
        for (int x = 1; x <= size; x++)
            for (int y = 1; y <= size; y++)
                map[x][y] = temp[x][y];
        break;
    case 2:
        for (int x = 1; x <= size; x++)
            for (int y = 1; y <= size; y++)
                map[x][y] = temp[size + 1 - x][size + 1 - y];
        break;
    case 3:
        for (int x = 1; x <= size; x++)
            for (int y = 1; y <= size; y++)
                map[x][y] = temp[y][x];
        break;
    case 4:
        for (int x = 1; x <= size; x++)
            for (int y = 1; y <= size; y++)
                map[x][y] = temp[size + 1 - y][size + 1 - x];
        break;
    default:
        break;
    }

    //왼쪽으로 미는걸 기준으로
    for (int x = 1; x <= size; x++)
    {
        int prev = map[x][1], index = 1;
        for (int y = 2; y <= size; y++)
        {
            if (!map[x][y])
                continue;
            if (prev == map[x][y])
            {
                moved[x][index++] = map[x][y] * 2;
                prev = 0;
            }
            else
            {
                if (prev)
                    moved[x][index++] = prev;
                prev = map[x][y];
            }
        }
        //마지막에 갱신이 안된경우.
        if (prev)
            moved[x][index++] = prev;
    }

    for (int x = 1; x <= size; x++)
    {
        for (int y = 1; y <= size; y++)
        {
            //if (it == 5)
                //printf("%d ", moved[x][y]);
            ans = max(ans, moved[x][y]);
        }
        //if (it == 5)
            //printf("\n");
    }

    for (int d = 1; d <= 4; d++)
        go(moved, d, size, it + 1);
}

int main(void)
{
    int map[21][21];
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);

    if (n == 1)
    {
        return !printf("%d", map[1][1]);
    }

    for (int i = 1; i <= 4; i++)
        go(map, i, n, 1);

    printf("%d", ans);
    return 0;
}