#include <bits/stdc++.h>
using namespace std;

bool prime(int n){
    if(n<=1)return 0;
    for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
    return 1;
}

int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<int> v;
    while(k>2)n-=2,v.push_back(2),k--;
    if(n%2&&!v.empty())v.back()++,n--;
    if(k==1&&!prime(n))return !printf("-1");
    else if(k==1)return !printf("%d",n);
    if(n<4)return !printf("-1");
    if(prime(n-2)){
        for(auto i:v)printf("%d ",i);
        printf("2 %d",n-2);
        return 0;
    }
    if(n%2)return !printf("-1");
    int x=3;
    while(1){
        if(prime(x)&&prime(n-x)){
            for(auto i:v)printf("%d ",i);
            printf("%d %d",x,n-x);
            return 0;
        }
        x+=2;
    }
}