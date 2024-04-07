#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);n--;
    vector<vector<int>> v(32-__builtin_clz(n));
    printf("%d\n",v.size());
    int mx=0;
    for(int i=1;i<=n;i++)for(int b=0;b<v.size();b++)
        if(i>>b&1)v[b].push_back(i),mx=max(mx,(int)v[b].size());
    for(auto &i:v){
        if(i.size()==mx)continue;
        reverse(i.begin(),i.end());
        while(i.size()<mx)i.push_back(i.back()-1);
    }
    printf("%d\n",mx);
    for(auto i:v){
        for(auto j:i)printf("%d ",j);
        printf("\n");
    }
}