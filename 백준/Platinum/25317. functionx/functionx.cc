#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod=1000000007;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}
const int sz=1<<18;
ll pl[sz*2],mi[sz*2],pllazy[sz*2],milazy[sz*2];

void propagate(int node,int ns,int ne,int c)
{
    if(!(c?pllazy:milazy)[node]) return;//(2)
    if(node<sz)
    {
        (c?pllazy:milazy)[node*2]+=(c?pllazy:milazy)[node];//(3)
        (c?pllazy:milazy)[node*2+1]+=(c?pllazy:milazy)[node];//(4)
    }
    (c?pl:mi)[node]+=(c?pllazy:milazy)[node]*(ll)(ne-ns+1);//(5)
    (c?pllazy:milazy)[node]=0LL;//(6)
}

void update(int s,int e,ll k,int node,int ns,int ne,int c)
{
    propagate(node,ns,ne,c);
    if(e<ns||ne<s)return;
    if (s<=ns&&ne<=e)
    {
        (c?pllazy:milazy)[node]+=k;//(7)
        propagate(node,ns,ne,c); return;
    }
    int mid=(ns+ne)/2;
    update(s,e,k,node*2,ns,mid,c),update(s,e,k,node*2+1,mid+1,ne,c);
    (c?pl:mi)[node]=(c?pl:mi)[node*2]+(c?pl:mi)[node*2+1];//(8)
}

ll query(int s,int e,int node,int ns,int ne,int c)
{
    propagate(node,ns,ne,c);
    if(e<ns||ne<s)return 0;//(9)
    if(s<=ns&&ne<=e)return (c?pl:mi)[node];//(10)
    int mid=(ns+ne)/2;
    return query(s,e,node*2,ns,mid,c)+query(s,e,node*2+1,mid+1,ne,c);//(11)
}

int main(){
    int q;scanf("%d",&q);
    vector<vector<ll>> queries;
    vector<pll> p;
    for(int i=0;i<q;i++){
        ll c;scanf("%lld",&c);
        if(c==1){
            ll a,b;scanf("%lld%lld",&a,&b);
            queries.push_back({c,a,b});
            if(a<0)a*=-1ll,b*=-1ll;
            if(a)p.push_back({-b,a});
        }
        else{
            ll a;scanf("%lld",&a);
            queries.push_back({c,1ll,-a});
            p.push_back({a,1ll});
        }
    }
    sort(p.begin(),p.end(),[](pll a,pll b){
        __int128 aa=a.first,bb=a.second,cc=b.first,dd=b.second;
        __int128 x=aa*dd,y=bb*cc;
        return x<y;
    });
    //for(auto [x,y]:p)printf("%lld %lld\n",x,y);

    bool END=0;
    ll rev=0;
    for(auto qu:queries){
        ll c=qu[0],a=qu[1],b=qu[2];
        if(c==1){
            if(a==0&&b==0)END=1;
            else if(a==0&&b<0) rev++;
            else if(a!=0) {
                pll x={-b,a};
                if(a<0)x.first*=-1ll,x.second*=-1ll;
                ll l=lower_bound(p.begin(),p.end(),x,[](pll a,pll b){
                    __int128 aa=a.first,bb=a.second,cc=b.first,dd=b.second;
                    __int128 x=aa*dd,y=bb*cc;
                    return x<y;
                })-p.begin(),
                r=upper_bound(p.begin(),p.end(),x,[](pll a,pll b){
                    __int128 aa=a.first,bb=a.second,cc=b.first,dd=b.second;
                    __int128 x=aa*dd,y=bb*cc;
                    return x<y;
                })-p.begin()-1;
                //printf("!<%lld %lld %lld %lld>\n",x.first,x.second,l,r);
                update(l,l,1ll,1,0,sz-1,a>0);
            }
        }
        else{
            pll x={-b,a};
            ll l=lower_bound(p.begin(),p.end(),x,[](pll a,pll b){
                __int128 aa=a.first,bb=a.second,cc=b.first,dd=b.second;
                __int128 x=aa*dd,y=bb*cc;
                return x<y;
            })-p.begin(),
                    r=upper_bound(p.begin(),p.end(),x,[](pll a,pll b){
                __int128 aa=a.first,bb=a.second,cc=b.first,dd=b.second;
                __int128 x=aa*dd,y=bb*cc;
                return x<y;
            })-p.begin()-1;
            //printf("<%lld %lld %lld %lld>\n",x.first,x.second,l,r);
            if(END||query(l,r,1,0,sz-1,0)||query(l,r,1,0,sz-1,1))
                printf("0\n");
            else {
                ll k=query(l,q,1,0,sz-1,1)+query(0,r,1,0,sz-1,0)+rev;
                printf(k&1ll?"-\n":"+\n");
            }
        }
    }
    return 0;
}