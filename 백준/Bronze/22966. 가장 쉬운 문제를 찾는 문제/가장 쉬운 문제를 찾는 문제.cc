#include<bits/stdc++.h>
using namespace std;
typedef pair<int,string> pis;

int main(){
    int n;cin>>n;
    vector<pis> v;
    while(n--){
        string s;int x;cin>>s>>x;
        v.push_back({x,s});
    }
    cout<<min_element(v.begin(),v.end())->second;
}