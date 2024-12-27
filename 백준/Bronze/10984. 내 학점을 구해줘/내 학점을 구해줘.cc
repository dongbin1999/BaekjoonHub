#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;scanf("%d",&n);
    int a=0;double b=0;
    while(n--){
        int x;double y;scanf("%d%lf",&x,&y);
        a+=x,b+=y*x;
    }
    printf("%d %lf\n",a,b/a);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}