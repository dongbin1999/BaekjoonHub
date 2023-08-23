#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int n;scanf("%d",&n);
        if(!n)break;
        map<int,int> ma;
        int ans=min(n-1,1);
        for(int i=2,nn=n;i*i<=nn;i++){
            if(n%i)continue;
            while(n%i==0)ma[i]++,n/=i,ans*=i;
            ans=ans/i*(i-1);
        }
        if(n>1)ans*=n-1;
        printf("%d\n",ans);
    }
    return 0;
}