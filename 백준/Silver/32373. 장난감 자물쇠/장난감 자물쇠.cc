#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        if(x%k!=i%k)return !printf("No");
    }
    printf("Yes");
}