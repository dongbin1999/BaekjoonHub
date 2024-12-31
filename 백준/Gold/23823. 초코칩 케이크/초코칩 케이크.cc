#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int n,q;scanf("%d%d",&n,&q);
    vector<int> a(30001),b(30001);
    pii amx={0,n},bmx={0,n};
    while(q--){
        int t,x;scanf("%d%d",&t,&x);
        if(t==1){
            if(a[x]==amx.first)amx={amx.first+1,1};
            else if(a[x]==amx.first-1)amx.second++;
            a[x]++;
        }
        else{
            if(b[x]==bmx.first)bmx={bmx.first+1,1};
            else if(b[x]==bmx.first-1)bmx.second++;
            b[x]++;
        }
        printf("%d\n",amx.second*bmx.second);
    }
}