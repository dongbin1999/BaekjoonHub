#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        v[i]&=1;
    }
    ll a=0,b=0,c=0,d=0;
    for(ll i=0;i<n;i++){
        if(!v[i])b+=max(0ll,i-a),a++;
        else d+=max(0ll,i-c),c++;
    }
    printf("%lld",min(b,d));
    return 0;
}