#include<bits/stdc++.h>
using namespace std;
vector<int> ans,cur;
void go(){
    if(ans.size()<cur.size())ans=cur;
    else if(ans.size()==cur.size())ans=min(ans,cur);

    string c=to_string(cur.back());
    int n=c.size(),num=cur.back();
    for(int i=1;i<1<<n;i++){
        string a,b;
        for(int j=0;j<n;j++)if(i>>j&1)a+=c[j];
        else b+=c[j];
        if(a.empty()||b.empty()||a[0]=='0')continue;
        int x=stoi(a),y=stoi(b);
        if(x<=1)continue;
        if(num%x==0){
            cur.push_back(y);
            go();
            cur.pop_back();
        }
    }
}
int main(){
    int n;cin>>n;
    cur.push_back(n);
    go();
    for(auto i:ans)cout<<i<<' ';
}