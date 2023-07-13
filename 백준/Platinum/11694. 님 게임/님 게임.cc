#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,XOR=0;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        XOR^=v[i];
    }
    if(*max_element(v.begin(),v.end())==1)
        printf(n%2?"cubelover":"koosaga");
    else printf(XOR?"koosaga":"cubelover");
    return 0;
}