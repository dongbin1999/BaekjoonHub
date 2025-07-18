#include<bits/stdc++.h>
using namespace std;
int main(){
    int x=1500,t=4;
    while(t--){
        int y;cin>>y;
        x-=y;
    }
    printf(x>=0?"Yes":"No");
}