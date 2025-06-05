#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x,y;scanf("%d%d",&x,&y);
    if(x+y&1){printf("-1\n");return;}
    int b=x>y;
    if(b)swap(x,y);
    int d=(y-x)/2;
    if(x+d==(y^d))printf("1\n%c %d\n",'B'-b,d);
    else printf("2\n%c %d\n%c %d\n",'B'-b,d,'B'-b,d);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}