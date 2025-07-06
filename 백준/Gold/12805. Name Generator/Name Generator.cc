#include<bits/stdc++.h>
using namespace std;

vector<string> ans,cur;
deque<char> dq;
void go(int x,int c=0){
    if(c==x){
        while(!dq.empty())cur.back()+=dq.front(),dq.pop_front();
        set<string> se;
        for(auto i:cur)se.insert(i);
        if(se.size()==x)ans=cur;
        return;
    }
    for(int l=1;l<=dq.size();l++){
        string s;
        for(int i=0;i<l;i++)s+=dq.front(),dq.pop_front();
        cur.push_back(s),go(x,c+1);
        while(!cur.back().empty())dq.push_front(cur.back().back()),cur.back().pop_back();
        cur.pop_back();
    }
}

void solve(){
    ans.clear(),dq.clear();
    string s;int x;
    cin>>s>>x;
    for(auto i:s)dq.push_back(i);
    if(s.size()>=15){
        for(int i=1;i<=x;i++){
            string ss;
            for(int j=0;j<i;j++)ss+=dq.front(),dq.pop_front();
            ans.push_back(ss);
        }
        while(!dq.empty())ans.back()+=dq.front(),dq.pop_front();
    }
    else go(x);
    if(ans.empty()){printf("NO\n");return;}
    printf("YES\n");
    for(auto i:ans)cout<<i<<'\n';
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}