#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        while(n>=5)n-=5,cout<<"++++ ";
        while(n--)cout<<'|';
        cout<<endl;
    }
}