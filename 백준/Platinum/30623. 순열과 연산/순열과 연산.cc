#include <bits/stdc++.h>
using namespace std;
int n;
void operation(vector<int> &v,int op){
    if(op==1)swap(v[1],v[2]);
    else if(op==2)swap(v[n-1],v[n]);
    else if(op==3){
        int mn=min(v[1],v[n]),mx=max(v[1],v[n]);
        for(int i=2;i<n;i++)
            if(v[i]<mn)v[i]=mx;
            else if(v[i]>mx)v[i]=mn;
    }
}
int main(){
    scanf("%d",&n);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    vector<vector<int>> ans;
    for(int i=0;i<256;i++){
        vector<int> vv=v;
        int x=i;
        while(x)operation(vv,x%4),x/=4;
        if(*max_element(vv.begin()+1,vv.end())==*min_element(vv.begin()+1,vv.end())){
            x=i;
            while(x){
                if(x%4==1)ans.push_back({1,1});
                else if(x%4==2)ans.push_back({1,n-1});
                else ans.push_back({2,1,n});
                x/=4;
            }
            printf("%d\n",ans.size());
            for(auto k:ans){
                for(auto j:k)printf("%d ",j);
                printf("\n");
            }
            return 0;
        }
    }
    assert(0);
    return 0;
}