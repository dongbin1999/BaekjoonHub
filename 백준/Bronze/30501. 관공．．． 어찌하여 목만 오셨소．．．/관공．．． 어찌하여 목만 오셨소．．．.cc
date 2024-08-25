#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    while(n--){
        string s;cin>>s;
        for(auto i:s)if(i=='S'){
            cout<<s;
            return 0;
        }
    }
    return 0;
}