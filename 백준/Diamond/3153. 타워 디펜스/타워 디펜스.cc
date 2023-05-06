#include <cstdio>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD (ll)1000000007
const int MAX = 10000;
//오른쪽 : k+10000, 왼쪽 : -k+10000, 위 : k+40000, 아래 : -k+40000
// k: (k/100) + 1 : x축, (k%100) + 1: y축         [0,10000)
int dfsn[MAX * 5 + 1], dfsnumber, scc[MAX * 5 + 1], sccnumber, val[MAX * 5 + 1];
vector<int> graph[MAX * 5 + 1];
stack<int> s;
char m[200][200];
pii tsort[MAX * 5 + 1];

int dfs(int node)
{
    dfsn[node] = ++dfsnumber;
    s.push(node);

    int topmost = dfsn[node];
    for (int i = 0; i < graph[node].size(); i++)
    {
        if (!dfsn[graph[node][i]])
            topmost = min(topmost, dfs(graph[node][i]));
        else if (!scc[graph[node][i]])
            topmost = min(topmost, dfsn[graph[node][i]]);
    }

    if (topmost == dfsn[node])
    {
        ++sccnumber;
        while (true)
        {
            int t = s.top();
            s.pop();
            scc[t] = sccnumber;
            if (t == node)
                break;
        }
    }
    return topmost;
}

int main(void)
{
    int R, S;
    scanf("%d %d", &R, &S);
    for (int i = 1; i <= R; i++)
        scanf("%s", m[i] + 1);

    bool up, down, left, right;
    int x, y, rk = 40000, ck = 10000; //row+-, column+-.

    for (int i = 1; i <= R; i++)
        m[i][0] = m[i][S + 1] = '#';
    for (int i = 1; i <= S; i++)
        m[0][i] = m[R + 1][i] = '#';

    for (int i = 1; i <= R * S; i++)
    {
        up = down = left = right = false;
        x = ((i - 1) / S) + 1, y = ((i - 1) % S) + 1;
        if (m[x][y] == '.' || m[x][y] == '#')
            continue;
        if (m[x][y] == 'T')
        {
            int xx = x + 1, yy = y;
            while (m[xx][yy] != '#')
            {
                if (m[xx][yy] == 'T')
                    down = true;
                xx++;
            }
            xx = x - 1, yy = y;
            while (m[xx][yy] != '#')
            {
                if (m[xx][yy] == 'T')
                    up = true;
                xx--;
            }
            xx = x, yy = y + 1;
            while (m[xx][yy] != '#')
            {
                if (m[xx][yy] == 'T')
                    right = true;
                yy++;
            }
            xx = x, yy = y - 1;
            while (m[xx][yy] != '#')
            {
                if (m[xx][yy] == 'T')
                    left = true;
                yy--;
            }
            if (up) //내 위에 타워가 있다.
                graph[i + rk].push_back(-i + rk); //아래 고정.
            if (down)
                graph[-i + rk].push_back(i + rk); //위 고정.
            if (right)
                graph[i + ck].push_back(-i + ck); //왼쪽 고정.
            if (left)
                graph[-i + ck].push_back(i + ck); //오른쪽 고정.
        }
        else if (m[x][y] == 'n')
        {
            int xx = x + 1, yy = y;
            int upt, downt, rightt, leftt;
            while (m[xx][yy] != '#' && !down)
            {
                if (m[xx][yy] == 'T')
                    down = true, downt = (xx - 1) * S + yy;
                xx++;
            }
            xx = x - 1, yy = y;
            while (m[xx][yy] != '#' && !up)
            {
                if (m[xx][yy] == 'T')
                    up = true, upt = (xx - 1) * S + yy;
                xx--;
            }
            xx = x, yy = y + 1;
            while (m[xx][yy] != '#' && !right)
            {
                if (m[xx][yy] == 'T')
                    right = true, rightt = (xx - 1) * S + yy;
                yy++;
            }
            xx = x, yy = y - 1;
            while (m[xx][yy] != '#' && !left)
            {
                if (m[xx][yy] == 'T')
                    left = true, leftt = (xx - 1) * S + yy;
                yy--;
            }

            if (up && down && right && left)
            {
                ;
            }
            else if (up && down && right && !left)
            {
                graph[rightt + ck].push_back(-rightt + ck);
            }
            else if (up && down && !right && left)
            {
                graph[-leftt + ck].push_back(leftt + ck);
            }
            else if (up && down && !right && !left)
            {
                ;
            }
            else if (up && !down && right && left)
            {
                graph[upt + rk].push_back(-upt + rk);
            }
            else if (up && !down && right && !left)
            {
                graph[rightt + ck].push_back(-upt + rk);
                graph[upt + rk].push_back(-rightt + ck);
            }
            else if (up && !down && !right && left)
            {
                graph[-leftt + ck].push_back(-upt + rk);
                graph[upt + rk].push_back(leftt + ck);
            }
            else if (up && !down && !right && !left)
            {
                graph[upt + rk].push_back(-upt + rk);
            }
            else if (!up && down && right && left)
            {
                graph[-downt + rk].push_back(downt + rk);
            }
            else if (!up && down && right && !left)
            {
                graph[-downt + rk].push_back(-rightt + ck);
                graph[rightt + ck].push_back(downt + rk);
            }
            else if (!up && down && !right && left)
            {
                graph[-downt + rk].push_back(leftt + ck);
                graph[-leftt + ck].push_back(downt + rk);
            }
            else if (!up && down && !right && !left)
            {
                graph[-downt + rk].push_back(downt + rk);
            }
            else if (!up && !down && right && left)
            {
                ;
            }
            else if (!up && !down && right && !left)
            {
                graph[rightt + ck].push_back(-rightt + ck);
            }
            else if (!up && !down && !right && left)
            {
                graph[-leftt + ck].push_back(leftt + ck);
            }
            else if (!up && !down && !right && !left)
            {
                ;
            }
        }
    }

    for (int i = 0; i <= MAX * 5; i++)
        if (!dfsn[i])
            dfs(i);

    for (int i = 0; i <= MAX * 5; i++)
        tsort[i] = { scc[i], i };
    sort(tsort, tsort + 1 + 5 * MAX, greater<pii>());

    fill(val, val + 1 + 5 * MAX, -1);
    for (int i = 0; i <= 5 * MAX; i++)
    {
        if (tsort[i].second > MAX * 2 && tsort[i].second < rk - ck)
            continue;
        if (tsort[i].second >= rk - ck)
        {
            if (val[abs(-tsort[i].second + rk)] == -1)
                val[abs(-tsort[i].second + rk) + rk] = -tsort[i].second + rk < 0;
        }
        else
        {
            if (val[abs(-tsort[i].second + ck)] == -1)
                val[abs(-tsort[i].second + ck) + ck] = -tsort[i].second + ck < 0;
        }
    }

    for (int i = 1; i <= R * S; i++)
    {
        x = ((i - 1) / S) + 1, y = ((i - 1) % S) + 1;
        if (m[x][y] != 'T')
            continue;
        if (!val[i + ck] && !val[i + rk])
            m[x][y] = '1';
        if (val[i + ck] && !val[i + rk])
            m[x][y] = '2';
        if (val[i + ck] && val[i + rk])
            m[x][y] = '3';
        if (!val[i + ck] && val[i + rk])
            m[x][y] = '4';
    }

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= S; j++)
            printf("%c", m[i][j]);
        printf("\n");
    }

    return 0;
}