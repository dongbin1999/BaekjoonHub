#include <bits/stdc++.h>
using namespace std;

int a[10001];
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;scanf("%d.%d",&x,&y);
        a[x*1000+y]++;
    }

    for(int i=1;i<=1000;i++){
        int c=0;
        for(int j=0;j<=10000;j++)if(j*1000/i<=10000)c+=a[j*1000/i];
        if(c==n)return !printf("%d",i);
    }
}