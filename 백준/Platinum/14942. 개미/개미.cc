#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int sz=17;

vector<pii> tree[100001];
int p[100001],s[1<<sz][sz],d[100001];
void go(int node=1,int dep=0,int pa=1){
    s[node][0]=pa,d[node]=dep;
    for(int i=1;i<sz;i++)
        s[node][i]=s[s[node][i-1]][i-1];
    for(auto [nx,c]:tree[node])
        if(pa!=nx)go(nx,dep+c,node);
}

int main() {
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&p[i]);
    for(int i=1;i<n;i++){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }
    go();
    for(int i=1;i<=n;i++){
        int cur=i,power=p[i];
        for(int j=sz-1;j>=0;j--)
            if(power>=d[cur]-d[s[cur][j]])
                power-=d[cur]-d[s[cur][j]],cur=s[cur][j];
        printf("%d\n",cur);
    }
}