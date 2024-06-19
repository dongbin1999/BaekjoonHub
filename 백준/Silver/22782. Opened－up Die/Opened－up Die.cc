#include<bits/stdc++.h>
using namespace std;

map<string,int> ma;
void ok(string s){
    int sum=abs(s[0]-s[2])+abs(s[2]-s[5]);
    for(int i=1;i<4;i++)sum+=abs(s[i]-s[i+1]);
    ma[s]=sum;
}

void solve(){
    string s;cin>>s;
    vector<int> a;vector<bool> b(6);
    for(int i=0;i<6;i++)if(s[i]=='x')a.push_back(i);
    else b[s[i]-'1']=1;
    vector<char> c;
    for(int i=0;i<6;i++)if(!b[i])c.push_back(i+'1');
    sort(c.begin(),c.end());
    pair<int,string> ans={1e9,""};
    do{
        string ss=s;
        for(int i=0;i<a.size();i++)ss[a[i]]=c[i];
        ans=min(ans,{ma[ss],ss});
    }while(next_permutation(c.begin(),c.end()));
    cout<<ans.second<<endl;
}

int main(){
    string s="123456";
    do{
        ok(s);
    }while(next_permutation(s.begin(),s.end()));
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}