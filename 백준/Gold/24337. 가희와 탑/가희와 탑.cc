#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    if(a+b-1>n)return !printf("-1");
    vector<int> ans;
    if(a<b){
        for(int i=1;i<a;i++)ans.push_back(i);
        for(int i=b;i>=1;i--)ans.push_back(i);
    }
    else{
        for(int i=1;i<=a;i++)ans.push_back(i);
        for(int i=b-1;i>=1;i--)ans.push_back(i);
    }
    int one=n-ans.size();
    printf("%d ",ans[0]);
    while(one--)printf("1 ");
    for(int i=1;i<ans.size();i++)printf("%d ",ans[i]);
}