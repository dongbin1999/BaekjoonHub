#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;scanf("%d",&n);
    int a[4]={0};
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        a[i%4]+=x;
    }
    printf("YES\n");
    if(n<=4){
        printf("0");n--;
        for(int i=0;i<n;i++)printf("%d",n);
        printf("\n");
        return;
    }
    pair<int,int> p={INT_MAX,-1};
    for(int i=0;i<4;i++)p=min(p,{a[i],i});
    if(p.second){
        printf("0");
        for(int i=0;i<p.second-1;i++)printf("%d",p.second-1);
        n-=p.second;
    }
    while(n>=4)printf("0333"),n-=4;
    if(n)printf("0"),n--;
    for(int i=0;i<n;i++)printf("%d",n);
    printf("\n");
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
}