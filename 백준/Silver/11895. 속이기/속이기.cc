#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    int x=0,mn=1e9,sum=0;
    for(int i=0;i<n;i++)scanf("%d",&v[i]),x^=v[i],mn=min(mn,v[i]),sum+=v[i];
    if(x)printf("0");
    else printf("%d",sum-mn);
}