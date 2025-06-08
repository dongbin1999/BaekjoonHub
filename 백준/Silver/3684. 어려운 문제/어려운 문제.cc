#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    for(int a=0;a<=10000;a++)for(int b=0;b<=10000;b++){
        int i=0,x=v[i],ok=1;
        while(i+1<n){
            x=(x*a+b)%10001;x=(x*a+b)%10001;
            if(x!=v[i+1]){ok=0;break;}
            else i++;
        }
        if(ok){
            for(int j=0;j<n;j++)
                printf("%d\n",(v[j]*a+b)%10001);
            return 0;
        }
    }
    return 0;
}