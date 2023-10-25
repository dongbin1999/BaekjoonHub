#include <bits/stdc++.h>
using namespace std;
bool f(int n,int m,int k){
    int r=n<m?k-m:k-n+1;
    if(n>=m)n--,m=min(n,m+r);
    else m--,n=min(m,n+r);
    return n==m;
}
int main(){
    int k,c;scanf("%d%d",&k,&c);
    while(c--){
        int n,m;scanf("%d%d",&n,&m);
        printf("%d\n",f(n,m,k));
    }
    return 0;
}