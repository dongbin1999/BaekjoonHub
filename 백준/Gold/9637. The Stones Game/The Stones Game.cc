#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        if(x%y==z%y)printf("YES\n");
        else printf("NO\n");
    }
}