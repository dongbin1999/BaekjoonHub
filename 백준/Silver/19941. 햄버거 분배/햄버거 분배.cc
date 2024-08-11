#include<bits/stdc++.h>
using namespace std;
typedef pair<char,int> pci;

int main(){
    int n,k;string s;
    cin>>n>>k>>s;
    deque<pci> dq;
    int ans=0;
    for(int i=0;i<n;i++){
        while(!dq.empty()&&i-dq.front().second>k)dq.pop_front();
        if(!dq.empty()&&dq.front().first!=s[i])ans++,dq.pop_front();
        else dq.push_back({s[i],i});
    }
    printf("%d",ans);
    return 0;
}