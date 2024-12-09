#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int n;scanf("%d",&n);
    vector<pii> v(n);
    for(auto &[a,b]:v)scanf("%d%d",&a,&b);
    int x;scanf("%d",&x);
    sort(v.begin(),v.end(),greater<pii>());
    for(int i=0;i<=x/v[0].first+1;i++){
        int k=v[0].first*i+v[0].second,sum=0,ok=1;
        for(auto [a,b]:v){
            if((k-b)%a||k<b){ok=0;break;}
            sum+=(k-b)/a;
        }
        if(sum==x)return !printf("%d",k);
    }
    printf("0");
    return 0;
}