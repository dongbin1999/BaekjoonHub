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

int dfsn[MAX * 2 + 1], dfsnumber, scc[MAX * 2 + 1], sccnumber, indegree[MAX * 2 + 1], val[MAX + 1];
vector<int> graph[MAX * 2 + 1], dag[MAX * 2 + 1], group[MAX * 2 + 1];
stack<int> s;
pii tsort[MAX * 2 + 1];

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
            group[sccnumber].push_back(t);
            if (t == node)
                break;
        }
    }
    return topmost;
}

int main(void)
{
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    fill(val, val + 1 + n, -1);
    while (m--)
    {
        scanf("%d %d", &x, &y);
        graph[-x + n].push_back(y + n);
        graph[-y + n].push_back(x + n);
    }

    for (int i = 0; i <= n * 2; i++)
        if (!dfsn[i])
            dfs(i);

    bool ok = true;
    for (int i = 1; i <= n; i++)
        if (scc[i + n] == scc[-i + n])
            ok = false;

    for (int i = 0; i <= 2 * n; i++)
        tsort[i] = { scc[i], i };
    sort(tsort, tsort + 1 + 2 * n, greater<pii>());

    for (int i = 0; i <= 2 * n; i++)
        if (val[abs(-tsort[i].second + n)] == -1)
            val[abs(-tsort[i].second + n)] = -tsort[i].second + n > 0;

    if (ok)
    {
        printf("1\n");
        for (int i = 1; i <= n; i++)
            printf("%d ", val[i]);
    }
    else
        printf("0");
	return 0;
}