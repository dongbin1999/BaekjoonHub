#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        string a,b;cin>>a>>b;
        if(a=="E")break;
        int x=0,y=0;
        map<char,char>ma;
        ma['R']='S',ma['S']='P',ma['P']='R';
        for(int i=0;i<a.size();i++){
            if(ma[a[i]]==b[i])x++;
            if(ma[b[i]]==a[i])y++;
        }
        printf("P1: %d\nP2: %d\n",x,y);
    }
    return 0;
}