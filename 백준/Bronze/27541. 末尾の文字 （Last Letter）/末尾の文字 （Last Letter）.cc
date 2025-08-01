#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;string s;cin>>n>>s;
    if(s.back()=='G')s.pop_back();
    else s+='G';
    cout<<s;
}