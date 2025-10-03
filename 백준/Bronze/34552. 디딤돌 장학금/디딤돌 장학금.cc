#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> m(11);
    for(auto &x:m)scanf("%d",&x);
    int n,ans=0;scanf("%d",&n);
    while(n--){
        int b,s;double l;scanf("%d %lf %d",&b,&l,&s);
        if(l<2.0||s<17)continue;
        ans+=m[b];
    }
    printf("%d",ans);
}
