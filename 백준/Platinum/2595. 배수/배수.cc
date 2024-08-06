#include<bits/stdc++.h>
using namespace std;
typedef pair<int,string> pis;
#define over(s) (s.size()>5||stoi(s)>n)
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
int n;
set<vector<int>> se;

bool operator<(pis a,pis b){
    if(a.first==b.first)
        return a.second.size()==b.second.size()?a>b:a.second.size()>b.second.size();
    else return a.first>b.first;
}

string b[2][30000];
pis f(vector<int> v){
    for(int i=0;i<n;i++)b[0][i].clear(),b[1][i].clear();
    queue<pis> q;
    for(auto i:v){
        if(!i)continue;
        string s=to_string(i);
        int x=over(s),y=i%n;
        if(b[x][y]!="")continue;
        q.push({y,to_string(i)}),b[x][y]=1;
    }
    while(!q.empty()){
        auto [r,s]=q.front();q.pop();
        if(!r)return {v.size(),s};
        for(auto ni:v){
            string ns=s+to_string(ni);
            int nx=over(ns),ny=(r*10+ni)%n;
            if(b[nx][ny]!="")continue;
            q.push({ny,ns}),b[nx][ny]=1;
        }
    }
    return {9,""};
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<100000;i++){
        vector<int> v;int x=i;
        while(x)v.push_back(x%10),x/=10;
        UNIQUE(v);
        se.insert(v);
    }
    pis ans={9,""};
    for(auto v:se){
        if(ans.first<v.size())continue;
        pis x=f(v);
        if(ans<x)ans=x;
    }
    cout<<ans.second;
    return 0;
}