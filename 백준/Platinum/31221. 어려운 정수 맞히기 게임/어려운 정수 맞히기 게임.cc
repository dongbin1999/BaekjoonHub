#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans=123212321232123212ll,cnt;

char question(ll a,ll b){
    printf("? %lld %lld\n",a,b);
    fflush(stdout);
//    cnt++;
//    if(ans-a<0){
//        printf("!\n");return '!';
//    }
//    else if(ans>a+b*b){
//        printf("+\n");
//        return '+';
//    }
//    else if(ans<a+b*b){
//        printf("-\n");
//        return '-';
//    }
//    else return '0';
    char x;scanf(" %c",&x);
    return x;
}

void solve(){
    ll l,r,a,b;
    l=0,r=1e9,b=0;
    while(l<=r){
        ll mid=(l+r)/2;
        char c=question(0,mid);
        if(c=='0'){
            printf("! %lld\n",mid*mid);
            fflush(stdout);
            return;
        }
        else if(c=='+')b=max(b,mid),l=mid+1;
        else if(c=='-')r=mid-1;
        else assert(0);
    }
    l=0,r=b*3,a=0;
    while(l<=r){
        ll mid=(l+r)/2;
        char c=question(mid,b);
        if(c=='0'){
            printf("! %lld\n",mid+b*b);
            fflush(stdout);
            return;
        }
        else if(c=='+')l=mid+1;
        else if(c=='-')a=max(a,mid),r=mid-1;
        else assert(0);
    }
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}
