#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int ans=0;
    map<pair<int,int>,int> ma;
    ma[{136,68}]=1000,ma[{142,68}]=5000,ma[{148,68}]=10000,ma[{154,68}]=50000;
    while(n--){
        int a,b;scanf("%d%d",&a,&b);
        ans+=ma[{a,b}];
    }
    printf("%d",ans);
    return 0;
}
