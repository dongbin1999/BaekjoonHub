#include<bits/stdc++.h>
using namespace std;
int mx[102][102][2],mn[102][102][2];

int solution(vector<string> arr)
{
    int n=arr.size()/2+1;
    memset(mx,-0x3f,sizeof(mx)),memset(mn,0x3f,sizeof(mn));
    vector<int> v={stoi(arr[0])};
    for(int i=2;i<arr.size();i+=2)
        v.push_back(arr[i-1]=="+"?stoi(arr[i]):-stoi(arr[i]));
    for(int i=0;i<n;i++)mn[i][i][v[i]>0]=mx[i][i][v[i]>0]=v[i];
    for(int len=2;len<=n;len++)
        for(int l=0,r=l+len-1;r<n;l++,r++)
            for(int m=l;m<r;m++){
                int rop=v[m+1]>0,lop=v[l]>0;
                mx[l][r][rop]=max(mx[l][r][rop],mx[l][m][lop]+mx[m+1][r][rop]);
                mx[l][r][lop]=max(mx[l][r][lop],mx[l][m][lop]+(v[l]<0?-mn[m+1][r][rop]:mx[m+1][r][rop]));
                mn[l][r][rop]=min(mn[l][r][rop],mn[l][m][lop]+mn[m+1][r][rop]);
                mn[l][r][lop]=min(mn[l][r][lop],mn[l][m][lop]+(v[l]<0?-mx[m+1][r][rop]:mn[m+1][r][rop]));
            }

    return mx[0][n-1][1];
}