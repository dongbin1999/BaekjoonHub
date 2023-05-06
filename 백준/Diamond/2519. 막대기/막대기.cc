#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int sz=3000;
#define X first
#define Y second
#define pb push_back

struct segment{pll A,B;}s[3001];
ll ccw(pll A,pll B,pll C){
    return A.X*B.Y+B.X*C.Y+C.X*A.Y-(A.Y*B.X+B.Y*C.X+C.Y*A.X);}

bool intersect(segment s1,segment s2){
    pll a=s1.A,b=s1.B,c=s2.A,d=s2.B;
    ll check[4]={ccw(a,b,c),ccw(a,b,d),ccw(c,d,a),ccw(c,d,b)};
    for(int i=0;i<4;i++)
        check[i]=check[i]<0?-1:check[i]!=0;
    ll ab=check[0]*check[1],cd=check[2]*check[3];
    return ab<=0&&cd<=0;
}

int dfsn[sz*2+1], dfsnumber, scc[sz*2+1], sccnumber, indegree[sz*2+1], val[sz+1];
vector<int> graph[sz*2+1], dag[sz*2+1], group[sz*2+1];
stack<int> st;
pii tsort[sz*2+1];

int dfs(int node){
    dfsn[node] = ++dfsnumber;
    st.push(node);

    int topmost = dfsn[node];
    for(auto i:graph[node]){
        if(!dfsn[i])topmost=min(topmost,dfs(i));
        else if(!scc[i])topmost=min(topmost,dfsn[i]);
    }

    if(topmost == dfsn[node]){
        ++sccnumber;
        while(1){
            int t=st.top();st.pop();
            scc[t]=sccnumber;
            group[sccnumber].pb(t);
            if(t==node)break;
        }
    }
    return topmost;
}

int main(){
    int n;scanf("%d",&n);n*=3;
    for(int i=1;i<=n;i++)
        scanf("%lld %lld %lld %lld",&s[i].A.X,&s[i].A.Y,&s[i].B.X,&s[i].B.Y);
    fill(val,val+1+n,-1);
    for(int i=1;i<=n;i++){
       if(i%3==0){
           int a=i-2,b=i-1,c=i;
           graph[-a+n].pb(b+n);
           graph[-b+n].pb(a+n);
           graph[-a+n].pb(c+n);
           graph[-c+n].pb(a+n);
           graph[-b+n].pb(c+n);
           graph[-c+n].pb(b+n);
       }
       for(int j=i+1;j<=n;j++)
           if(intersect(s[i],s[j])){
               graph[i+n].pb(-j+n);
               graph[j+n].pb(-i+n);
           }
    }
    
    for(int i=0;i<=n*2;i++)if(!dfsn[i])dfs(i);
    bool ok=true;
    for(int i=1;i<=n;i++)ok&=scc[i+n]!=scc[-i+n];

    for(int i=0;i<=2*n;i++)tsort[i]={scc[i],i};
    sort(tsort,tsort+1+2*n,greater<pii>());
    for(int i=0;i<=2*n;i++)
        if(val[abs(-tsort[i].second+n)]==-1)
            val[abs(-tsort[i].second+n)]=-tsort[i].second+n>0;

    if(!ok) return !printf("-1");
    vector<int> v;
    for(int i=1;i<=n;i++)
        if(!val[i])v.push_back(i);
    printf("%d\n",v.size());
    for(auto i:v)printf("%d ",i);
    return 0;
}