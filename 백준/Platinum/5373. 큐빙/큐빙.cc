#include<bits/stdc++.h>
using namespace std;
#define i()x=='D'||x=='B'||x=='R'
string c[91],t[91],cw="630741852",ccw="258147036";int T,n,i,s,e,k;char a[91][9],x,y;
int main(){
    t['U']="FLBR",t['D']="FRBL",t['F']="URDL",t['B']="ULDR",t['L']="UFDB",t['R']="UBDF";
    c['U']="012012210210",c['D']="678876876678",c['F']="678258876852",c['B']="012630210036",c['L']="036036630630",c['R']="258852852258";
    for(cin>>T;T--;){
        for(i=9;i--;)a['U'][i]='w',a['D'][i]='y',a['F'][i]='r',a['B'][i]='o',a['L'][i]='g',a['R'][i]='b';
        for(cin>>n;n--;){
            cin>>x>>y;
            vector<array<int,3>> v;
            for(s=4;s--;){
                e=(s+(y=='+'?1:3))%4;
                for(k=3;k--;)v.push_back({t[x][e],c[x][e*3+k]-'0',a[t[x][s]][c[x][s*3+k]-'0']});
            }
            for(s=9;s--;)v.push_back({x,s,a[x][(y=='+'?i()?ccw:cw:i()?cw:ccw)[s]-'0']});
            for(auto[p,q,r]:v)a[p][q]=r;
        }
        for(i=0;i<9;i++){
            cout<<a['U'][i];
            if(i%3==2)cout<<'\n';
        }
    }
}
