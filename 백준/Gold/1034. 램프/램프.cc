#include <bits/stdc++.h>
using namespace std;

int a[51][51];
void turn(int n,vector<bool> v){
    for(int j=1;j<v.size();j++){
        if(!v[j])continue;
        for(int i=1;i<=n;i++)a[i][j]^=1;
    }
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%1d",&a[i][j]);
    int k,ans=0;scanf("%d",&k);
    //i번째 행을 무조건 켠다.
    for(int i=1;i<=n;i++){
        int on=0;
        vector<bool> s(m+1);
        for(int j=1;j<=m;j++)s[j]=!a[i][j];
        int need=accumulate(s.begin(),s.end(),0);
        if(k<need||(k+need)%2)continue;
        turn(n,s);
        for(int r=1;r<=n;r++)on+=accumulate(a[r]+1,a[r]+1+m,0)==m;
        ans=max(ans,on);
        turn(n,s);
    }
    printf("%d",ans);
    return 0;
}