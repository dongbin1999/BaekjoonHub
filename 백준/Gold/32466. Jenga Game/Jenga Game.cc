#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;scanf("%d",&n);
    int a=-1,b=0;
    while(n--){
        int x;scanf("%d",&x);
        if(x==111)a++;
        if(x==110||x==11)b++;
    }
    printf(a%2||b%2?"Yesyes\n":"Nono\n");
}
int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
}