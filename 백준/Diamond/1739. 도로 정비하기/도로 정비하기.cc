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
const int MAX = 1000;
//x오른쪽 : x+1000, x왼쪽 : -x+1000, y아래 : y+4000, y위 : -y+4000
int dfsn[MAX * 5 + 1], dfsnumber, scc[MAX * 5 + 1], sccnumber;
vector<int> graph[MAX * 5 + 1];
stack<int> s;

void init(int n, int m)
{
    for (int i = 0; i <= 5000; i++)
    {
        dfsn[i] = scc[i] = 0;
        graph[i].clear();
    }
    sccnumber = dfsnumber = 0;
}

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
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int n, m, k, x1, y1, x2, y2;
        scanf("%d %d %d", &n, &m, &k);
        int xk = 1000, yk = 4000;

        while (k--)
        {
            //좌표는 아래가 양의방향, 오른쪽이 양의방향.
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if (x1 < x2 && y1 < y2) //오른쪽 아래.
            {
                graph[-x1 + xk].push_back(y1 + yk);
                graph[-y1 + yk].push_back(x1 + xk);
                graph[-x2 + xk].push_back(y2 + yk);
                graph[-y2 + yk].push_back(x2 + xk);
                graph[-x1 + xk].push_back(x2 + xk); //둘중 하나는 오른쪽.
                graph[-x2 + xk].push_back(x1 + xk);
                graph[-y1 + yk].push_back(y2 + yk); //둘중 하나는 아래.
                graph[-y2 + yk].push_back(y1 + yk);
            }
            else if (x1 < x2 && y1 == y2) //아래.
            {
                graph[-y1 + yk].push_back(y2 + yk);
            }
            else if (x1 < x2 && y1 > y2) //왼쪽 아래.
            {
                graph[x1 + xk].push_back(y1 + yk);
                graph[-y1 + yk].push_back(-x1 + xk);
                graph[x2 + xk].push_back(y2 + yk);
                graph[-y2 + yk].push_back(-x2 + xk);
                graph[x1 + xk].push_back(-x2 + xk); //둘중 하나는 왼쪽.
                graph[x2 + xk].push_back(-x1 + xk);
                graph[-y1 + yk].push_back(y2 + yk); //둘중 하나는 아래.
                graph[-y2 + yk].push_back(y1 + yk);
            }

            else if (x1 == x2 && y1 < y2) //오른쪽.
            {
                graph[-x1 + xk].push_back(x2 + xk);
            }
            else if (x1 == x2 && y1 == y2) //안움직임.
            {
                continue;
            }
            else if (x1 == x2 && y1 > y2) //왼쪽.
            {
                graph[x1 + xk].push_back(-x2 + xk);
            }

            else if (x1 > x2 && y1 < y2) //오른쪽 위.
            {
                graph[-x1 + xk].push_back(-y1 + yk);
                graph[y1 + yk].push_back(x1 + xk);
                graph[-x2 + xk].push_back(-y2 + yk);
                graph[y2 + yk].push_back(x2 + xk);
                graph[-x1 + xk].push_back(x2 + xk); //둘중 하나는 오른쪽.
                graph[-x2 + xk].push_back(x1 + xk);
                graph[y1 + yk].push_back(-y2 + yk); //둘중 하나는 위.
                graph[y2 + yk].push_back(-y1 + yk);
            }
            else if (x1 > x2 && y1 == y2) //위.
            {
                graph[y1 + yk].push_back(-y2 + yk);
            }
            else if (x1 > x2 && y1 > y2) //왼쪽 위.
            {
                graph[x1 + xk].push_back(-y1 + yk);
                graph[y1 + yk].push_back(-x1 + xk);
                graph[x2 + xk].push_back(-y2 + yk);
                graph[y2 + yk].push_back(-x2 + xk);
                graph[x1 + xk].push_back(-x2 + xk); //둘중 하나는 왼쪽.
                graph[x2 + xk].push_back(-x1 + xk);
                graph[y1 + yk].push_back(-y2 + yk); //둘중 하나는 위.
                graph[y2 + yk].push_back(-y1 + yk);
            }
        }
        
        for (int i = 0; i <= 5000; i++)
            if (!dfsn[i])
                dfs(i);

        bool ok = true;
        for (int i = 1; i <= n; i++)
            if (scc[i + xk] == scc[-i + xk])
                ok = false;
        for (int i = 1; i <= m; i++)
            if (scc[i + yk] == scc[-i + yk])
                ok = false;

        printf(ok ? "Yes\n" : "No\n");
        init(n, m);
    }
    return 0;
}