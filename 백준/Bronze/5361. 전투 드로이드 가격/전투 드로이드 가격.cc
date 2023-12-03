#include <bits/stdc++.h>
using namespace std;

vector<double> v={350.34,230.90,190.55,125.30,180.90};

int main(){
    int n;scanf("%d",&n);
    while(n--){
        double ans=0;
        for(int i=0;i<5;i++){
            double x;scanf("%lf",&x);
            ans+=v[i]*x;
        }
        printf("$%.2lf\n",ans);
    }
}
