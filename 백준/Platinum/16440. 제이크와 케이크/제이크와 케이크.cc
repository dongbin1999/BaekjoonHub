#include<bits/stdc++.h>
using namespace std;
char a[300000];

int main(){
    int n;scanf("%d %s",&n,a+1);
    int x=0;
    for(int i=1;i<=n/2;i++)if(a[i]=='s')x++;
    if(x==n/4)return !printf("1\n%d",n/2);
    int l=n/2+1,r=n/2,s=0,k=0;
    while(s<n/4&&k<n/4)if(a[--l]=='s')s++;else k++;
    while(s+k<n/2){
        if(a[++r]=='s')s++;else k++;
        while(s>n/4||k>n/4)if(a[l++]=='s')s--;else k--;
    }
    printf("2\n%d %d",l-1,r);
}