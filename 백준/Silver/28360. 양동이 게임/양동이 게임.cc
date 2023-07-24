#include <bits/stdc++.h>
using namespace std;
vector<int> graph[51];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<double> ans(n+1);
    vector<int> in(n+1);
    ans[1]=100.0;
    while(m--){
        int v,w;scanf("%d%d",&v,&w);
        graph[v].push_back(w),in[w]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)if(!in[i])q.push(i);
    while(!q.empty()){
        int cur=q.front();q.pop();
        int d=graph[cur].size();
        if(!d)continue;
        for(auto nx:graph[cur]){
            ans[nx]+=ans[cur]/(double)d,in[nx]--;
            if(!in[nx])q.push(nx);
        }
        ans[cur]=0;
    }
    printf("%.9lf",*max_element(ans.begin(),ans.end()));
    return 0;
}