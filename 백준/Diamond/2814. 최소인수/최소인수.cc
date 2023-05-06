#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,p;scanf("%d%d",&n,&p);
    if(p<=50){
        vector<bool> np(p,0);
        vector<int> prime;
        for(int i=2;i<p;i++)
            if(!np[i]){
                prime.push_back(i);
                for(int j=i*i;j<p;j+=i)
                    np[j]=1;
            }
        int l=1,r=1e9/p+1,mid,ans=r;
        while(l<=r){
            mid=(l+r)/2;
            int ok=mid;
            for(int i=1;i<1<<prime.size();i++){
                int cnt=mid;
                for(int j=0;j<prime.size();j++)
                    if(i&(1<<j))cnt/=prime[j];
                __builtin_popcount(i)&1?ok-=cnt:ok+=cnt;
            }
            if(ok>=n)ans=min(ans,mid),r=mid-1;
            else l=mid+1;
        }
        printf("%d",ans*p>1e9?0:ans*p);
    }
    else{
        vector<bool> v(1e9/p+1,0);
        for(int i=2;i<=min(p-1,(int)1e9/p);i++)
            if(!v[i])
                for(int j=i;j<=(int)1e9/p;j+=i)
                    v[j]=1;
        int ok=0;
        for(int i=1;i<v.size();i++)
            if(!v[i]){
                ok++;
                if(ok==n){
                    printf("%d",i*p);
                    return 0;
                }
            }
        printf("0");
    }
    return 0;
}