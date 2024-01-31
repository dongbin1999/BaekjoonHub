#include <bits/stdc++.h>
using namespace std;

int u[360];
int find(int x){
    if(u[x]<0)return x;
    return u[x]=find(u[x]);
}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    u[a]+=u[b],u[b]=a;
    return true;
}

int main() {
    int n;scanf("%d",&n);
    vector<int> v(360);
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        v[x]++;
    }
    int ans=0;
    for(int d=1;d<360;d++){
        memset(u,-1,sizeof(u));
        for(int i=0;i<360;i++)if(v[i]&&v[(i+d)%360])merge(i,(i+d)%360);
        int tmp=0;
        for(int i=0;i<360;i++)if(find(i)==i&&v[i])tmp+=-u[i]/2*2;
        ans=max(ans,tmp);
    }
    printf("%d",ans);
}