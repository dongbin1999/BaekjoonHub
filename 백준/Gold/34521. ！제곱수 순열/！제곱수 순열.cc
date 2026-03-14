#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        if(n<5){
            for(int i=1;i<=n;i++)printf("%d ",i);
            printf("\n");
        }
        else if(n<8){
            for(int i=5;i<=n;i++)printf("%d ",i);
            for(int i=1;i<=4;i++)printf("%d ",i);
            printf("\n");
        }
        else{
            vector<int> ans;
            for(int i=n/2*2;i>=2;i-=2)ans.push_back(i);
            ans.push_back(1);
            int x=n/4*4+1;if(x>n)x-=4;
            while(x>1)ans.push_back(x),x-=4;
            x=3;while(x<=n)ans.push_back(x),x+=4;
            for(auto i:ans)printf("%d ",i);
            printf("\n");
        }
    }
}