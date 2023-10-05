#include<bits/stdc++.h>
using namespace std;

set<string> vis[50][50];
struct S{int l,r,dist;string s;};
string rev(string s,int l,int r){
    while(l<r)swap(s[l],s[r]),l++,r--;
    return s;
}
bool check(string a,string b,int l,int r){
    for(int i=0;i<b.size();i++){
        if(l<=i&&i<=r)continue;
        if(a[i]!=b[i])return false;
    }
    return true;
}

int main(){
    string a,b;cin>>a>>b;
    int n=a.size();
    vis[0][n-1].insert(a);
    queue<S> q;q.push({0,n-1,0,a});
    while(!q.empty()){
        S cur=q.front();q.pop();
        if(cur.s==b)return !printf("%d",cur.dist);
        for(int l=cur.l;l<=cur.r;l++)for(int r=l+1;r<=cur.r;r++){
            string ns=rev(cur.s,l,r);
            if(!vis[l][r].count(ns)&&check(ns,b,l,r))
                vis[l][r].insert(ns),q.push({l,r,cur.dist+1,ns});
        }
    }
    printf("-1");
    return 0;
}