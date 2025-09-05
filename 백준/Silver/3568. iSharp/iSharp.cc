#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    string x,y;
    int i=0;
    while(s[i]!=' ')y+=s[i],i++;
    vector<string> v;
    while(i<s.size()){
        if(s[i]==' ')x.clear();
        else if(s[i]==','||s[i]==';')v.push_back(x);
        else x+=s[i];
        i++;
    }
    for(auto p:v){
        cout<<y;
        reverse(p.begin(),p.end());
        string z;
        while(isalpha(p.back()))z+=p.back(),p.pop_back();
        for(int i=0;i<p.size();i++)if(p[i]=='[')swap(p[i],p[i-1]);
        cout<<p<<' '<<z<<";\n";
    }
}