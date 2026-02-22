#include<bits/stdc++.h>
using namespace std;
char s[50][50];
int main(){
    int x=0;
    while(scanf("%s",s[x++])!=EOF);
    for(int j=0;j<20;j++)for(int i=0;i<x;i++)
        if(s[i][j])printf("%c",s[i][j]);
}