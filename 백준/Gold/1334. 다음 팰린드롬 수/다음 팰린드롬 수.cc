#include<bits/stdc++.h>
using namespace std;

bool b(string a,string b){
    if(a.size()==b.size())return a<b;
    return a.size()<b.size();
}
int main(){
    string s;cin>>s;
    string ans="9999999999999999999999999999999999999999999999999999";
    int n=s.size(),mid=(n-1)/2;
    while(mid>=0){
        string ss=s.substr(0,mid+1);
        int sz=ss.size();
        string cmp=ss;
        reverse(ss.begin(),ss.end());
        if(sz*2>n)cmp.pop_back();
        else for(int i=sz*2;i<n;i++)cmp+='0';
        cmp+=ss;
        if(b(s,cmp))if(b(cmp,ans))ans=cmp;

        reverse(ss.begin(),ss.end());
        if(ss.back()<'9'){
            ss.back()++;cmp=ss;
            reverse(ss.begin(),ss.end());
            if(sz*2>n)cmp.pop_back();
            else for(int i=sz*2;i<n;i++)cmp+='0';
            cmp+=ss;
            if(b(s,cmp))if(b(cmp,ans))ans=cmp;
        }
        mid--;
    }
    if(ans.size()>50){
        ans="1";
        for(int i=1;i<=n-1;i++)ans+='0';
        ans+="1";
    }
    cout<<ans;
    return 0;
}