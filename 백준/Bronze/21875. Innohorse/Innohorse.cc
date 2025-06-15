#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;cin>>a>>b;
    int x=abs(a[0]-b[0]),y=abs(a[1]-b[1]);
    printf("%d %d",min(x,y),max(x,y));
    return 0;
}