#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++)printf("%d ",i*m+j+1);
        printf("%d\n",i*m+m);
    }
}