#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    int n,q;cin>>n>>s>>q;
    while(q--){
        int x,y;cin>>x>>y;x--,y--;
        int ans=0;
        for(int l=x,r=y;l<r;l++){
            if(r-l+1&1)continue;
            int t=0,le=l,ri=r;
            while(le<ri)t+=s[le++]==s[ri--];
            ans=max(ans,t);
        }
        for(int l=x,r=y;l<r;r--){
            if(r-l+1&1)continue;
            int t=0,le=l,ri=r;
            while(le<ri)t+=s[le++]==s[ri--];
            ans=max(ans,t);
        }
        cout<<ans<<'\n';
    }
}