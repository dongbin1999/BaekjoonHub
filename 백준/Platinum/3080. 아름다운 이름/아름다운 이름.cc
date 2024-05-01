#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int sz=3000*3000;
string s;
int numbering;

struct node{
    vector<pair<char,int>> ma;
    bool exist;
}trie[sz+1];

void insert(int i=0,int node=0){
    if(i==s.size()){trie[node].exist=1;return;}
    int nx=-1;
    for(auto [a,b]:trie[node].ma)
        if(a==s[i]){nx=b;break;}
    if(nx==-1){
        trie[node].ma.push_back({s[i],++numbering});
        trie[node].ma.shrink_to_fit();
        nx=numbering;
    }
    insert(i+1,nx);
}

ll dfs(int node=0,int pa=-1){
    ll ret=1,cnt=0;
    if(trie[node].exist)cnt++;
    for(auto [al,nx]:trie[node].ma)if(nx!=pa)
        cnt++,ret=ret*dfs(nx,node)%mod*cnt%mod;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)cin>>s,insert();
    cout<<dfs();
}