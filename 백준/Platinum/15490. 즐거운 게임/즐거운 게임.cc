#include <bits/stdc++.h>
using namespace std;

int a[3001],dp[3001][3001][2][2][2];

//l~r을 고를수 있고, kcm1700홀짝성, ntopia홀짝성, turn이 주어질때, 이 상황에서 턴 잡은 사람이 이길 수 있는가?
bool go(int l,int r,int k=0,int n=0,bool turn=0){
    if(l>r)return turn?n==0:k==0;
    if(dp[l][r][k][n][turn]!=-1)return dp[l][r][k][n][turn];
    bool ret=0;
    if(!turn){
        ret|=!go(l+1,r,k^a[l],n,!turn);
        if(l<r)ret|=!go(l+2,r,k^a[l]^a[l+1],n,!turn);
        ret|=!go(l,r-1,k^a[r],n,!turn);
        if(l<r)ret|=!go(l,r-2,k^a[r]^a[r-1],n,!turn);
    }
    else{
        ret|=!go(l+1,r,k,n^a[l],!turn);
        if(l<r)ret|=!go(l+2,r,k,n^a[l]^a[l+1],!turn);
        ret|=!go(l,r-1,k,n^a[r],!turn);
        if(l<r)ret|=!go(l,r-2,k,n^a[r]^a[r-1],!turn);
    }
    return dp[l][r][k][n][turn]=ret;
}

int main(){
    int n;scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]&=1;
    printf(go(1,n)?"Yes":"No");
    return 0;
}