#include<bits/stdc++.h>
using namespace std;

struct node{map<string,node> child;}root;
void insert(vector<string> &v,node &now=root,int d=0){
    if(!now.child.count(v[d]))now.child[v[d]]=node();
    if(d+1<v.size())insert(v,now.child[v[d]],d+1);
}

void go(node &now=root,int d=0){
    for(auto [s,nx]:now.child){
        int x=d;while(x--)cout<<"--";
        cout<<s<<endl;
        go(nx,d+1);
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string> v(n);
        for(auto &s:v)cin>>s;
        insert(v);
    }
    go();
}