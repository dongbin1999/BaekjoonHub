#include<bits/stdc++.h>
using namespace std;

int a[1000001];

int main(){
    int n;scanf("%d",&n);
    vector<char> v(n);
    for(int i=0;i<n;i++)scanf(" %c",&v[i]);
    for(int len=1;len<=min(6,n);len++)
        for(int l=0,r=l+len-1;r<n;l++,r++){
            string s;
            for(int i=l;i<=r;i++)s+=v[i];
            int x=stoi(s);
            a[x]++;
        }
    int x=0;
    while(a[x])x++;
    printf("%d",x);
    return 0;
}