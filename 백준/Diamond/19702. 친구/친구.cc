#include <bits/stdc++.h>
using namespace std;

int a[101][101];

int main() {
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
    vector<int> v;
    for(int i=0;i<n;i++)v.push_back(i);
    while(1){
        int x=-1;
        for(int i=0;i<n;i++)if(!a[v[i]][v[(i+1)%n]])x=i;
        if(x==-1)break;
        for(int y=0;y<n;y++)if(x!=y&&a[v[x]][v[y]]&&a[v[(x+1)%n]][v[(y+1)%n]]){
            if(x>y)swap(x,y);
            for(int l=x+1,r=y;l<r;l++,r--)swap(v[l],v[r]);
            break;
        }
    }
    for(auto i:v)printf("%d ",i+1);
}