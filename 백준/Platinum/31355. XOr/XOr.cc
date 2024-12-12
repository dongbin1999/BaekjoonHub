#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,ans=0,x=0;scanf("%d%d",&n,&m);
    vector<int> a(n);
    unordered_set<int> se;for(int i=0;i<n;i++)se.insert(i);
    for(int i=0;i<n;i++)scanf("%d",&a[i]),x^=a[i];
    for(int i=30;i>=0;i--){
        if(x>>i&1){ans+=1<<i;continue;}
        int y=0;
        unordered_set<int> cur;
        for(int j=0;j<n;j++){
            y^=a[j];
            if(!(y>>i&1)&&se.count(j))cur.insert(j);
        }
        if(cur.size()<m)ans+=1<<i;
        else se=cur;
    }
    printf("%d",ans);
}