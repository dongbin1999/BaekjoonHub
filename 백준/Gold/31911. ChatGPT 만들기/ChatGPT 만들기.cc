#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[400000];

int main(){
    int n,m;ll k;scanf("%d %lld %d",&n,&k,&m);k--;
    map<char,map<char,int>> ma;
    map<char,char> ans;
    while(n--){
        scanf("%s",s);int sz=strlen(s);
        for(int i=0;i<sz-1;i++)ma[s[i]][s[i+1]]++;
    }
    for(auto [a,b]:ma){
        int mx=-1;char x;
        for(auto [c,cnt]:b)if(mx<cnt)x=c,mx=cnt;
        else if(mx==cnt)x=min(x,c);
        ans[a]=x;
    }
    vector<char> v={'['};
    while(v.back()!=']'&&v.size()<50)v.push_back(ans[v.back()]);
    if(v.size()>40){//사이클 존재
        array<int,3> cycle={INT_MAX,-1,-1};
        for(int i=0;i<v.size();i++)for(int j=i+1;j<v.size();j++)
            if(v[i]==v[j])cycle=min(cycle,{j-i,i,j-1});
        auto [len,l,r]=cycle;
        for(ll i=k;i<k+m;i++)
            if(i<l)printf("%c",v[i]);
            else printf("%c",v[(i-l)%len+l]);
    }
    else{
        for(ll i=k;i<k+m;i++)
            if(v.size()<=i)printf(".");
            else printf("%c",v[i]);
    }
    return 0;
}