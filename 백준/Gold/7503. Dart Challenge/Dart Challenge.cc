#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

bool b[51][15001];

void solve(){
    int a,k;scanf("%d%d",&a,&k);
    vector<int> v(a);
    multiset<int> se;
    for(int i=0;i<a;i++){
        scanf("%d",&v[i]);
        se.insert(v[i]),se.insert(v[i]*2),se.insert(v[i]*3);
    }
    se.erase(se.find(*max_element(v.begin(),v.end())*3));
    set<int> s;for(auto i:se)s.insert(i);
    memset(b,0,sizeof(b));
    b[0][0]=1;
    queue<pii> q;q.push({k,0});
    set<int> ans;
    while(!q.empty()){
        auto [K,num]=q.front();q.pop();
        ans.insert(num);
        for(auto d:s){
            int nx=num+d;
            if(K>0&&!b[K-1][nx])q.push({K-1,nx}),b[K-1][nx]=1;
        }
    }
    printf("%d\n\n",ans.size());
}

int main(){
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Scenario #%d:\n",i);
        solve();
    }
    return 0;
}