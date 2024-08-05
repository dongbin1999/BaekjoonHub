#include<bits/stdc++.h>
using namespace std;
string s[200];
void solve(int n){
    queue<pair<int,string>> q;
    for(int i=0;i<n;i++)s[i]="";
    q.push({1,"1"});s[1]="1";
    while(!q.empty()){
        auto [r,S]=q.front();q.pop();
        int nr=(r*10)%n;string ns=S+'0';
        if(s[nr]=="")q.push({nr,ns}),s[nr]=ns;
        nr=(r*10+1)%n;ns=S+'1';
        if(s[nr]=="")q.push({nr,ns}),s[nr]=ns;
    }
    cout<<s[0]<<endl;
}

int main(){
    while(1){
        int x;scanf("%d",&x);
        if(!x)break;
        solve(x);
    }
    return 0;
}