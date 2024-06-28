#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    vector<int> ans;
    set<int> se;
    for(int i=0;i<n-1;i++){
        se.insert(v[i]);
        if(se.size()==i+1&&*prev(se.end())==i+1){
            ans.push_back(i+1);
            se.erase(se.find(v[i]));
            swap(v[i],v[i+1]);
            se.insert(v[i]);
        }
    }
    printf("%d\n",ans.size());
    for(auto i:ans)printf("%d ",i);
    printf("\n");
}
int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}