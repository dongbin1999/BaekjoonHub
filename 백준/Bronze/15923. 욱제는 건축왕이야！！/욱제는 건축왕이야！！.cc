#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    vector<int> x,y;
    while(n--){
        int a,b;scanf("%d%d",&a,&b);
        x.push_back(a),y.push_back(b);
    }
    sort(x.begin(),x.end()),sort(y.begin(),y.end());
    printf("%d",(x.back()-x[0]+y.back()-y[0])*2);
}