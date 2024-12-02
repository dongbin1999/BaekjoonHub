#include <bits/stdc++.h>
using namespace std;
int a[4000];

int main(){
    int n;scanf("%d",&n);
    set<int> ans;
    set<int> se;
    for(int i=0;i<n;i++)scanf("%d",&a[i]),se.insert(a[i]);
    for(int i=1;i<n;i++){
        int d=a[i]-a[0];
        bool ok=1;
        set<int> x;
        for(int j=0;j<n;j++){
            if(x.count(a[j]))continue;
            if(se.count(a[j]+d))x.insert(a[j]),x.insert(a[j]+d);
            else if(x.count(a[j]-d))x.insert(a[j]);
            else ok=0;
        }
        if(ok)ans.insert(d);
    }
    printf("%d\n",ans.size());
    for(auto i:ans)printf("%d ",i);
}

