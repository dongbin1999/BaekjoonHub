#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;scanf("%d",&n);
    n=(n+1)/2;
    printf("%d\n",n*n);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}