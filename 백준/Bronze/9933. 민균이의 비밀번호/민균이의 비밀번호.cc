#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    set<string> se;
    while(n--){
        string s;cin>>s;
        se.insert(s);
        reverse(s.begin(),s.end());
        if(se.count(s))return !printf("%d %c\n",s.size(),s[s.size()/2]);
    }
}