#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    int m;scanf("%d",&m);
    while(m--){
        int x;scanf("%d",&x);
        auto it=lower_bound(v.begin(),v.end(),x);
        printf("%d ",it!=v.end()&&*it==x);
    }
    return 0;
}