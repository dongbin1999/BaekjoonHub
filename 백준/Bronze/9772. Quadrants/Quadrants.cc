#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        double x,y;
        cin>>x>>y;
        if(x==0.0||y==0.0){
            printf("AXIS\n");
            if(x==0.0&&y==0.0)break;
        }
        else{
            int z=0;
            if(y<0){z=4;if(x<0)z--;}
            else if(x<0)z+=2;else z++;
            printf("Q%d\n",z);
        }
    }
}