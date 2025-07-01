#include<bits/stdc++.h>
using namespace std;

void solve(){
    int ans=0,cur=0;
    string s;cin>>s;
    string ss;
    for(int i=s.size()-1;i>=0;i--){
        if(!cur)ans+=1+(s[i]=='C'),cur++,ss+=')';
        else if(s[i]=='C') cur--,ss+='(';
        else ans++,cur++,ss+=')';
    }
    reverse(ss.begin(),ss.end());
    assert(cur%2==0);
    for(int i=0;i<ss.size();i++)if(s[i]=='U'&&cur)cur-=2,ss[i]='(';
    cout<<ans<<'\n'<<ss<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    while(n--)solve();
}