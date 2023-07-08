#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    if(n<=2)return !printf("0");
    vector<int> b(n);
    int ans=1e9;
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    for(int i=-1;i<=1;i++)for(int j=-1;j<=1;j++){
        int s=b[0]+i,e=b[n-1]+j,d=(e-s)/(n-1);
        if(d*(n-1)+s!=e)continue;
        int cnt=0,ok=1;
        for(int k=0;k<n;k++,s+=d){
            int diff=abs(b[k]-s);
            ok&=diff<=1;
            cnt+=diff;
        }
        if(ok)ans=min(ans,cnt);
    }
    printf("%d",ans==1e9?-1:ans);
}