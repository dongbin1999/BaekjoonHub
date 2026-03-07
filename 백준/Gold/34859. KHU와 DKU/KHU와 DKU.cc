#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;scanf("%d",&n);
    int d,k,h,u;scanf("%d%d%d%d",&d,&h,&k,&u);
    deque<char> dq;
    while(k--)dq.push_back('K');
    while(u--)dq.push_back('U');
    if(d<=n&&h<=n){
        while(d--)dq.push_front('D');
        while(h--)dq.push_back('H');
    }
    else if(d>n){
        while(d--)dq.push_back('D');
        while(h--)dq.push_back('H');
    }
    else{
        while(h--)dq.push_front('H');
        while(d--)dq.push_front('D');
    }
    printf("YES\n");
    for(auto i:dq)printf("%c",i);
    printf("\n");
}
int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
}