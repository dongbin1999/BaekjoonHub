#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<ll> tree[200001];
vector<pll> ans;

ll go(ll node){
    ll sum=0;
    vector<ll> v;
    for(auto nx:tree[node])
        v.push_back(go(nx)),sum+=v.back();
    ll cnt=sum*2+1;
    for(auto i:v)cnt+=i*(sum-i);
    ans.push_back({node,cnt});
    return sum+1;
}

int main(){
    int n,root;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int pa;scanf("%d",&pa);
        tree[pa].push_back(i);
        if(!pa)root=i;
    }
    go(root);
    sort(ans.begin(),ans.end());
    ll odd=0,even=0,b=0;
    for(auto [num,cnt]:ans){
        odd+=num*(cnt/2),even+=num*(cnt/2);
        if(cnt%2)(b%2?even:odd)+=num;
        b+=cnt;
    }
    printf("%lld %lld",even,odd);
}