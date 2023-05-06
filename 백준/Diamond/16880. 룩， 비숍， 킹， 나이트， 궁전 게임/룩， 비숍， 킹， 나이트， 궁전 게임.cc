#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> d={1,3};while(d.back()<1e9)d.push_back(d.back()*2);
    int n,ans=0;scanf("%d",&n);
    while(n--){
        int x,y;char c;
        scanf(" %d %d %c",&x,&y,&c);
        if(c=='R')ans^=x^y;
        else if(c=='B')ans^=min(x,y);
        else if(c=='K'){
            int mn=min(x,y),diff=abs(x-y);
            int z=2*(mn%2)+diff%2;
            ans^=z;
        }
        else if(c=='N'){
            int a[4][4]={{0,0,0,0},{0,0,1,1},{0,1,1,1},{0,1,1,0}};
            int mi=min(x/3,y/3)*3,z;
            x-=mi,y-=mi;
            if(x<4&&y<4)z=a[x][y];
            else if(x>=4)z=y%3;
            else z=x%3;
            ans^=z;
        }
        else if(c=='P'){
            int a[3][3]={{0,1,2},{1,2,0},{2,0,1}};
            vector<int> ai(d.size(),0),aj(d.size(),0);
            for(int k=d.size()-1;k>=0;k--){
                while(x>=d[k])ai[k]++,x-=d[k];
                while(y>=d[k])aj[k]++,y-=d[k];
            }
            vector<int> res(d.size(),0);
            int z=a[ai[0]][aj[0]];
            for(int k=1;k<d.size();k++)res[k]=ai[k]^aj[k],z+=res[k]*d[k];
            ans^=z;
        }
    }
    printf(ans?"koosaga":"cubelover");
    return 0;
}