#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;scanf("%d",&n);
    vector<int> a(n+1);
    for(int i=n/2+1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=n;i>1;i-=2){
        int x=min(a[i],a[i-1]);
        a[i/2]+=x,a[i]-=x,a[i-1]-=x;
    }
    printf("%d\n", accumulate(a.begin(), a.end(),0));
}
int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}