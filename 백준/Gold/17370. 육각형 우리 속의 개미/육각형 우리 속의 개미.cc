#include <cstdio>
#include <algorithm>
using namespace std;

struct point
{
    int x, y;
};

point move(point cur, int prevdir, int order)
{
    switch ((prevdir + 6 + order) % 6)
    {
    case 0:
        return { cur.x + 0, cur.y + 2 };
    case 1:
        return { cur.x + 1, cur.y + 1 };
    case 2:
        return { cur.x + 1, cur.y - 1 };
    case 3:
        return { cur.x + 0, cur.y - 2 };
    case 4:
        return { cur.x - 1, cur.y - 1 };
    case 5:
        return { cur.x - 1, cur.y + 1 };
    default:
        return { -100000000,-100000000 };
    }
}

int n, ans;
point route[24];
void go(int moved, int left, int prevdir, point cur)
{
    if (left == 0)
    {
        point tmp = move(cur, prevdir, 1);
        for (int i = 1; i <= moved; i++)
            if (tmp.x == route[i].x && tmp.y == route[i].y)
                ans++;
        tmp = move(cur, prevdir, -1);
        for (int i = 1; i <= moved; i++)
            if (tmp.x == route[i].x && tmp.y == route[i].y)
                ans++;
        return;
    }
    bool flag = false;
    point tmp = move(cur, prevdir, 1);
    for (int i = 1; i <= moved; i++)
        if (tmp.x == route[i].x && tmp.y == route[i].y)
            flag = true;
    if (!flag)
    {
        route[++moved] = tmp;
        go(moved, left - 1, (prevdir + 6 + 1) % 6, tmp);
        moved--;
    }
    
    flag = false;
    tmp = move(cur, prevdir, -1);
    for (int i = 1; i <= moved; i++)
        if (tmp.x == route[i].x && tmp.y == route[i].y)
            return;
    if (!flag)
    {
        route[++moved] = tmp;
        go(moved, left - 1, (prevdir + 6 - 1) % 6, tmp);
        moved--;
    }
    return;
}

int main(void)
{
    point start = { 100,100 };
    route[1] = start;
    scanf("%d", &n);
    start.y += 2;
    route[2] = start;
    go(2, n - 1, 0, start);
    printf("%d", ans);
    return 0;
}