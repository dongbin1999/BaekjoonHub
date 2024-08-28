#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;getline(cin,s);
    if(s.size()<=2||s[0]!='"'||s.back()!='"'){
        cout<<"CE";
        return 0;
    }
    for(int i=1;i<s.size()-1;i++)printf("%c",s[i]);
}