#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int sz = 1 << 19;

int arr[sz * 2];
pii a[500001], b[500001];

void update(int i)
{
    i += sz;
    arr[i]++;
    while (i > 1)
    {
        i /= 2;
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }
}

int sum(int s, int e, int node, int ns, int ne)
{
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return arr[node];
    int mid = (ns + ne) / 2;
    return sum(s, e, node * 2, ns, mid) + sum(s, e, node * 2 + 1, mid + 1, ne);
}

int main()
{
    int n, num = 0;
    ll ans = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].first), a[i].second = i, b[i].first = i;

    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i].first != a[i - 1].first)
            num++;
        b[a[i].second].second = num;
    }
    sort(b + 1, b + 1 + n);

    for (int i = n; i >= 1; i--)
    {
        update(b[i].second);
        ans += (ll)sum(0, b[i].second - 1, 1, 0, sz - 1);
    }
    printf("%lld", ans);
}