#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
typedef pair<ll,vector<ll>> plv;
pil fix={-1,-1};//i번째 정점의 값은 j일 수밖에 없다.

vector<pil> graph[100001];
int vis[100001],n;
ll val[100001];

//한 노드의 값을 정하면, 모든 노드의 값이 정해진다.
void go(ll v,int node=1,int pre=-1,int order=0){
    //답이 유일하면 go2로 답구하기.
    if(fix.first!=-1)return;
    vis[node]=order,val[node]=v;
    for(auto [nx,cost]:graph[node]){
        if(nx==pre)continue;
        if(vis[nx]==-1)go(cost-v,nx,node,order+1);
        else{
            int cyclesz=order+1-vis[nx];
            //크기가 홀수인 사이클에서
            if(cyclesz&1){
                //어떤 값이 안맞으면,
                if(val[node]+val[nx]!=cost){
                    ll diff=val[node]+val[nx]-cost;
                    //근데 차이가 홀수다? 그럼 답 없음.
                    if(diff&1){
                        printf("No");
                        exit(0);
                    }
                        //(양쪽 정점 합-해당간선)/2를 시작한 정점(지금 막 중복된 간선)에서 뺀다.
                    else fix={nx,val[nx]-diff/2};
                    return;
                }
                else return;
            }
                //크기가 짝수인 사이클은, 걍 안되면 안되는거야.
            else if(val[node]+val[nx]!=cost){
                printf("No");
                exit(0);
            }
        }
    }
}

void go2(ll v,int node){
    val[node]=v,vis[node]=1;
    for(auto [nx,cost]:graph[node])
        if(vis[nx]==-1)go2(cost-v,nx);
}

plv f(ll d){
    memset(vis,-1,sizeof(vis));
    go(d,1);
    plv tmp={0,{}};
    for(int i=1;i<=n;i++)tmp.first+=abs(val[i]),tmp.second.push_back(val[i]);
    return tmp;
}

plv ternary_search(){
    plv ans={2e18,{}};
    ll l=-2e12,r=2e12,lmid,rmid;
    while(l+30<r){
        lmid=(l+l+r)/3,rmid=(l+r+r)/3;
        if(f(lmid)<f(rmid))r=rmid;
        else l=lmid;
    }
    for(ll i=l;i<=r;i++)ans=min(ans,f(i));
    return ans;
}

int main(){
    int m;scanf("%d%d",&n,&m);
    while(m--){
        int a,b;ll c;scanf("%d%d%lld",&a,&b,&c);
        graph[a].push_back({b,c}),graph[b].push_back({a,c});
    }
    auto [a,b]=ternary_search();
    if(fix.first!=-1){
        memset(vis,-1,sizeof(vis));
        go2(fix.second,fix.first);
        for(int i=1;i<=n;i++)for(auto [j,cost]:graph[i])
                if(cost!=val[i]+val[j])return !printf("No");
        printf("Yes\n");
        for(int i=1;i<=n;i++)printf("%lld ",val[i]);
    }
    else{
        printf("Yes\n");
        for(auto i:b)printf("%lld ",i);
    }
}