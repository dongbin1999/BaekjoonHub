#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    while(n--){
        string s;cin>>s;
        int c=0,n=s.size();
        for(auto i:s)c+=i=='a';
        c=min(c,n-c);
        cout<<c<<endl;
    }
}