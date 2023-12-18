#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define MOD 1000000007

pair<ll,ll> ext(ll a, ll b)
{
	ll s = 0, prev_s = 1;
	ll r = b, prev_r = a;
	ll quotient, bezout_t, temp, gcd;

	while (r != 0)
	{
		quotient = prev_r / r;

		temp = r;
		r = prev_r - quotient * r;
		prev_r = temp;

		temp = s;
		s = prev_s - quotient * s;
		prev_s = temp;
	}

	if (b != 0)
		bezout_t = (prev_r - prev_s * a) / b;
	else
		bezout_t = 0;

	gcd = prev_r;

	return { gcd, bezout_t };
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ll k, c;
		scanf("%lld %lld", &k, &c);
		if (c == 1)
		{
			if (k + 1 <= 1000000000)
				printf("%lld\n", k + 1LL);
			else
				printf("IMPOSSIBLE\n");
			continue;
		}
		if (k == 1)
		{
			printf("%lld\n", 1LL);
			continue;
		}
		pair<ll, ll> ans = ext(k, c);
		if (ans.first != 1)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}

		printf("%lld\n", (ans.second + 1000000000LL * k) % k);
	}
	return 0;
}