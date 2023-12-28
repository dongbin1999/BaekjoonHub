#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod[2] = { 998244353,1000000007 }, base = '0' + 1;
ll power[2][100001],a[2][2][100001];
char P[2][100001];

ll get_hash(int s, int e, int n, int x) {
    ll ret[2] = { 0 };
    for (int p = 0; p < 2; p++) {
        ret[p] = (a[x][p][e] - (s ? a[x][p][s - 1] : 0) + mod[p]) % mod[p] * power[p][n - s] % mod[p];
    }
    return ret[0] * mod[1] + ret[1];
}

void init(int n) {
    for(int x=0;x<2;x++)
    for (int p = 0; p < 2; p++)
        for (int i = 0; i <= n; i++) {
            power[p][i] = i ? power[p][i - 1] * base % mod[p] : 1;
            if (i < n)a[x][p][i] = ((i ? a[x][p][i - 1] : 0) + power[p][i] * P[x][i]) % mod[p];
        }
}

int main(){
    int n,k;scanf("%d%d %s %s",&n,&k,P[0],P[1]);
    init(n);
    set<ll> se,ans;
    for(int i=0;i+k<=n;i++)se.insert(get_hash(i,i+k-1,n,0));
    for(int i=0;i+k<=n;i++){
        ll hash=get_hash(i,i+k-1,n,1);
        if(se.count(hash))ans.insert(hash);
    }
    printf("%d",ans.size());
    return 0;
}