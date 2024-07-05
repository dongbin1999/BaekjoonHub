#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

pii nx[100001];

int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    memset(nx,0x3f,sizeof(nx));
    for(int i=1;i<=n;i++){
        int a,b;scanf("%d%d",&a,&b);
        nx[b]=min(nx[b],{i,a});
    }
    int ans=0;
    while(ans<=2e5){
        if(nx[k].second<1e9)ans++,k=nx[k].second;
        else break;
    }
    if(ans<2e5)printf("%d",ans);
    else printf("-1");
}