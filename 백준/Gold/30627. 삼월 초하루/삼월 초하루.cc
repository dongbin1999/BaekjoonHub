#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<pii> try_swap(vector<pii> v,int x,int y){
    if(x!=y&&v[x].first==3&&v[y].second>=5)
        v[y].second-=5,swap(v[x],v[y]);
    return v;
}

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n+1);
    vector<pii> ans(n);
    for(int i=1;i<n;i++)scanf("%d",&v[i]);
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        if(!x)x=3;
        ans[i]={x,v[x]};
    }

    vector<pii> init={{1,100},{2,100},{3,0}};
    map<vector<pii>,vector<pii>> ma;
    queue<pair<vector<pii>,vector<pii>>> q;
    q.push({init,{}}),ma[init]={};

    while(!q.empty()){
        auto [cur,p]=q.front();q.pop();

        for(int i=0;i<3;i++)for(int j=0;j<3;j++){
                vector<pii> nv=try_swap(cur,i,j);
                if(!ma.count(nv)){
                    vector<pii> np=p;
                    np.push_back({j+1,i+1});
                    ma[nv]=np,q.push({nv,np});
                }
            }
    }
    if(!ma.count(ans))printf("-1");
    else{
        printf("%d\n",ma[ans].size());
        for(auto [x,y]:ma[ans])
            printf("%d %d\n",x,y);
    }
    return 0;
}