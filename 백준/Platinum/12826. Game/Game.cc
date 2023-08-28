#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//풀이 : https://docplayer.net/35585040-Vpcpc-problems-and-sample-solutions.html

bool f(ll a,ll b){
    if(!a||!b)return 0;
    if(a<b)swap(a,b);
    if(a%b==0)return 1;
    ll win=!f(a%b,b);
    ll x=a/b;
    if(b%2)win|=x%2==0;
    else win|=x%(b+1)%2==0;
    return win;
}

bool bruteforce(ll a,ll b){
    if(!a||!b)return 0;
    if(a>b)swap(a,b);
    if(b%a==0)return 1;
    ll win=0;
    int x=a;while(x<=b)win|=!bruteforce(a,b-x),x*=a;
    return win;
}

void solve(){
    ll a,b;scanf("%lld%lld",&a,&b);
    //printf("%d %d\n",f(a,b),bruteforce(a,b));
    printf(f(a,b)&1?"Mirek\n":"Kamil\n");
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
}