#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef array<int,3> arr;

int main(){
    int a,b;scanf("%d%d",&a,&b);
    int n;scanf("%d",&n);
    vector<int> x(n+1),y(n+1);
    set<pii> se;
    arr ans={INT_MIN,-1-1};
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
        se.insert({y[i],i});
        if(a-b<0)ans=max(ans,{a-b,-1,-1});
        if(a-b-x[i]<0)ans=max(ans,{a-b-x[i],i,-1});
        if(a-b-y[i]<0)ans=max(ans,{a-b-y[i],-1,i});
    }
    for(int i=1;i<=n;i++){
        int need=a-b-x[i];
        auto it=se.upper_bound({need,1e9});
        if(it==se.end())continue;
        if(it->second==i){
            if(next(it)==se.end())continue;
            ans=max(ans,{need-next(it)->first,i,next(it)->second});
        }
        else ans=max(ans,{need-it->first,i,it->second});
    }
    if(ans[0]==INT_MIN)return !printf("No");
    printf("%d %d",ans[1],ans[2]);
}