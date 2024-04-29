#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b,c;
    cin>>a>>b>>c;
    string x,y="lkp";
    x+=a[0],x+=b[0],x+=c[0];
    sort(x.begin(),x.end());sort(y.begin(),y.end());
    printf(x==y?"GLOBAL":"PONIX");
}