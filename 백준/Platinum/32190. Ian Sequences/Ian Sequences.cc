#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;scanf("%d",&n);
     vector<int> v;
     for(int i=n;i>=1;i--)v.push_back(i);
     if(n%2){
         v.push_back(1);
         for(int i=3;i<=n;i+=2)v.push_back(i),v.push_back(i-1);
     }
     else{
         for(int i=2;i<=n;i+=2)v.push_back(i),v.push_back(i-1);
     }
     for(auto i:v)printf("%d ",i);
}