#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (ll)1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%MOD;a=a*a%MOD;b/=2;}return ret;}
const int MAX = 250000;

int dfsn[MAX*2+1],dfsnumber,scc[MAX*2+1],sccnumber,val[MAX+1];
vector<int> graph[MAX*2+1],group[MAX*2+1];
stack<int> s;
pii tsort[MAX*2+1];

int dfs(int node)
{
    dfsn[node]=++dfsnumber;
    s.push(node);
    int topmost=dfsn[node];
    for(int to:graph[node])
        if(!dfsn[to]) topmost=min(topmost, dfs(to));
        else if(!scc[to]) topmost=min(topmost,dfsn[to]);

    if(topmost==dfsn[node])
    {
        ++sccnumber;
        while(true)
        {
            int t=s.top();
            s.pop();
            scc[t]=sccnumber;
            group[sccnumber].push_back(t);
            if(t==node) break;
        }
    }
    return topmost;
}

int main()
{
    int n;scanf("%d",&n);
    int nn=5*n,me,me2,num;
    fill(val,val+1+nn,-1);
    for(int i=1;i<=n;i++)
    {
        //2^4비트랑 2^3비트 둘중에 하나만 켜져야하고, 2^4비트가 켜지면 2^2비트는 켜면 안됨.
        me=(i-1)*5+5,me2=(i-1)*5+4;
        graph[-me+nn].push_back(me2+nn);
        graph[-me2+nn].push_back(me+nn);
        graph[me+nn].push_back(-me2+nn);
        graph[me2+nn].push_back(-me+nn);
        me2=(i-1)*5+3;
        graph[me+nn].push_back(-me2+nn);
        graph[me2+nn].push_back(-me+nn);

        scanf("%d",&num);
        if(num)
        {
            for(int bit=4;bit>=0;bit--)
                if(num&(1<<bit))
                {
                    me=(i-1)*5+bit+1;
                    graph[-me+nn].push_back(me+nn);
                }
                else
                {
                    me=(i-1)*5+bit+1;
                    graph[me+nn].push_back(-me+nn);
                }
        }
    }
    int m;scanf("%d",&m);
    while(m--)
    {
        char c;int x,y,z;
        scanf(" %c %d %d %d",&c,&x,&y,&z);
        num=z;
        if(c=='&')
        {
            for(int bit=4;bit>=0;bit--)
                if(num&(1<<bit))//두비트 모두 켬.
                {
                    me=(x-1)*5+bit+1,me2=(y-1)*5+bit+1;
                    graph[-me+nn].push_back(me+nn);
                    graph[-me2+nn].push_back(me2+nn);
                }
                else//하나 이상 끔.
                {
                    me=(x-1)*5+bit+1,me2=(y-1)*5+bit+1;
                    graph[me+nn].push_back(-me2+nn);
                    graph[me2+nn].push_back(-me+nn);
                }
        }
        else
        {
            for(int bit=4;bit>=0;bit--)
                if(num&(1<<bit))//하나 이상 켬.
                {
                    me=(x-1)*5+bit+1,me2=(y-1)*5+bit+1;
                    graph[-me+nn].push_back(me2+nn);
                    graph[-me2+nn].push_back(me+nn);
                }
                else//두비트 모두 끔.
                {
                    me=(x-1)*5+bit+1,me2=(y-1)*5+bit+1;
                    graph[me+nn].push_back(-me+nn);
                    graph[me2+nn].push_back(-me2+nn);
                }
        }
    }
    for(int i=0;i<=nn*2;i++)
        if(!dfsn[i]) dfs(i);

    bool ok=true;
    for(int i=1;i<=nn;i++)
        if(scc[i+nn]==scc[-i+nn])
            ok=false;

    for(int i=0;i<=2*nn;i++)
        tsort[i]={scc[i],i};
    sort(tsort,tsort+1+2*nn,greater<pii>());

    for(int i=0;i<=2*nn;i++)
        if(val[abs(-tsort[i].second+nn)]==-1)
            val[abs(-tsort[i].second+nn)]=-tsort[i].second+nn>0;

    if(ok)
    {
        printf("1\n");
        vector<int> ans;
        for(int i=0;i<nn;i+=5)
        {
            int temp=0;
            for(int j=0;j<=4;j++)
                temp+=(1<<j)*val[i+j+1];
            ans.push_back(temp);
        }
        for(int i:ans) printf("%d ",i);
    }
    else
        printf("0");
    return 0;
}