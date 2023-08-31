#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tup;
typedef pair<int,int> pii;

int u[100001],tree[100001];
pii atk[100001];
vector<tup> v={{0,-2e9,-2e9}};

int find(int x){
    if(u[x]<0)return x;
    else return u[x]=find(u[x]);
}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    if(get<0>(v[a])>get<0>(v[b]))swap(a,b);
    u[a]+=u[b],u[b]=a;
    return true;
}

int main(){
    memset(u,-1,sizeof(u));
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int h,l,r;scanf("%d%d%d",&h,&l,&r);
        v.push_back({h,l,-r});//r은 큰게 우선임.
    }
    sort(v.begin(),v.end());//높이우선정렬
    vector<tup> vv={{-2e9,-2e9,0}};
    for(int i=1;i<=n;i++){
        auto [h,l,r]=v[i]; r=-r;
        vv.push_back({l,-r,i});//lr우선정렬
        int block=upper_bound(v.begin(),v.end(),tup{h-1,l,-r})-v.begin()-1;
        tree[i]=block;
    }

    int q;scanf("%d",&q);
    vector<pii> m;
    for(int i=1;i<=q;i++){
        int x,p;scanf("%d%d",&x,&p);
        atk[i].second=p;
        m.push_back({x,i});
    }
    sort(m.begin(),m.end());
    sort(vv.begin(),vv.end());

    //어느 블럭에 폭격이 떨어지는 지 구하기.
    int idx=0;
    stack<tup> s;
    for(auto [x,i]:m){
        while(idx<=n){
            auto [l,r,block]=vv[idx]; r=-r;
            if(l<=x) s.push(vv[idx]),idx++;
            else break;
        }
        while(!s.empty()){
            auto [l,r,block]=s.top(); r=-r;
            if(x<=r)break;
            else s.pop();
        }
        if(s.empty())atk[i].first=-1;
        else atk[i].first=get<2>(s.top());
    }
    for(int i=1;i<=q;i++){
        auto [block,p]=atk[i];
        block=find(block);
        int ans=0;
        while(block&&p--){
            ans++;
            merge(block,tree[block]);
            block=find(block);
        }
        printf("%d ",ans);
    }
    return 0;
}