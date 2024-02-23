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
#include <unordered_map>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD (ll)1000000007
const int MAX = 1000000;

unordered_map<char, int> trie[MAX + 1];
int numbering, cnt[MAX + 1];

int go(int now, int typing)
{
	int ret = cnt[now] * typing, plus = 0;
	if (now == 0 || trie[now].size() > 1 || cnt[now])
		plus++;

	for (auto it = trie[now].begin(); it != trie[now].end(); it++)
		ret += go(it->second, typing + plus);

	return ret;
}

void init()
{
	for (int i = 0; i <= numbering; i++)
		trie[i].clear(), cnt[i] = 0;
	numbering = 0;
}

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		char a[81];
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", a);
			int as = strlen(a);
			sum += as;
			int now = 0, next;
			for (int j = 0; j < as; j++)
			{
				next = a[j];
				if (trie[now][next] == 0)
					trie[now][next] = ++numbering;
				now = trie[now][next];
			}
			cnt[now]++;
		}

		printf("%.2lf\n", (double)go(0, 0) / (double)n);
		init();
	}
	
	return 0;
}