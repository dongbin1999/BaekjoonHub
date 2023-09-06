#include <bits/stdc++.h>
using namespace std;

char c[99][7];

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<7;j++)
            c[i][j]=(i>>j&1)+'A';
    for(int j=0;j<7;j++){
        bool a=0,b=0;
        for(int i=0;i<n;i++)a|=c[i][j]=='A',b|=c[i][j]=='B';
        if(!a)c[0][j]='A'; if(!b)c[0][j]='B';
        for(int i=0;i<n;i++)printf("%c",c[i][j]);
        printf("\n");
    }
}