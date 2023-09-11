#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;scanf("%d%d",&a,&b);
    string r(a,'.'),c(b,'.');
    vector<string> v(a);
    for(int i=0;i<a;i++)cin>>v[i];
    int x=0,y=0;
    for(int i=0;i<a;i++)x+=v[i]==c;
    for(int i=0;i<b;i++){
        string cmp;
        for(int j=0;j<a;j++)cmp+=v[j][i];
        y+=cmp==r;
    }
    printf("%d",max(x,y));
    return 0;
}