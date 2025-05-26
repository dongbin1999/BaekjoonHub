#include<bits/stdc++.h>
using namespace std;
int a[500001],f[500001];
int main(){
    int n,c,b;scanf("%d%d%d",&n,&c,&b);
    vector<int> v(b);
    for(int i=0;i<b;i++)scanf("%d",&v[i]),f[v[i]]=1;
    int p=0;
    for(int i=n;i>=1;i--){
        p^=1;
        if(f[i])p=0;
        a[i]=p;
    }
    int x=0;
    for(int i=2;i<=n;i++)x+=a[i]!=a[i-1];
    for(int i=n;i>=1;i--){
        if(x<=c)break;
        if(x-1==c&&a[1]!=a[2]){a[1]=a[2];break;}
        if(a[i]){
            a[i]=0;
            if(!a[i+1])x--;
            if(i-1>=1&&!a[i-1])x--;
        }
    }
    if(x<c&&a[1]==a[2])a[1]=!a[2];
    for(int i=1;i<=n;i++)printf("%d",a[i]);
}