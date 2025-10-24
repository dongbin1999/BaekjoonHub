#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int x;scanf("%d",&x);
        printf(x%25>=17?"OFF":"ON");
        printf("LINE\n");
    }
}