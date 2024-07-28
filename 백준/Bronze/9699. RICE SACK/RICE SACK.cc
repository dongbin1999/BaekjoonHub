#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Case #%d: ",i);
        vector<int> v(5);
        for(auto &x:v)scanf("%d",&x);
        printf("%d\n",*max_element(v.begin(),v.end()));
    }
    return 0;
}