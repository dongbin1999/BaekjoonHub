#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    int o1=1,o2=1;
    while(n--){
        o1+=a,o2+=b;
        if(o1<o2)swap(o1,o2);
        else if(o1==o2)o2--;
    }
    printf("%d %d",o1,o2);
}
