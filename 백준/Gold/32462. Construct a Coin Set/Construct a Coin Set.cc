#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        if(n<6)printf("-1\n");
        else if(n%2==0)printf("3\n1 %d %d\n",n/2,n-2);
        else printf("4\n1 3 %d %d\n",n-3,n-2);
    }
    return 0;
}