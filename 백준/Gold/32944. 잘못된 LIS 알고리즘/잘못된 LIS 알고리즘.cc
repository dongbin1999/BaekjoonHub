#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;cin>>n>>m>>k;
    if(n==m){cout<<-1;return 0;}
    int d=n-m-1,x=d+1;
    for(int i=1;i<k;i++)cout<<x++<<' ';
    cout<<n<<' ';
    while(x<n)cout<<x++<<' ';
    for(int i=d;i>=1;i--)cout<<i<<' ';
}