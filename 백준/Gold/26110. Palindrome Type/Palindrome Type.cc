#include <bits/stdc++.h>
using namespace std;

char s[100003];
bool b[5][5][100001];

int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    b[0][0][0]=1;
    for(int l=0;l<=3;l++)for(int r=0;r+l<=3;r++)
        for(int i=0;i+i+l+r<=n;i++){
            b[l+1][r][i]|=b[l][r][i];
            b[l][r+1][i]|=b[l][r][i];
            char L=s[i+l+1],R=s[n-i-r];
            if(L==R)b[l][r][i+1]|=b[l][r][i];
        }
    for(int i=0;i<=3;i++)
        for(int l=0,r=i-l;l<=i;l++,r--)
            if(b[l][r][(n-l-r)/2])return !printf("%d",i);
    printf("-1");
}