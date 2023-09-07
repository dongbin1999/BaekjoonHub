#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
map<pii,int> ma;
map<int,pii> restore;
int numbering=10000;

vector<int> result(string a){
    vector<int> v;
    bool ok=1;
    for(int i=10000;i>=1;i--)v.push_back(i);
    for(auto i:a){
        if(v.empty())continue;
        if(i=='C'){
            v.push_back(v.back());
        }
        if(i=='D'){
            v.pop_back();
        }
        if(i=='L'){
            if(v.back()<=10000){
                ok=0;break;
            }
            else {
                auto [l,r]=restore[v.back()];
                v.pop_back();
                v.push_back(l);
            }
        }
        if(i=='P'){
            if(v.size()<2)continue;
            int x=v.back();v.pop_back();
            int y=v.back();v.pop_back();
            if(!ma[{x,y}]) ma[{x,y}]=++numbering,restore[numbering]={x,y};
            v.push_back(ma[{x,y}]);
        }
        if(i=='R'){
            if(v.back()<=10000){ok=0;break;}
            else {
                auto [l,r]=restore[v.back()];
                v.pop_back();
                v.push_back(r);
            }
        }
        if(i=='S'){
            if(v.size()<2)continue;
            int x=v.back();v.pop_back();
            int y=v.back();v.pop_back();
            v.push_back(x),v.push_back(y);
        }
        if(i=='U'){
            if(v.back()<=10000){ok=0;break;}
            auto [l,r]=restore[v.back()];
            v.pop_back();
            v.push_back(r),v.push_back(l);
        }
    }
    if(!ok)return {-1};
    return v;
}

int main(){
    string a,b;cin>>a>>b;
    cout<<(result(a)==result(b)?"True":"False");
    return 0;
}