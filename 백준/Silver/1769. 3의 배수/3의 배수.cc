#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;cin>>s;
    int c=0;
    while(s.size()>1){
        int x=0;for(auto i:s)x+=i-'0';
        s=to_string(x),c++;
    }
    printf("%d\n",c);
    printf(stoi(s)%3?"NO":"YES");
    return 0;
}