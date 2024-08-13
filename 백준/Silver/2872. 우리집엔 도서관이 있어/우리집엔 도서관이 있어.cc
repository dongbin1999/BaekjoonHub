#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    int me=n,cnt=0;
    for(int i=n-1;i>=0;i--)if(me==v[i])cnt++,me--;
    printf("%d",n-cnt);
    return 0;
}