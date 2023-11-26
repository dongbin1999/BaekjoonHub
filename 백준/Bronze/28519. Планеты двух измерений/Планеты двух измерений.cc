#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    printf("%d",min(n,m)*2+min(1,abs(n-m)));
    return 0;
}
