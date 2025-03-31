#include<bits/stdc++.h>
using namespace std;
int p[5001][5001],a[5002],b[5001];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int il=1,ir=2;ir<=n;il++,ir++){
        int l=il,r=ir;
        while(l>=1&&r<=n&&a[l]==a[r])p[l][r]=1,l--,r++;
    }
    memset(b,-0x3f,sizeof(b));
    b[0]=0;
    for(int i=0;i<=n;i++){
        int l=i+1;
        for(int r=l+1;r<=n;r+=2)
            if(p[l][r])b[r]=max(b[r],b[i]+1);
    }
    printf("%d",max(b[n],-1));
}