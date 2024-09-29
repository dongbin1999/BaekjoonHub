#include<bits/stdc++.h>
using namespace std;

string keyboard[4],word;

int main(){
    for(int i=0;i<4;i++)cin>>keyboard[i];
    cin>>word;
    sort(word.begin(),word.end());
    for(int x=1;x<=2;x++)for(int y=1;y<=8;y++){
        string cmp;
        for(int i=x-1;i<=x+1;i++)for(int j=y-1;j<=y+1;j++)
            cmp+=keyboard[i][j];
        sort(cmp.begin(),cmp.end());
        if(word==cmp){
            cout<<keyboard[x][y];
            return 0;
        }
    }
}