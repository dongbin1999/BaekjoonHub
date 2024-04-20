#include<bits/stdc++.h>
using namespace std;
set<char> valid={'<','>','+','-','.','[',']'};
void solve(){
    int sz=32768;
    vector<int> val(sz);int ptr=0;
    string ans,s;
    stack<int> st;
    while(1){
        string line;getline(cin,line);
        if(line=="end")break;
        //문자열 정리
        string ss;
        for(auto c:line)
            if(c=='%')break;
            else if(valid.count(c))ss+=c;
        s+=ss;
    }
    vector<pair<char,int>> v;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c=='['||c==']')v.push_back({c,i});
    }

    //괄호 이동 위치 구현
    map<int,int> warp;
    for(auto [c,i]:v)
        if(c==']'){
            if(st.empty()){cout<<"COMPILE ERROR\n";return;}
            warp[i]=st.top(),warp[st.top()]=i,st.pop();
        }
        else st.push(i);
    if(!st.empty()){cout<<"COMPILE ERROR\n";return;}

    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c=='['&&!val[ptr])i=warp[i]-1;
        else if(c==']'&&val[ptr])i=warp[i]-1;
        else if(c=='>')ptr=(ptr+1)%32768;
        else if(c=='<')ptr=(ptr+32767)%32768;
        else if(c=='+')val[ptr]=(val[ptr]+1)%256;
        else if(c=='-')val[ptr]=(val[ptr]+255)%256;
        else if(c=='.')ans+=val[ptr];
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"PROGRAM #"<<i<<":\n";
        solve();
    }
}