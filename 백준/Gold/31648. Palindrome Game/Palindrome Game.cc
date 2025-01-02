#include<bits/stdc++.h>
using namespace std;
char s[200000];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%s",s+1);
        int n=strlen(s+1);
        printf(s[n]=='0'?"E\n":"B\n");
    }
}