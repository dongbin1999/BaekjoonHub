#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int n;scanf("%d",&n);
        if(!n)break;
        vector<int> v(n);
        for(int i=0;i<n;i++)scanf("%d",&v[i]);
        vector<int> vv=v;
        sort(vv.begin(),vv.end(),greater<int>());
        map<int,int> ma;int sum=0;
        for(int i=0;i<n;i++){
            sum+=i*(i?vv[i-1]-vv[i]:0);
            ma[vv[i]]=sum;
        }
        int ans=2e9;
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++)for(int l=k+1;l<n;l++){
            int d1=j-i,d2=k-j,d3=l-k,d4=n-l+i;
            if(2*d1<n&&2*d2<n&&2*d3<n&&2*d4<n)
                ans=min(ans,ma[min({v[i],v[j],v[k],v[l]})]);
        }
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++){
            int d1=j-i,d2=k-j,d3=n-k+i;
            if(2*d1<n&&2*d2<n&&2*d3<n)
                ans=min(ans,ma[min({v[i],v[j],v[k]})]);
        }
        printf("%d\n\n",ans);
    }
}