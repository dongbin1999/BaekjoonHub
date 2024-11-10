#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    int x;scanf("%d",&x);
    ll ret=0,cnt=0;
    for(auto i:v)if(gcd(i,x)==1)ret+=i,cnt++;
    printf("%.10lf",(double)ret/cnt);
}
