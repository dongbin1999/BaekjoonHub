#include <bits/stdc++.h>
using namespace std;

int main(){
    double a,b;scanf("%lf %lf",&a,&b);
    a/=b*b;
    if(a>25.0)printf("Overweight");
    else if(a>=18.5)printf("Normal weight");
    else printf("Underweight");
    return 0;
}