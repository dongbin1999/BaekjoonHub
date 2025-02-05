//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int cnt[60000],answer[60000],nx[60000];
int a[60000],idx[60000];
pii v[60000];

void solve(){
    int n;cin>>n;
    memset(cnt,0,sizeof(int)*(n+1));
    memset(nx,-1,sizeof(int)*(n+1));
    int root=sqrt(n);
    for(int i=1;i<=n;i++)cin>>a[i];

    int q;cin>>q;
    for(int i=0;i<q;i++)cin>>v[i].first>>v[i].second,idx[i]=i;

    sort(idx,idx+q,[&](int a,int b){
        const auto& [al,ar]=v[a];
        const auto& [bl,br]=v[b];
        int A=al/root,B=bl/root;
        return A==B?ar<br:A<B;
    });

    int l=v[idx[0]].first,r=v[idx[0]].second,ans=0;
    for(int i=2;i<=n;i++)
        if((ll)n>=(ll)a[i]*(ll)a[i])
            nx[a[i]]=a[i]*a[i];

    for(int i=l;i<=r;i++)
        for(int x=a[i];x>=2&&x<=n&&++cnt[x]%x==0;x=x*x)ans++;

    for(int i=0;i<q;i++){
        auto [L,R]=v[idx[i]];
        while(L<l)for(int x=a[--l];x>=2&&x<=n&&++cnt[x]%x==0;x=x*x)ans++;
        while(R>r)for(int x=a[++r];x>=2&&x<=n&&++cnt[x]%x==0;x=x*x)ans++;
        while(L>l)for(int x=a[l++];x>=2&&x<=n&&cnt[x]--%x==0;x=x*x)ans--;
        while(R<r)for(int x=a[r--];x>=2&&x<=n&&cnt[x]--%x==0;x=x*x)ans--;
        answer[idx[i]]=ans;
    }
    for(int i=0;i<q;i++)cout<<answer[i]<<'\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    setbuf(stdout, NULL);
    int tc;cin>>tc;
    for(int i=1;i<=tc;i++){
        cout<<"Case #"<<i<<"\n";
        solve();
    }
    return 0;
}