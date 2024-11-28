#include <bits/stdc++.h>
using namespace std;
void solve(){
    int l,r;scanf("%d%d",&l,&r);
    if(r>3){printf("%d\n",r);return;}
    string s;
    for(int i=l;i<=r;i++)s+=to_string(1<<i);
    int ans=0,x=stoll(s);
    while(x%2==0)ans++,x/=2;
    printf("%d\n",ans);
}
int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}