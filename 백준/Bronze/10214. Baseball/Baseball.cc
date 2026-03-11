#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    while(n--){
        int x=0,y=0,z=9;
        while(z--){
            int a,b;cin>>a>>b;
            x+=a,y+=b;
        }
        if(x>y)printf("Yonsei\n");
        else if(x<y)printf("Korea\n");
        else printf("Draw\n");
    }
}