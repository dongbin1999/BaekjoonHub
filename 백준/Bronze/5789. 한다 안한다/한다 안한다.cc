#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    while(n--){
        string s;cin>>s;
        cout<<"Do-it";
        int x=s.size();
        if(s[(x-1)/2]!=s[x/2])cout<<"-Not";
        cout<<endl;
    }
}