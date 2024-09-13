#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(auto &i:v)scanf("%d",&i);
    if(n==1)return !printf("%d",abs(v[0]));
    int ans=abs(v[0]-v.back());
    for(int i=1;i<n;i++)ans=gcd(ans,abs(v[i]-v[i-1]));
    printf("%d",ans);
}