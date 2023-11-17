#include <bits/stdc++.h>
using namespace std;
map<char,int> ma;

int main(){
    ma['P']=1,ma['p']=-1;
    ma['N']=3,ma['n']=-3;
    ma['B']=3,ma['b']=-3;
    ma['R']=5,ma['r']=-5;
    ma['Q']=9,ma['q']=-9;
    int t=8,ans=0;
    while(t--){
        string s;cin>>s;
        for(auto i:s)ans+=ma[i];
    }
    cout<<ans;
    return 0;
}
