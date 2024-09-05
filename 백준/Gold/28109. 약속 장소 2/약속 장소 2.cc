#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;string s;cin>>n>>k>>s;
    string c=s;
    int idx=0;
    while(k&&idx<n){
        c[idx]='A';
        while(1){
            if(s[idx]==c[idx])break;
            if(!--k)break;
            c[idx]++;
        }
        idx++;
    }
    if(!k){cout<<c;return 0;}
    if(!--k){cout<<s;return 0;}
    c=s;
    idx=n-1;
    while(k&&idx>=0){
        while(1){
            if(c[idx]=='Z')break;
            c[idx]++;
            if(!--k)break;
        }
        if(k)c[idx]=s[idx];
        idx--;
    }
    if(!k){cout<<c;return 0;}
    cout<<-1;
}