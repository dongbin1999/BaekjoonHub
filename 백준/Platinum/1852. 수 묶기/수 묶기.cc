#include <bits/stdc++.h>
using namespace std;
#define d(a,b) abs(a-b)
#define l(a,b) a=min(a,b)
#define u(a,b) a=max(a,b)
int a[8][100002],mx[8][100002],mn[8][100002];

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d%d",&a[1][i],&a[2][i],&a[4][i]);
    memset(mn,0x7f,sizeof(mn));mn[0][0]=0;
    for(int i=0;i<n;i++){
        u(mx[3][i],mx[0][i]+d(a[1][i],a[2][i]));
        u(mx[6][i],mx[0][i]+d(a[2][i],a[4][i]));
        u(mx[0][i+1],mx[1][i]+d(a[2][i],a[4][i]));
        u(mx[0][i+1],mx[4][i]+d(a[1][i],a[2][i]));
        u(mx[1][i+1],mx[6][i]+d(a[1][i],a[1][i+1]));
        u(mx[4][i+1],mx[3][i]+d(a[4][i],a[4][i+1]));
        u(mx[3][i+1],mx[4][i]+d(a[1][i],a[1][i+1])+d(a[2][i],a[2][i+1]));
        u(mx[6][i+1],mx[1][i]+d(a[2][i],a[2][i+1])+d(a[4][i],a[4][i+1]));
        u(mx[0][i+2],mx[0][i]+d(a[1][i],a[1][i+1])+d(a[2][i],a[2][i+1])+d(a[4][i],a[4][i+1]));

        l(mn[3][i],mn[0][i]+d(a[1][i],a[2][i]));
        l(mn[6][i],mn[0][i]+d(a[2][i],a[4][i]));
        l(mn[0][i+1],mn[1][i]+d(a[2][i],a[4][i]));
        l(mn[0][i+1],mn[4][i]+d(a[1][i],a[2][i]));
        l(mn[1][i+1],mn[6][i]+d(a[1][i],a[1][i+1]));
        l(mn[4][i+1],mn[3][i]+d(a[4][i],a[4][i+1]));
        l(mn[3][i+1],mn[4][i]+d(a[1][i],a[1][i+1])+d(a[2][i],a[2][i+1]));
        l(mn[6][i+1],mn[1][i]+d(a[2][i],a[2][i+1])+d(a[4][i],a[4][i+1]));
        l(mn[0][i+2],mn[0][i]+d(a[1][i],a[1][i+1])+d(a[2][i],a[2][i+1])+d(a[4][i],a[4][i+1]));
    }
    printf("%d\n%d",mx[0][n],mn[0][n]);
    return 0;
}