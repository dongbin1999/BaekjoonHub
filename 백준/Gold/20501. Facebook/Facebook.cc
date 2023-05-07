#include <bits/stdc++.h>
using namespace std;
char s[2001];
int main(){
    int n;scanf("%d",&n);
    vector<bitset<2000>> v(n+1);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        for(int j=0;j<n;j++)v[i].set(j,s[j]=='1');
    }
    int q;scanf("%d",&q);
    while(q--){
        int x,y;scanf("%d%d",&x,&y);
        printf("%d\n",(v[x]&v[y]).count());
    }
}