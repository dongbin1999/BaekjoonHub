#include <bits/stdc++.h>
using namespace std;
vector<int> tree[500001];
int main(){
    int n,w;scanf("%d%d",&n,&w);
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].push_back(y),tree[y].push_back(x);
    }
    int leaf=0;
    for(int i=2;i<=n;i++)leaf+=tree[i].size()==1;
    printf("%lf",(double)w/leaf);
}