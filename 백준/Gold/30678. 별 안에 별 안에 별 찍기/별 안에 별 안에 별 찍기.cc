#include <bits/stdc++.h>
using namespace std;

char b[5000][5000];

vector<vector<bool>> v=
        {{0,0,1,0,0},
         {0,0,1,0,0},
         {1,1,1,1,1},
         {0,1,1,1,0,},
         {0,1,0,1,0}};

int main(){
    int n;scanf("%d",&n);
    int mx=1,enter=1;for(int i=0;i<n;i++)mx*=25,enter*=5;
    for(int i=0;i<mx;i++){
        bool print=true;
        int val=i;
        int r=0,c=0;
        for(int j=0;j<n;j++){
            int x=val%25/5,y=val%25%5;
            print&=v[x][y];
            val/=25;
            r=r*5+x,c=c*5+y;
        }
        b[r][c]=print?'*':' ';
    }
    for(int i=0;i<enter;i++)printf("%s\n",b[i]);
    return 0;
}