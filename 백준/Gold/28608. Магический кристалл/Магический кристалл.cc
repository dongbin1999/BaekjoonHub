#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    if(n<4)return !printf("-1 -1");
    vector<int> v={2,(n+1)/2};
    int x=n,sum=accumulate(v.begin(),v.end(),0);
    while(sum<x)v.push_back(1),sum++;
    printf("%d %d\n",v.size(),n%2+1);
    for(auto i:v)printf("%d ",i);
    printf("\n%d",n);
    if(n%2)printf(" 1");
}