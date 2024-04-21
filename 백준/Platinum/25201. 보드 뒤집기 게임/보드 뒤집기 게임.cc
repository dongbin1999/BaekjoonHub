#include <bits/stdc++.h>
using namespace std;

int a[2][100001];

int main() {
    int n,m,x,y;scanf("%d %d",&n,&m);
    n+=m;
    while(n--){
        scanf("%d %d",&x,&y);
        a[0][x]^=1,a[1][y]^=1;
    }
    for(int i=1;i<=100000;i++)
        if(a[0][i]|a[1][i])return !printf("NO\n");
    printf("YES\n");
    return 0;
}
