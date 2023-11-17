#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
const int sz = 1 << 17;

int arr[1 << 18], ans[100001];

void construct()
{
	for (int i = sz - 1; i >= 1; i--)
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
}

void update(int i, int val)
{
	i += sz;
	arr[i] = val;
	while (i > 1)
	{
		i /= 2;
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}
}

int temp;
void space(int r, int node, int ns, int ne)
{
	if (ns > ne)
		return;
	if (arr[node] >= r)
	{
		temp = min(temp, ne);
		if (ns != ne)
			space(r, node * 2, ns, (ns + ne) / 2);
	}
	else
		space(r - arr[node], node + 1, ne + 1, 2 * ne - ns + 1);
}

int main()
{
	int n, a;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		arr[i + sz] = 1;
	construct();

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		temp = n;
		space(a + 1, 1, 0, sz - 1);
		update(temp, 0);
		ans[temp] = i;
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;
}