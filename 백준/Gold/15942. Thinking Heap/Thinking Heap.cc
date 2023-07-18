#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,p;scanf("%d%d%d",&n,&k,&p);
    vector<int> ans(n+1,-1),idx(n+1,-1);
    if(32-__builtin_clz(p)>k)return !printf("-1");
    int pp=p,kk=k;
    while(pp>1)pp/=2,kk=32-__builtin_clz(pp),ans[pp]=kk,idx[kk]=pp;
    queue<int> q;q.push(p);
    while(!q.empty()){
        int cur=q.front();q.pop();
        if(k>n)return !printf("-1");
        else ans[cur]=k,idx[k]=cur,k++;
        if(cur*2<=n)q.push(cur*2);
        if(cur*2+1<=n)q.push(cur*2+1);
    }
    int num=1;
    for(int i=1;i<=n;i++){
        if(ans[i]==-1){
            while(idx[num]!=-1)num++;
            ans[i]=num,idx[num]=i;
        }
        printf("%d\n",ans[i]);
    }
    return 0;
}