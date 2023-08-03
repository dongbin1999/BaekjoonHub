#include<bits/stdc++.h>
using namespace std;
int a[1002][1002],sum[1002][1002];
int answer(int n,int m){
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
        if(a[i][j]>0)ans++;
    }
    return ans;
}

void add(int i1,int j1,int i2,int j2,int k){
    a[i1][j1]+=k,a[i2+1][j1]-=k,a[i1][j2+1]-=k,a[i2+1][j2+1]+=k;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n=board.size(),m=board[0].size();
    for(int r=0;r<n;r++)for(int c=0;c<m;c++)
        add(r+1,c+1,r+1,c+1,board[r][c]);
    for(auto i:skill){
        int type=i[0],r1=i[1]+1,c1=i[2]+1,r2=i[3]+1,c2=i[4]+1,degree=i[5];
        if(type==1)degree*=-1;
        add(r1,c1,r2,c2,degree);
    }
    return answer(n,m);
}