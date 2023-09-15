#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<math.h>
#include<algorithm>
#include<set>
#include<bitset>
#include<assert.h>
#include<string>
using namespace std;
typedef long long ll;
const ll mod[2] = { 998244353,1000000007 }, base = 'z' + 1;
ll power[250001][2],a[250001][2];
char P[250002];


ll get_hash(int s, int e, int n) {
	ll ret[2] = { 0 };
	for (int p = 0; p < 2; p++) {
		ret[p] = (a[e][p] - (s ? a[s - 1][p] : 0) + mod[p]) % mod[p] * power[n - s][p] % mod[p];
	}
	return ret[0] * mod[1] + ret[1];
}
void init(int n) {
	for (int p = 0; p < 2; p++)
		for (int i = 0; i <= n; i++) {
			power[i][p] = i ? power[i - 1][p] * base % mod[p] : 1;
			if (i < n)a[i][p] = ((i ? a[i - 1][p] : 0) + power[i][p] * P[i]) % mod[p];
		}
}

int main(){
	int n; scanf("%d %s", &n, P);
	init(n);
	int l = 0, r = n, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		map<ll, int> ma;
		bool ok = 0;
		for (int s = 0, e = mid - 1; e < n; s++, e++)
			ma[get_hash(s, e, n)]++, ok |= ma[get_hash(s, e, n)] > 1;
		if (ok)ans = max(ans, mid), l = mid + 1;
		else r = mid - 1;
	}
	printf("%d", ans);
	return 0;
}