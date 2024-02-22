#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define upd(x,y)x=min(x,y)
//아빠i번째, 엄마j번째, 현이k번째 음식까지 먹었고, 지금 테이블이 (아빠/엄마/현이)음식 위치에 있을때,
//테이블 회전수의 최솟값
ll dp[102][102][102][3];
vector<int> v[3];

int main(){
    memset(dp,0x3f,sizeof(dp));
    int n,p[3];
    scanf("%d",&n);
    for(int i=0;i<3;i++){
        scanf("%d",&p[i]);
        v[i].resize(p[i]+1);
        for(int j=1;j<=p[i];j++){
            int x;scanf("%d",&x);
            v[i][j]=x-1;
        }
    }
    int d=v[0][1];
    dp[1][0][0][0]=min(d,n-d);
    d=abs(v[1][1]-n/3);
    dp[0][1][0][1]=min(d,n-d);
    d=abs(v[2][1]-n/3*2);
    dp[0][0][1][2]=min(d,n-d);

    for(int f=0;f<=p[0];f++)for(int m=0;m<=p[1];m++)for(int h=0;h<=p[2];h++){
        if(f<p[0]){
            d=abs(v[0][f+1]-v[0][f]);
            upd(dp[f+1][m][h][0],dp[f][m][h][0]+min(d,n-d));
            d=abs(v[0][f+1]-(v[1][m]+n/3*2)%n);
            upd(dp[f+1][m][h][0],dp[f][m][h][1]+min(d,n-d));
            d=abs(v[0][f+1]-(v[2][h]+n/3)%n);
            upd(dp[f+1][m][h][0],dp[f][m][h][2]+min(d,n-d));
        }
        if(m<p[1]){
            d=abs(v[1][m+1]-(v[0][f]+n/3)%n);
            upd(dp[f][m+1][h][1],dp[f][m][h][0]+min(d,n-d));
            d=abs(v[1][m+1]-v[1][m]);
            upd(dp[f][m+1][h][1],dp[f][m][h][1]+min(d,n-d));
            d=abs(v[1][m+1]-(v[2][h]+n/3*2)%n);
            upd(dp[f][m+1][h][1],dp[f][m][h][2]+min(d,n-d));
        }
        if(h<p[2]){
            d=abs(v[2][h+1]-(v[0][f]+n/3*2)%n);
            upd(dp[f][m][h+1][2],dp[f][m][h][0]+min(d,n-d));
            d=abs(v[2][h+1]-(v[1][m]+n/3)%n);
            upd(dp[f][m][h+1][2],dp[f][m][h][1]+min(d,n-d));
            d=abs(v[2][h+1]-v[2][h]);
            upd(dp[f][m][h+1][2],dp[f][m][h][2]+min(d,n-d));
        }
    }
    printf("%lld",min({dp[p[0]][p[1]][p[2]][0],dp[p[0]][p[1]][p[2]][1],dp[p[0]][p[1]][p[2]][2]}));
}