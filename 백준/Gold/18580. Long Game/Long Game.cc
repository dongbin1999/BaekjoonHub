#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    for(int i=1;i<n;i++)
        if(v[i]<v[i-1]) return !printf(n%2?"Alice":"Bob");
    printf("Bob");
}