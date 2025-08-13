#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a(3);
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    sort(a.begin(),a.end());
    printf("%d",a[2]*2-a[1]-a[0]);
}