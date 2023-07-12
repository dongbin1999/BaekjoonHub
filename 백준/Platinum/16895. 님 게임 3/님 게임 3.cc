#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int x=0,ans=0;
    vector<int> p(n);
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]),x^=p[i];
    for(int i=0;i<n;i++)ans+=(x^p[i])<=p[i];
    printf("%d",x?ans:0);
    return 0;
}