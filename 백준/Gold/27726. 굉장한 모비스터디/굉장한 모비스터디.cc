#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<int> u[3];
int find(int a,int c){
    if(u[c][a]<0)return a;
    return u[c][a]=find(u[c][a],c);
}
bool merge(int a,int b,int c){
    a=find(a,c),b=find(b,c);
    if(a==b)return false;
    u[c][a]+=u[c][b],u[c][b]=a;
    return true;
}
int main(){
    int n,a[3];scanf("%d%d%d%d",&n,&a[0],&a[1],&a[2]);
    for(int i=0;i<3;i++)u[i].assign(n+1,-1);
    vector<pii> v;
    for(int i=0;i<3;i++)
        while(a[i]--){
            int x,y;scanf("%d%d",&x,&y);
            merge(x,y,i);
            v.push_back({x,y});
        }
    map<tuple<int,int,int>,vector<int>> ma;
    for(int i=1;i<=n;i++)
        ma[{find(i,0),find(i,1),find(i,2)}].push_back(i);
    vector<vector<int>> ans;
    for(auto [key,v]:ma)if(v.size()>1)ans.push_back(v);
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(auto i:ans){
        for(auto j:i)printf("%d ",j);
        printf("\n");
    }
    return 0;
}