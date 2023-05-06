#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,c;scanf("%d%d",&n,&c);
    vector<bool> v(c+1,0);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]==c)return !printf("1");
        if(a[i]<c)v[a[i]]=1;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
        int x=c-a[i]-a[j];
        if(!x)return !printf("1");
        if(x>0&&x!=a[i]&&x!=a[j]&&v[x])return !printf("1");
    }
    printf("0");
}