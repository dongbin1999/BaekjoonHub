#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        m-=x+1;
    }
    if(m<=0)return !printf("0");
    int ans=0,x=m/(n+1);
    for(int i=0;i<=n;i++){
        int y=i<m%(n+1)?x+1:x;
        ans+=y*(y+1)*(y+y+1)/6;
    }
    printf("%d",ans);
    return 0;
}