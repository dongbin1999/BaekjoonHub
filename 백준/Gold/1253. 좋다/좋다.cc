#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    v.push_back(2e9);
    set<int> se;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
        int x= lower_bound(v.begin(),v.end(),v[i]+v[j])-v.begin();
        int y= upper_bound(v.begin(),v.end(),v[i]+v[j])-v.begin()-1;
        while(v[x]==v[i]+v[j]&&!(x!=i&&x!=j))x++;
        for(int k=x;k<=y;k++){
            if(se.count(k))break;
            else se.insert(k);
        }
    }
    printf("%d",se.size());
    return 0;
}