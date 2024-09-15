#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,d;scanf("%d%d",&n,&d);
    vector<int> v;
    while(n--){
        sort(v.begin(),v.end());
        int x;scanf("%d",&x);
        if(v.empty()||v[0]-d>=x){printf("%d ",x),v.push_back(x);continue;}
        int add=max(x,v.back()+d);
        for(int l=0,r=1;r<v.size();l++,r++)
            if(max(x,v[l]+d)<=v[r]-d)add=min(add,max(x,v[l]+d));
        printf("%d ",add),v.push_back(add);
    }
}