#include <bits/stdc++.h>
using namespace std;
int GCD(int a,int b){return b?GCD(b,a%b):a;}
int main(){
    int n;scanf("%d",&n);
    while(n--){
        int x,y,a;scanf("%d%d%d",&x,&y,&a);
        vector<int> v(a);
        for(int i=0;i<a;i++){
            scanf("%d",&v[i]);
            if(i)v[0]=GCD(v[0],v[i]);
        }
        printf(x%v[0]==0&&y%v[0]==0?"Ta-da\n":"Gave up\n");
    }
    return 0;
}