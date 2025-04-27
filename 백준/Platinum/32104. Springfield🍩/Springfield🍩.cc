#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int u[200001],sum[200001];
set<pii> se[200001];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return 0;
    if(se[a].size()<se[b].size())swap(a,b);
    for(auto [l,r]:se[b]){
        int add=r-l+1;
        auto it=se[a].lower_bound({l,-1});

        if(it!=se[a].begin()){
            it--;
            if(it->second<l)it++;
        }
        //if(it!=se[a].end())printf("!{%d %d}\n",it->first,it->second);
        bool pass=0;
        vector<pii> del;
        //[l,r]과 겹치는 구간 찾기
        while(it!=se[a].end()){
            auto [L,R]=*it;
            if(r<L)break;
            if(L<=l&&l<=R){
                if(r<=R){pass=1;break;}
                del.push_back({L,R});
                add-=min(r,R)-l+1;
                l=min(L,l),r=max(R,r);
            }
            else if(L<=r&&r<=R){
                if(L<=l){pass=1;break;}
                del.push_back({L,R});
                add-=r-max(l,L)+1;
                l=min(L,l),r=max(R,r);
            }
            else if(l<=L&&R<=r){
                del.push_back({L,R});
                add-=R-L+1;
            }
            else assert(0);
            it++;
        }
        if(pass)continue;
        se[a].insert({l,r}),sum[a]+=add;
        for(auto [L,R]:del)se[a].erase({L,R});
    }
//    int cmp=0;
//    for(auto [l,r]:se[a])cmp+=r-l+1;
//    assert(cmp==sum[a]);
//    printf("%d: ",a);
//    for(auto [l,r]:se[a])printf("[%d %d] ",l,r);
//    printf("\n");
    se[b].clear(),u[a]+=u[b],u[b]=a;
    return 1;
}

int main(){
    int n,q;scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        int l,r;scanf("%d%d",&l,&r);
        u[i]=-1,sum[i]=r-l+1,se[i].insert({l,r});
    }
    while(q--){
        int a,b,c;scanf("%d",&c);
        if(c==1){
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        else{
            scanf("%d",&a);
            printf("%d\n",sum[find(a)]);
        }
    }
    return 0;
}