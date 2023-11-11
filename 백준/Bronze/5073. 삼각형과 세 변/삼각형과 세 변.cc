#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        vector<int> a(3);
        for(auto &x:a)scanf("%d",&x);
        sort(a.begin(),a.end());
        if(!a[0])break;
        if(a[0]==a[2])printf("Equilateral\n");
        else if(a[0]+a[1]<=a[2])printf("Invalid\n");
        else if(a[0]==a[1]||a[1]==a[2])printf("Isosceles\n");
        else printf("Scalene\n");
    }
    return 0;
}