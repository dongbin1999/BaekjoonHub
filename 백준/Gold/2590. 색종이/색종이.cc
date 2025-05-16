#include<bits/stdc++.h>
using namespace std;
int a[7],b[7];
int main(){
    for(int i=1;i<=6;i++)scanf("%d",&a[i]);
    int ans=a[6]+a[5]+a[4]+(a[3]+3)/4;
    b[1]+=a[5]*11;
    b[2]+=a[4]*5;
    if(a[3]%4==1)b[2]+=5,b[1]+=7;
    if(a[3]%4==2)b[2]+=3,b[1]+=6;
    if(a[3]%4==3)b[2]+=1,b[1]+=5;
    int x=min(a[2],b[2]);

    a[2]-=x,b[2]-=x;
    ans+=(a[2]+8)/9;
    if(a[2]%9)b[2]+=9-a[2]%9;

    b[1]+=b[2]*4;
    x=min(a[1],b[1]);

    a[1]-=x,b[1]-=x;
    ans+=(a[1]+35)/36;

    printf("%d",ans);
}