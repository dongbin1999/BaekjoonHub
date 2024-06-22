#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;cin>>a>>b;
    printf("%d", to_string(stoi(a)+stoi(b)).size());
}