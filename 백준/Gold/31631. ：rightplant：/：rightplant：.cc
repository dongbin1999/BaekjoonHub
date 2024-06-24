#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> ans={1,2};
    while(ans.size()<n){
        int all=accumulate(ans.begin(),ans.end(),0);
        int idx=0,sum=0;
        for(int i=0;i<ans.size();i++){
            sum+=ans[i];
            if(sum+sum>all){idx=i;break;}
        }
        vector<int> v;
        for(int i=0;i<idx;i++)v.push_back(ans[i]+1);
        v.push_back(1);
        for(int i=idx;i<ans.size();i++)v.push_back(ans[i]+1);
        ans=v;
    }
    for(auto i:ans)printf("%d ",i);
}