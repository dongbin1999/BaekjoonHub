#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    int ans=0;
    while(v.size()>1){
        int x=max_element(v.begin(),v.end())-v.begin();
        vector<int> t={x?v[x]-v[x-1]:1<<30,x<v.size()-1?v[x]-v[x+1]:1<<30};
        ans+=min(t[0],t[1]);
        v.erase(v.begin()+x);
    }
    printf("%d",ans);
    return 0;
}