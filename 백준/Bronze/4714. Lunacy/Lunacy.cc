#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        double d;scanf("%lf",&d);
        if(d<0)break;
        printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n",d,d*0.167);
    }
}