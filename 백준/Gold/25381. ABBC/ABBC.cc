#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int n=s.size();
    vector<bool> vis(n);
    queue<int> q;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='B')q.push(i);
        else if(s[i]=='C'){
            if(q.empty())continue;
            vis[i]=vis[q.front()]=1,cnt++,q.pop();
        }
    }
    string ss;
    while(!q.empty())q.pop();
    for(int i=0;i<n;i++)if(!vis[i])ss+=s[i];
    n=ss.size();
    for(int i=0;i<n;i++){
        if(ss[i]=='A')q.push(i);
        else if(ss[i]=='B'){
            if(q.empty())continue;
            cnt++,q.pop();
        }
    }
    cout<<cnt;
    return 0;
}