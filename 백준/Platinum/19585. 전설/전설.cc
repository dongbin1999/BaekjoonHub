#include<bits/stdc++.h>
using namespace std;

const int sz=4000*1000;
string s,team,r;
int numbering;
unordered_set<string> se;

struct node{
    int ma[26];
    bool exist;

}trie[sz+1];

void insert(int i=0,int node=0){
    if(i==s.size()){trie[node].exist=1;return;}
    if(!trie[node].ma[s[i]-'a'])trie[node].ma[s[i]-'a']=++numbering;
    insert(i+1,trie[node].ma[s[i]-'a']);
}
bool find(){
    int node=0;
    for(auto c:s){
        if(!trie[node].ma[c-'a'])return 0;
        node=trie[node].ma[c-'a'];
        r.pop_back();
        if(trie[node].exist&&se.contains(r))return 1;
    }
    return 0;
}

void solve(){
    cin>>s;
    r=s,reverse(r.begin(),r.end());
    team.clear();
    if(find()){cout<<"Yes\n";return;}
    cout<<"No\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,n;cin>>c>>n;
    while(c--)cin>>s,insert();
    while(n--)cin>>s,reverse(s.begin(),s.end()),se.insert(s);
    int q;cin>>q;
    while(q--)solve();
}