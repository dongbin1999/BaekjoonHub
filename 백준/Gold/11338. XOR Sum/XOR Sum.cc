#include <bits/stdc++.h>
using namespace std;
char s[10];
void solve(){
    int n,k;scanf("%d%d",&n,&k);
    priority_queue<int,vector<int>,greater<int>> pq;
    int XOR=0;
    while(n--){
        scanf("%s",s);
        if(s[0]=='i'){
            int x;scanf("%d",&x);
            pq.push(x),XOR^=x;
        }
        else{
            while(pq.size()>k){
                XOR^=pq.top();
                pq.pop();
            }
            printf("%d\n",XOR);
        }
    }
}
int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}