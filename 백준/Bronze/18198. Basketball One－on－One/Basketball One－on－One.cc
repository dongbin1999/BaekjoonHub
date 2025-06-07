#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int x=0;
    for(int i=1;i<s.size();i+=2){
        int k=s[i]-'0';
        if(s[i-1]=='B')k*=-1;
        x+=k;
    }
    printf("%c",'A'+(x<0));
}