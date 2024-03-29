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
    if(a<b)swap(a,b);
    if(a%b==0)return 1;
    ll win=0;
    int x=b;while(x<=a)win|=!bruteforce(b,a-x),x*=b;
    return win;
}

void solve(){
    ll a,b;scanf("%lld%lld",&a,&b);
    printf(f(a,b)?"Mirek\n":"Kamil\n");
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
}