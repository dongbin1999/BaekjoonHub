#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    n+=m;
    set<string> se;
    while(n--){
        string s;cin>>s;
        se.insert(s);
    }
    cout<<se.size()<<endl;
}

int main(){
    int t;cin>>t;
    while(t--)solve();
}