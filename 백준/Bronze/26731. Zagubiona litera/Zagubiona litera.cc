#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    for(char a='A';a<='Z';a++){
        bool b=0;
        for(auto c:s)b|=a==c;
        if(!b)return !printf("%c",a);
    }
}