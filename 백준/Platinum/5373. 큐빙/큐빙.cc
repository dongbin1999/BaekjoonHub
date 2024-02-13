#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> tup;
string turn[6],all="UDFBLR";
vector<int> cw={6,3,0,7,4,1,8,5,2},ccw={2,5,8,1,4,7,0,3,6};
array<tup,4> change[6];
unordered_map<char,int> idx;
char a[6][9];
void solve(){
    for(int i=0;i<9;i++){
        a[idx['U']][i]='w';a[idx['D']][i]='y';a[idx['F']][i]='r';
        a[idx['B']][i]='o';a[idx['L']][i]='g';a[idx['R']][i]='b';
    }
    int n;scanf("%d",&n);
    while(n--){
        char x,y;scanf(" %c %c",&x,&y);
        char b[6][9]={0};
        for(int i=0;i<4;i++){
            int j=(i+(y=='+'?1:3))%4;
            int s=idx[turn[idx[x]][i]],e=idx[turn[idx[x]][j]];
            for(int k=0;k<3;k++)
                b[e][change[idx[x]][j][k]]=a[s][change[idx[x]][i][k]];
        }
        for(int j=0;j<9;j++)b[idx[x]][j]=a[idx[x]][(y=='+'?idx[x]%2?ccw:cw:idx[x]%2?cw:ccw)[j]];
        for(int i=0;i<6;i++)for(int j=0;j<9;j++)if(b[i][j])a[i][j]=b[i][j];
    }
    for(int i=0;i<9;i++){
        printf("%c",a[idx['U']][i]);
        if(i%3==2)printf("\n");
    }
}
int main(){
    for(int i=0;i<6;i++)idx[all[i]]=i;
    turn[idx['U']]="FLBR";turn[idx['D']]="FRBL";
    turn[idx['F']]="URDL";turn[idx['B']]="ULDR";
    turn[idx['L']]="UFDB";turn[idx['R']]="UBDF";
    //U,B,L 우선.
    change[idx['U']]={tup{0,1,2},tup{0,1,2},tup{2,1,0},tup{2,1,0}};
    change[idx['D']]={tup{6,7,8},tup{8,7,6},tup{8,7,6},tup{6,7,8}};
    change[idx['F']]={tup{6,7,8},tup{2,5,8},tup{8,7,6},tup{8,5,2}};
    change[idx['B']]={tup{0,1,2},tup{6,3,0},tup{2,1,0},tup{0,3,6}};
    change[idx['L']]={tup{0,3,6},tup{0,3,6},tup{6,3,0},tup{6,3,0}};
    change[idx['R']]={tup{2,5,8},tup{8,5,2},tup{8,5,2},tup{2,5,8}};
    int t;scanf("%d",&t);
    while(t--)solve();
}