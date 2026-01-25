#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int n;cin>>n;
        if(!n)break;
        int x=0;
        for(int i=1;i<=n;i++)x+=i*i;
        cout<<x<<endl;
    }
}