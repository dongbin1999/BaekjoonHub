#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x=0,y;
        for(int j=0;j<n;j++)scanf("%d",&y),x|=y;
        printf("%d ",x);
    }
}