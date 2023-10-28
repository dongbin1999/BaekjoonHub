#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    while(n--){
        string s;int a,b;cin>>s>>a>>b;
        for(int i=0;i<s.size();i++)
            if(i<a||b<=i)printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}