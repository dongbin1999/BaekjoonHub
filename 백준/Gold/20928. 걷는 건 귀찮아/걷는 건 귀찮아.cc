#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<int> p(n),x(n);
    for(int i=0;i<n;i++)scanf("%d",&p[i]);
    for(int i=0;i<n;i++)scanf("%d",&x[i]);
    int ans=0,mx=p[0]+x[0],i=0;
    while(mx<m){
        ans++;
        pair<int,int> nx={-1,-1};
        while(i+1<n&&mx>=p[i+1])nx=max(nx,{p[i+1]+x[i+1],i+1}),i++;
        if(nx.first==-1)break;
        mx=nx.first;
    }
    printf("%d",mx>=m?ans:-1);
}