#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct point
{
    int x, y;
};

point go[4] = { {0,1},{0,-1},{1,0},{-1,0} };
int map[27][27], N;
vector<int> v;

void bfs(point p)
{
    if (!map[p.x][p.y])
        return;
    int cnt = 0;
    queue<point> q;
    map[p.x][p.y] = 0;
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop(); cnt++;
        for (int i = 0; i < 4; i++)
        {
            int tx = p.x + go[i].x, ty = p.y + go[i].y;
            if (map[tx][ty])
            {
                map[tx][ty] = 0;
                q.push({ tx,ty });
            }
        }
    }
    v.push_back(cnt);
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%1d", &map[i][j]);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            bfs({ i,j });
    printf("%d\n", v.size());
    int vs = v.size();
    sort(v.begin(), v.end());
    for (int i = 0; i < vs; i++)
        printf("%d\n", v[i]);
    return 0;
}