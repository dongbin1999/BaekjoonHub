#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]),a[v[i]]=1;
    deque<int> dq;
    for(int i=1;i<=n+n;i++)if(!a[i])dq.push_back(i);
    int ans=0;
    sort(v.begin(),v.begin()+n/2,greater<int>());
    sort(v.end()-n/2,v.end());
    for(int i=0;i<n/2;i++)
        if(dq.back()>v[i])dq.pop_back(),ans++;
    for(int i=n/2;i<n;i++)
        if(dq.front()<v[i])dq.pop_front(),ans++;
    printf("%d",ans);
}