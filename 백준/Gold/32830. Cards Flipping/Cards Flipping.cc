#include <bits/stdc++.h>
using namespace std;
int u[1000001],a[200001],b[200001],o[1000001];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return 0;
    if(-u[x]<-u[y])swap(x,y);
    u[x]+=u[y],o[x]|=o[y],u[y]=x;
    return 1;
}

int main(){
    memset(u,-1,sizeof(u));
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        if(!merge(a[i],b[i]))o[find(a[i])]=o[find(b[i])]=1;
    }
    int ans=0;
    for(int i=0;i<=1000000;i++)if(find(i)==i){
        ans+=-u[i]-1;
        if(o[i])ans++;
    }
    printf("%d",ans);
}