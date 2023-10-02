#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m[100001],u[100001],mm[100001];

int find(int x){
    if(u[x]<0)return x;
    else return u[x]=find(u[x]);
}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    if(a<b)swap(a,b);
    u[a]+=u[b],u[b]=a;
    return true;
}

int main(){
    memset(u,-1,sizeof(u));
    int n,q;scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%lld",&m[i]),mm[i]=m[i];
    while(q--){
        int c;scanf("%d",&c);
        if(c==1){
            ll i,x;scanf("%lld%lld",&i,&x);
            while(x){
                i=find(i);
                ll d=min(x,m[i]);
                m[i]-=d,x-=d;
                if(i==n||!x)break;
                else merge(i,i+1);
            }
        }
        else{
            int i;scanf("%d",&i);
            printf("%lld\n",mm[i]-m[i]);
        }
    }
    return 0;
}