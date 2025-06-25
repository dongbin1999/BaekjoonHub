#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    getchar();
    while(t--){
        string s;getline(cin,s);
        s+=' ';
        int x=0,sum=0;
        for(auto i:s)
            if(i==' ')sum+=x,x=0;
            else x=x*10+i-'0';
        printf("%d\n",sum);
    }
}