#include<bits/stdc++.h>
using namespace std;
char s[500005];
string x;
void f(){
    while(x.size()>=3&&x.substr(x.size()-3)=="ABB"){
        x.pop_back();x.pop_back();x.pop_back();
        x+='B',f(),x+='A';
    }
}
void solve(){
    int n;scanf("%d %s",&n,s);
    x.clear();
    for(int i=0;i<n;i++)x+=s[i],f();
    for(auto i:x)printf("%c",i);
    printf("\n");
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}