#include <bits/stdc++.h>
using namespace std;
char s[5]="NESW";
int main(){
    int x=10,z=0;
    while(x--){
        int y;scanf("%d",&y);
        z+=y;
    }
    printf("%c",s[z%4]);
    return 0;
}