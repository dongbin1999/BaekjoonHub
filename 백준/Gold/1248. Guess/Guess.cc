#include <bits/stdc++.h>
using namespace std;
char a[10][10];
int n,sum;
void go(vector<int> &v){
    if(v.size()==n){
        for(auto i:v)printf("%d ",i);
        exit(0);
    }
    int mn=-10,mx=10,x=v.size(),s=sum;
    for(int i=0;i<=x;i++){
        if(a[i][x]=='+')mn=max(mn,1-s);
        else if(a[i][x]=='-')mx=min(mx,-1-s);
        else mn=max(mn,-s),mx=min(mx,-s);
        if(i<x)s-=v[i];
    }

    for(int i=mn;i<=mx;i++){
        v.push_back(i),sum+=i;
        go(v);
        v.pop_back(),sum-=i;
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j=i;j<n;j++)scanf(" %c",&a[i][j]);
    vector<int> v;
    go(v);
}