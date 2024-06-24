#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<int> dag[3001];

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n+1),in(n+1);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
            if(__gcd(v[i],v[j])>1)
                dag[i].push_back(j),in[j]++;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=1;i<=n;i++)if(!in[i])pq.push({v[i],i});
    vector<int> ans;
    while(!pq.empty()){
        auto [val,idx]=pq.top();pq.pop();
        ans.push_back(val);
        for(auto nx:dag[idx])
            if(--in[nx]==0)pq.push({v[nx],nx});
    }
    for(auto i:ans)printf("%d ",i);
    return 0;
}