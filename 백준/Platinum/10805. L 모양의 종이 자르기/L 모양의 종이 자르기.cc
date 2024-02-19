#include <bits/stdc++.h>
using namespace std;

int rect[51][51];
int dp[51][51][51][51];

int r(int h,int w){
    if(h>w)swap(h,w);
    if(rect[h][w]!=-1)return rect[h][w];
    if(h==w)return rect[h][w]=1;
    int ret=1e9;
    for(int i=1;i<h;i++)ret=min(ret,r(i,w)+r(h-i,w));
    for(int i=1;i<w;i++)ret=min(ret,r(h,w-i)+r(h,i));
    return rect[h][w]=ret;
}

int go(int h1,int w1,int h2,int w2){
    if(dp[h1][w1][h2][w2]!=-1)return dp[h1][w1][h2][w2];
    int ret=1e9;
    //위에서부터 i지점 수평으로 자르기
    for(int i=1;i<h2;i++)ret=min(ret,go(h1-i,w1,h2-i,w2)+r(i,w1-w2));
    //아래서부터 i지점 수평으로 자르기
    for(int i=1;i<h1-h2;i++)ret=min(ret,go(h1-i,w1,h2,w2)+r(i,w1));
    //오른쪽서부터 i지점 수직으로 자르기
    for(int i=1;i<w2;i++)ret=min(ret,go(h1,w1-i,h2,w2-i)+r(h1-h2,i));
    //왼쪽서부터 i지점 수직으로 자르기
    for(int i=1;i<w1-w2;i++)ret=min(ret,go(h1,w1-i,h2,w2)+r(h1,i));
    ret=min(ret,r(h2,w1-w2)+r(h1-h2,w1));
    ret=min(ret,r(h1,w1-w2)+r(h1-h2,w2));
    return dp[h1][w1][h2][w2]=ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    memset(rect,-1,sizeof(rect));
    int h1,w1,h2,w2;scanf("%d%d%d%d",&h1,&w1,&h2,&w2);
    printf("%d",go(h1,w1,h2,w2));
    return 0;
}