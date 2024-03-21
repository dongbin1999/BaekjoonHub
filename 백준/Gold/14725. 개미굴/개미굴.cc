#include<bits/stdc++.h>
using namespace std;

//왜 unordered_map은 정의부터 안되지?
struct node{map<string,node> child;}root;
void insert(vector<string> &v,node &now=root,int i=0){
    if(!now.child.count(v[i]))now.child[v[i]]=node();
    if(i+1<v.size())insert(v,now.child[v[i]],i+1);
}

void go(node &now=root,int d=0){
    for(auto [cur,nx]:now.child){
        int x=d;while(x--)cout<<"--";
        cout<<cur<<endl;
        go(nx,d+1);
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string> v(n);
        for(auto &s:v)cin>>s;
        string now="",nx;
        insert(v);
    }
    go();
}