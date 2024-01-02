#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c,d,e;scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    if(a||b||c>1||(c==1&&d%2==0))printf("hanbyeol\n");
    else printf(d%2?"geometry\n":"number_theory\n");
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}