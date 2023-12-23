#include <cstdio>
#include <algorithm>
#define INF 1000000000
using namespace std;

int coin[100];
int temp[10001];

int main()
{
    int n, change;
    scanf("%d %d", &n, &change);
    for (int i = 1; i <= n; i++)
        scanf("%d", &coin[i]);
    fill(temp, temp + 10001, INF);
    temp[change] = 0;
    for (int c = 1; c <= n; c++)
    {
        for (int i = change; i >= 0; i--)
        {
            if (i - coin[c] < 0)
                break;
            temp[i - coin[c]] = min(temp[i - coin[c]], temp[i] + 1);
        }
    }
    printf("%d", temp[0] == INF ? -1 : temp[0]);
    return 0;
}