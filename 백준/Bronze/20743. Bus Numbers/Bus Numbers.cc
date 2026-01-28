#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;cin>>x;
    for(int i=x;i>=1;i--){
        int cnt=0;
        for(int a=1;a<=100;a++)for(int b=a;b<=100;b++)
            if(a*a*a+b*b*b==i)cnt++;
        if(cnt>1)return !printf("%d",i);
    }
    printf("none");
}