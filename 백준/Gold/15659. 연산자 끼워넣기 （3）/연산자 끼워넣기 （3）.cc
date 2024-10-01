#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n),a(4);
    for(auto &x:v)scanf("%d",&x);
    for(auto &x:a)scanf("%d",&x);
    int mx=INT_MIN,mn=INT_MAX;
    for(int i=0;i<1<<((n-1)*2);i++){
        vector<int> b={0},A(4);
        int x=i;
        for(int j=0;j<n-1;j++)b.push_back(x%4),A[x%4]++,x/=4;
        if(a!=A)continue;
        vector<int> num;int plmi=0,cur=0;
        for(int j=0;j<n;j++)
            if(b[j]<2){
                num.push_back(plmi?-cur:cur);
                plmi=b[j],cur=v[j];
            }
            else b[j]>2?cur/=v[j]:cur*=v[j];
        num.push_back(plmi?-cur:cur);
        int cal=accumulate(num.begin(),num.end(),0);
        mx=max(mx,cal),mn=min(mn,cal);
    }
    printf("%d\n%d",mx,mn);
}
