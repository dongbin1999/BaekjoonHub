#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;n*=2;
    string s;cin>>s;
    for(int i=1;i<n;i++)if(abs(s[i]-s[i-1])!=1)return !printf("No");
    printf("Yes");
}