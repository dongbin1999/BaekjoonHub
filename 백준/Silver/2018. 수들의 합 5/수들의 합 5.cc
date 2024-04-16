#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int ans=0;
    for(int i=1;i*i<=2*n;i++){
        if(i%2){
            if(n%i)continue;
            int mid=n/i,d=i/2;
            if(mid-d>=1)ans++;
        }
        else{
            if(n*2%i)continue;
            int mid=n/i,d=i/2-1;
            if(i/2*(mid+mid+1)!=n)continue;
            if(mid-d>=1)ans++;
        }
    }
    printf("%d",ans);
}