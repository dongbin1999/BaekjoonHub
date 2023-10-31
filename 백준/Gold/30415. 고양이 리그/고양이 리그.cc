#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll LCM(ll a,ll b){return a*b/GCD(a,b);}

map<int,int> ma;
int n,m;
vector<int> d;
pair<int,vector<int>> ans={2e9,{}};
void go(int pick,vector<int> &v){
    if(pick==d.size()){
        for(int i=0;i<v.size();i++){
            if(!v[i]||v[i]==n)return;
            for(int j=i+1;j<v.size();j++)
                if(v[i]==v[j]||LCM(v[i],v[j])!=n)return;
        }
        ans=min(ans,{accumulate(v.begin(),v.end(),0),v});
        return;
    }
    for(int i=0;i<v.size();i++){
        int pre=v[i];
        v[i]/=d[pick];
        go(pick+1,v);
        v[i]=pre;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    int nn=n;
    for(int i=2;i*i<=n;i++)
        while(nn%i==0)(!ma[i]?ma[i]=i:ma[i]*=i),nn/=i;
    if(nn>1)ma[nn]=nn;
    for(auto [x,y]:ma)d.push_back(y);
    vector<int> v(m,n);
    if(m>10)return !printf("-1");
    go(0,v);
    if(ans.first==2e9)printf("-1");
    else for(auto i:ans.second)printf("%d ",i);
    return 0;
}