#include<bits/stdc++.h>
using namespace std;

char s[1000003];
vector<int> v={0};

int main(){
    int n;scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)if(s[i]=='S')v.push_back(i);
    for(int K=1;K<=n;K++){
        int cnt=0,k=K,pre=0,real=0;
        while(pre+1<v.size()&&k>=1){
            int mod=real%k,goal=v[pre+1]/k*k+mod;
            if(goal-k>=v[pre+1])goal-=k;
            if(goal<v[pre+1])goal+=k;
            if(goal>n)break;
            int idx=upper_bound(v.begin(),v.end(),goal)-v.begin()-1;
            cnt+=(goal-real)/k;
            int spades=idx-pre;k-=spades;
            real=goal,pre=idx;
        }
        if(k)cnt+=(n-real)/k;
        printf("%d ",cnt);
    }
}