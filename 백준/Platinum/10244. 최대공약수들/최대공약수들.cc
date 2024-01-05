#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int n;scanf("%d",&n);
        if(!n)break;
        vector<int> v(n);
        set<int> ans;
        for(auto &x:v)scanf("%d",&x);
        for(int x=1;x<=100;x++){
            int a=0;
            for(auto i:v){
                if(gcd(a,i)%x==0)a=gcd(a,i);
                else a=0;
                if(a==x)ans.insert(x);
            }
        }
        printf("%d\n",ans.size());
    }
}