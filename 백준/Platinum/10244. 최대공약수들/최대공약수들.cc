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
            int gcd=0;
            for(auto i:v){
                if(__gcd(gcd,i)%x==0)gcd=__gcd(gcd,i);
                else gcd=0;
                if(gcd==x)ans.insert(x);
            }
        }
        printf("%d\n",ans.size());
    }
}