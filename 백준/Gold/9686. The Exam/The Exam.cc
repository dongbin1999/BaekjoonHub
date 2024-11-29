#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    int a=(n+1)/2,b=n;
    vector<int> ans;
    for(int i=0;i<n/2;i++)ans.push_back(a--),ans.push_back(b--);
    if(n%2)ans.push_back(a);
    if(b-a<k)return !printf("NIE");
    for(auto i:ans)printf("%d ",i);
}