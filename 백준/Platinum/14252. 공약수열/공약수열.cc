#include <bits/stdc++.h>
using namespace std;
int GCD(int a,int b){return b?GCD(b,a%b):a;}

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=1;i<v.size();i++){
        int gcd=GCD(v[i],v[i-1]);
        if(gcd==1)continue;
        bool add=1;
        for(int j=v[i-1]+1;j<v[i];j++)
            add&=GCD(v[i-1],j)!=1||GCD(v[i],j)!=1;
        ans+=1+add;
    }
    printf("%d",ans);
    return 0;
}