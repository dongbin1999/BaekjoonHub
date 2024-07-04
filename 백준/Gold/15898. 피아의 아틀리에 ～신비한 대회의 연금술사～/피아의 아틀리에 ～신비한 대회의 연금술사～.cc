#include <cstdio>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define MOD (ll)1000000007

struct item
{
	int v[6][6];
	char c[6][6];
};

item a[11];
int ans = 0;

item spin(item t, int o)
{
	item temp;
	if (o == 1)
	{
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				temp.c[i][j] = t.c[i][j];
				temp.v[i][j] = t.v[i][j];
			}
	}
	if (o == 2)
	{
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				temp.c[i][j] = t.c[5 - i][5 - j];
				temp.v[i][j] = t.v[5 - i][5 - j];
			}
	}
	if (o == 3)
	{
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				temp.c[i][j] = t.c[j][5 - i];
				temp.v[i][j] = t.v[j][5 - i];
			}
	}
	if (o == 4)
	{
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				temp.c[i][j] = t.c[5 - j][i];
				temp.v[i][j] = t.v[5 - j][i];
			}
	}
	return temp;
}

item board;

void f(item a, item b, item c, int x, int y, int z)
{
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
		{
			board.v[i + x/2][j + x%2] += a.v[i][j];
			board.v[i + x/2][j + x%2] = min(9, board.v[i + x/2][j + x%2]);
			board.v[i + x/2][j + x%2] = max(0, board.v[i + x/2][j + x%2]);
			if (a.c[i][j] == 'W')
				continue;
			board.c[i + x/2][j + x%2] = a.c[i][j];
		}
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
		{
			board.v[i + y/2][j + y%2] += b.v[i][j];
			board.v[i + y/2][j + y%2] = min(9, board.v[i + y/2][j + y%2]);
			board.v[i + y/2][j + y%2] = max(0, board.v[i + y/2][j + y%2]);
			if (b.c[i][j] == 'W')
				continue;
			board.c[i + y/2][j + y%2] = b.c[i][j];
		}
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
		{
			board.v[i + z/2][j + z%2] += c.v[i][j];
			board.v[i + z/2][j + z%2] = min(9, board.v[i + z/2][j + z%2]);
			board.v[i + z/2][j + z%2] = max(0, board.v[i + z/2][j + z%2]);
			if (c.c[i][j] == 'W')
				continue;
			board.c[i + z/2][j + z%2] = c.c[i][j];
		}
}


void go(int x, int y, int z, int i, int j, int k)
{
	item temp[3] = { spin(a[x],i),spin(a[y],j),spin(a[z],k) };

	for (int a = 0; a <= 3; a++)
		for (int b = 0; b <= 3; b++)
			for (int c = 0; c <= 3; c++)
			{
				int cur = 0;
				for (int u = 1; u <= 5; u++)
					for (int g = 1; g <= 5; g++)
						board.c[u][g] = board.v[u][g] = 0;
				f(temp[0], temp[1], temp[2], a, b, c);
				for (int u = 1; u <= 5; u++)
					for (int g = 1; g <= 5; g++)
						switch (board.c[u][g])
						{
						case 'R':
							cur += 7 * board.v[u][g];
							break;
						case 'B':
							cur += 5 * board.v[u][g];
							break;
						case 'G':
							cur += 3 * board.v[u][g];
							break;
						case 'Y':
							cur += 2 * board.v[u][g];
							break;
						default:
							break;
						}
				ans = max(ans, cur);
			}
}

int main()
{
	int n;

	scanf("%d", &n);
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				scanf("%d", &a[k].v[i][j]);
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				scanf(" %c", &a[k].c[i][j]);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
			{
				if (i != j && j != k && k != i)
					for (int l = 1; l <= 4; l++)
						for (int m = 1; m <= 4; m++)
							for (int o = 1; o <= 4; o++)
								go(i, j, k, l, m, o);
			}
	printf("%d", ans);
	return 0;
}