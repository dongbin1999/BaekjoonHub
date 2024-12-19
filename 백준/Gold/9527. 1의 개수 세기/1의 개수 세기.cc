#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long

ll f(ll a)
{
	ll ret = 0LL;
	for (ll i = 1LL; i <= 60LL; i++)
	{
		ll power = 1LL << i;
		ret += a / power * power / 2LL + max(0LL, a % power - (1LL << (i - 1)));
	}
	return ret;
}

int main(void)
{
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", f(b + 1LL) - f(a));
	return 0;
}