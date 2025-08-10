#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v={0,1};
    while(n--){
        int x,l,r;scanf("%d%d%d",&x,&l,&r);
        v.push_back(v[r]-v[l-1]==(2-x)*(r-l+1));
        printf(v.back()?"Yes\n":"No\n");
        v.back()+=v[v.size()-2];
    }
}