#include<bits/stdc++.h>
using namespace std;
int np[1000001],sum[1000001];
int main(){
    int n;scanf("%d",&n);
    for(int i=2;i<=1000;i++){
        if(np[i])continue;
        for(int j=i*i;j<=1000000;j+=i)
            np[j]=1;
    }
    for(int i=1;i<=1000000;i++)sum[i]=sum[i-1]+!np[i];
    while(n--){
        int a,b;scanf("%d%d",&a,&b);
        int cnt=sum[b]-sum[a-1];
        if(cnt%2==0){printf("-1\n");continue;}
        cnt=cnt/2+1;
        int l=a,r=b,mid,ans=r;
        while(l<=r){
            mid=(l+r)/2;
            if(sum[mid]-sum[a-1]>=cnt)ans=min(ans,mid),r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",ans);
    }
}
