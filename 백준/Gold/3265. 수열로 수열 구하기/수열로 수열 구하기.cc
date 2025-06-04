#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],c[100001];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    set<int> se;
    vector<int> v;
    for(int i=1;i<=n;i++){
        se.insert(i),scanf("%d",&b[i]);
        if(b[i])v.push_back(i);
    }
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        se.erase(y),a[x]=y;
    }
    int cur=1;
    for(auto i:v)while(cur<=i){
        if(a[cur]){cur++;continue;}
        auto it=se.upper_bound(i);
        if(it==se.begin())return !printf("-1");
        it=prev(it);
        a[cur]=*it,se.erase(it),cur++;
    }

    int mex=0;
    for(int i=1;i<=n;i++){
        c[a[i]]=1;
        while(c[mex+1])mex++;
        if((mex==i)!=b[i])return !printf("-1");
    }
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
}