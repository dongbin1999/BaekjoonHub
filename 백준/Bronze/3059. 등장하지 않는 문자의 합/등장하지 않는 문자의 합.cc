#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        set<int> se;
        se.insert(s.begin(),s.end());
        int ans=0;
        for(int i='A';i<='Z';i++)if(!se.count(i))ans+=i;
        cout<<ans<<'\n';
    }
}