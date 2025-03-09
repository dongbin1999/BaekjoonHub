#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n;scanf("%d",&n);
    vector<pii> v(n);
    for(auto &[a,b]:v)scanf("%d%d",&a,&b);
    vector<int> ans(n);
    int x=0,l=0,r=300,sum=0;
    for(int i=0;i<n;i++){
        auto [ll,rr]=v[i];
        if(ll>r){
            int d=r;
            sum+=x?abs(r-ans[x-1]):0;
            for(int j=x;j<i;j++)ans[j]=d;
            l=ll,r=rr,x=i;
        }
        else if(rr<l){
            int d=l;
            sum+=x?abs(l-ans[x-1]):0;
            for(int j=x;j<i;j++)ans[j]=d;
            l=ll,r=rr,x=i;
        }
        else{
            l=max(l,ll),r=min(r,rr);
        }
        //printf("%d %d %d\n",l,r,sum);
    }
    if(!x)for(int j=x;j<n;j++)ans[j]=l;
    else if(abs(l-ans[x-1])<abs(r-ans[x-1])){
        sum+=abs(l-ans[x-1]);
        for(int j=x;j<n;j++)ans[j]=l;
    }
    else{
        sum+=abs(r-ans[x-1]);
        for(int j=x;j<n;j++)ans[j]=r;
    }
    printf("%d\n",sum);
    for(auto i:ans)printf("%d\n",i);
}