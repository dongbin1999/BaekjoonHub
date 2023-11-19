#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> a(n),cnt(1000001),idx(1000001,-1);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        if(idx[a[i]]==-1)idx[a[i]]=i+1;
    }
    vector<pair<int,int>> st;
    reverse(a.begin(),a.end());
    vector<int> ans;
    for(auto i:a){
        while(!st.empty()){
            if(st.back().first<=cnt[i])st.pop_back();
            else break;
        }
        if(st.empty())ans.push_back(-1);
        else ans.push_back(st.back().second);
        st.push_back({cnt[i],i});
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans)printf("%d ",i);
    return 0;
}