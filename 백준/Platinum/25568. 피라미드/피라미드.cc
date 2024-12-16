#include<bits/stdc++.h>
using namespace std;

int a[1001][1001],b[1001][1001],c[1001][1001];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)scanf("%d",&a[i][j]);
    int x=a[1][1],y=x;
    for(int i=1;i<=n;i++){
        int xx=x,yy=y;
        for(int j=1;j<=i;j++){
            b[i][j]=xx,c[i][j]=yy;
            xx=(xx+1)%3,yy=(yy+2)%3;
        }
        x=(x+1)%3,y=(y+2)%3;
    }
    int bcnt=0,ccnt=0;
    for(int i=1;i<=n;i++){
        vector<int> A(3),B(3),C(3);
        int ab[3][3]={0},ac[3][3]={0};
        for(int j=1;j<=i;j++){
            A[a[i][j]]++,B[b[i][j]]++,C[c[i][j]]++;
            ab[a[i][j]][b[i][j]]++,ac[a[i][j]][c[i][j]]++;
        }
        if(A!=B)bcnt=1e9;if(A!=C)ccnt=1e9;
        for(int j=0;j<3;j++){
            int X=j,Y=(j+1)%3;
            int p=min(ab[X][Y],ab[Y][X]);
            ab[X][Y]-=p,ab[Y][X]-=p,bcnt+=p;
            p=min(ac[X][Y],ac[Y][X]);
            ac[X][Y]-=p,ac[Y][X]-=p,ccnt+=p;
        }
        bcnt+=2*max(ab[0][1],ab[1][0]);
        ccnt+=2*max(ac[0][1],ac[1][0]);
    }
    int ans=min(bcnt,ccnt);
    printf("%d",ans>1e8?-1:ans);
}