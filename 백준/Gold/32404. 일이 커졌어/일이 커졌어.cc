#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    int r=n;
    vector<int> ans(n+1);
    int i=n;if(i%2==0)i--;
    while(i>=1)ans[i]=r--,i-=2;
    i=2;
    while(i<=n)ans[i]=r--,i+=2;
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}