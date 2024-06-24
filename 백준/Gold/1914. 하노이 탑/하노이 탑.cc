#include<bits/stdc++.h>
using namespace std;
void hanoi(int n,int from=1,int tmp=2,int to=3){
    if(n==1){printf("%d %d\n",from,to);return;}
    hanoi(n-1,from,to,tmp);
    printf("%d %d\n",from,to);
    hanoi(n-1,tmp,from,to);
}

int main(){
    int n;scanf("%d",&n);
    __int128 ans=1;
    int nn=n;while(nn--)ans*=2;ans--;
    vector<int> v;while(ans)v.push_back(ans%10),ans/=10;
    for(int i=v.size()-1;i>=0;i--)printf("%d",v[i]);
    if(n<=20){
        printf("\n");
        hanoi(n);
    }
}