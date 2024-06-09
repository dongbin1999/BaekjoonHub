#include<bits/stdc++.h>
using namespace std;
vector<int> tree[100001];
int ans;
void go(int node=1,int pa=-1){
    int child=0;
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        go(nx,node),child++;
    }
    while(child)child>>=1,ans++;
    ans++;
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].push_back(b),tree[b].push_back(a);
    }
    go();
    printf("%d",ans-1);
}