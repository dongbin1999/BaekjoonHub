#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;cin>>a;
    getchar();
    getline(cin,b);
    set<int> se;
    for(auto i:b){
        se.insert(i);
        if(islower(i))se.insert(i-'a'+'A');
        else se.insert(i-'A'+'a');
    }
    for(auto i:a){
        if(se.count(i)&&!islower(i))cout<<(char)(i-'A'+'a');
        else cout<<i;
    }
}