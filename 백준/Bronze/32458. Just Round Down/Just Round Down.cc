#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;cin>>s;
    for(auto i:s){
        if(i=='.')return 0;
        cout<<i;
    }
}