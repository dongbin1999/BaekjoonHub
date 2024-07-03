#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> arr;
typedef pair<int,int> pii;

arr a[200001];
char ab,type[10];
vector<int> need[200001];
set<int> se;

void print(vector<arr> &ans){
    printf("YES\n");
    for(auto [c,t,x]:ans){
        printf(c?"B ":"A ");
        printf(t?"CHAIN ":"BLOCK ");
        printf("%d\n",x);
    }
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<pii> v;
    for(int i=1;i<=2*n;i++)se.insert(i);
    for(int i=1;i<=m;i++){
        int x;scanf(" %c %s %d",&ab,type,&x);
        se.erase(se.find(x));
        a[i]={ab=='B',0,x};
        if(x==1)v.push_back({1,i});
    }
    if(v.empty())return !printf("NO");

    vector<arr> ans;
    for(int i=1;i<=m;i++)ans.push_back(a[i]);

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=0;i+1<ans.size();i++)
        if(ans[i][0]==ans[i+1][0])pq.push({ans[i][2],i});
    if(!ans.back()[0])pq.push({ans.back()[2],ans.size()-1});

    while(!pq.empty()){
        auto [x,i]=pq.top();pq.pop();
        auto it=se.upper_bound(ans[i][2]);
        if(it==se.end())return !printf("NO");
        need[i].push_back(*it),se.erase(it);
    }

    vector<arr> tmp;
    for(int i=0;i<ans.size();i++){
        tmp.push_back(ans[i]);
        for(auto j:need[i]){
            auto [pab,ptype,px]=tmp.back();
            tmp.push_back({!pab,1,j});
        }
        if(ans[i][2]==1)
            for(auto j:se){
                auto [pab,ptype,px]=tmp.back();
                tmp.push_back({!pab,1,j});
            }
    }
    ans=tmp;
    print(ans);
}