#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;string s;
    getline(cin,s);
    while(n--){
        getline(cin,s);
        cout<<s;
        printf(s.back()=='.'?"\n":".\n");
    }
}