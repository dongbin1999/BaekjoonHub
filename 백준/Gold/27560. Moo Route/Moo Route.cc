#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n+2);
    string ans;
    for(int i=0;i<n;i++)scanf("%d",&v[i+1]);
    int d=1,cur=1;
    while(1){
        if(d==1){
            if(!v[cur]){d^=1;continue;}
            ans+='R',v[cur++]--;
        }
        else{
            if(v[cur-1]<v[cur]){d^=1;continue;}
            if(cur==1)break;
            ans+='L',v[--cur]--;
        }
    }
    while(v[1])v[1]-=2,ans+="RL";
    for(auto c:ans)printf("%c",c);
}