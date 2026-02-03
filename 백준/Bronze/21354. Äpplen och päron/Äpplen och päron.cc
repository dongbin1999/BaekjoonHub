#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y;cin>>x>>y;
    x*=7,y*=13;
    if(x>y)cout<<"Axel";
    else if(x==y)cout<<"lika";
    else cout<<"Petra";
}