#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=24*60*60;
ll a[sz+2],sum[sz+2],b;

void init(){
    if(b)return; b=1; //2번 쿼리가 수행되는 처음 한 번만 초기화.
    for(int t=1;t<=sz;t++){
        a[t]+=a[t-1];
        sum[t]=sum[t-1]+a[t];
    }
}

void add(int s,int e){
    a[s]++,a[e]--;
}

int main(){
    int n;scanf("%d",&n);
    while(n--){
        int q,h1,m1,s1,h2,m2,s2;
        scanf("%d %d:%d:%d %d:%d:%d",&q,&h1,&m1,&s1,&h2,&m2,&s2);
        int s=h1*3600+m1*60+s1,e=h2*3600+m2*60+s2;
        s++,e++;//1부터 시작하도록 1칸 이동.
        if(q==1){
            add(s,e);
        }
        else{
            init();
            printf("%lld\n",sum[e-1]-sum[s-1]);
        }
    }
    return 0;
}