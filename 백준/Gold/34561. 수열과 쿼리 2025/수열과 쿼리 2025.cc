#include<bits/stdc++.h>
using namespace std;
int a[300001],ans[300001],r[300001];
vector<int> v[300001];
void merge(int x,int y){
    int xx=x,yy=y;
    x=r[x],y=r[y];
    if(x==y)return;
    if(v[x].size()>v[y].size()){
        swap(ans[x],ans[y]);
        swap(r[xx],r[yy]);
        swap(x,y);
    }
    while(!v[x].empty()){
        int p=v[x].back();v[x].pop_back();
        a[p]=a[v[y][0]],v[y].push_back(p);
    }
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=300000;i++)ans[i]=i,r[i]=i;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),v[a[i]].push_back(i);
    int m;scanf("%d",&m);
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        if(x==1){
            int z;scanf("%d",&z);
            merge(y,z);
        }
        else printf("%d\n",ans[a[y]]);
    }
}