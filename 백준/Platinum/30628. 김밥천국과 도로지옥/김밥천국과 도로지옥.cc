#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tup;

const int mx=60;
vector<pii> graph[100001];
int dp[100001][8][2];

int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    while(m--){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        assert(a<b);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    map<int,int> ma;ma[2]=1,ma[3]=2,ma[6]=4;
    map<int,int> rma;rma[0]=2,rma[1]=3,rma[2]=6;
    memset(dp,0x3f,sizeof(dp));
    priority_queue<tup,vector<tup>,greater<tup>> pq;pq.push({0,1,0});
    while(!pq.empty()){
        auto [dist,cur,state]=pq.top();pq.pop();
        if(dp[cur][state][0]<1e9)continue;
        dp[cur][state][0]=dist;
        for(auto [nx,cost]:graph[cur]){
            int ns=state|ma[cost];
            pq.push({dist+cost,nx,ns});
        }
    }
    pq.push({0,n,0});
    while(!pq.empty()){
        auto [dist,cur,state]=pq.top();pq.pop();
        if(dp[cur][state][1]<1e9)continue;
        dp[cur][state][1]=dist;
        for(auto [nx,cost]:graph[cur]){
            int ns=state|ma[cost];
            pq.push({dist+cost,nx,ns});
        }
    }
    for(int i=1;i<=n;i++)
        for(int ns=0;ns<8;ns++)for(int os=0;os<8;os++){
                if(k-dp[i][ns][0]-dp[i][os][1]<0)continue;
                int r=k-dp[i][ns][0]-dp[i][os][1];r%=mx;
                vector<int> vis(mx+1);vis[0]=1;
                int x=ns|os;
                for(int go=0;go<3;go++)for(int back=0;back<3;back++){
                        if(!(x>>go&1)||!(x>>back&1))continue;
                        int goback=rma[go]+rma[back];
                        for(int j=0;j+goback<=mx;j++)vis[j+goback]|=vis[j];
                    }
                if(vis[r])return !printf("YES");
            }
    printf("NO");
    return 0;
}