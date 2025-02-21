#include<bits/stdc++.h>
using namespace std;

char s[100];
bool f(string a,string b){
    if(a.size()+1!=b.size())return 0;
    for(int i=0;i<b.size();i++){
        string c=b.substr(0,i)+b.substr(i+1);
        if(a==c)return 1;
    }
    return 0;
}

int main(){
    int n;scanf("%d %s",&n,s);
    string init=s;
    vector<string> v;
    for(int i=0;i<n;i++){
        scanf("%s",s);
        v.push_back(s);
    }
    set<string> se;
    queue<string> q;q.push(init),se.insert(init);
    string ans;
    while(!q.empty()){
        auto cur=q.front();q.pop();
        if(ans.size()<cur.size())
            ans=cur;
        for(int i=0;i<n;i++)
            if(!se.count(v[i])&&f(cur,v[i]))
                se.insert(v[i]),q.push(v[i]);
    }
    for(auto i:ans)printf("%c",i);
}