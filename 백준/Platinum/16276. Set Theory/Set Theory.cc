#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    set<int> vv;
    vector<int> bb;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)vv.insert(abs(v[i]-v[j]));
    vector<int> b={1};
    for(int i=2;b.size()<n&&i<=1e6;i++){
        bool ok=1;
        for(int j=b.size()-1;j>=0;j--)
            if(vv.count(i-b[j])>0){ok=0;break;}
        if(ok)b.push_back(i);
    }
    printf("YES\n");
    for(auto i:b)printf("%d ",i);
    printf("\n");
}

int main() {
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}