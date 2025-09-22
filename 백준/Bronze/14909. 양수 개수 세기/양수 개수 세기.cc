#include<bits/stdc++.h>
using namespace std;
int main() {
    int x,y=0;
    while(scanf("%d",&x)!=EOF){
        y+=x>0;
    }
    printf("%d",y);
}