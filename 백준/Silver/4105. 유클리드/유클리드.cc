#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> pdd;

double dist(pdd a,pdd b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
double area(pdd a,pdd b,pdd c){
    double A=dist(a,b),B=dist(b,c),C=dist(c,a),s=(A+B+C)/2;
    return sqrt(s*(s-A)*(s-B)*(s-C));
}

int main(){
    pdd a,b,c,d,e,f;
    while(1){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&a.first,&a.second,&b.first,&b.second,
              &c.first,&c.second,&d.first,&d.second,&e.first,&e.second,&f.first,&f.second);
        if(a==b)break;
        double h=area(d,e,f)/dist(a,b);
        pdd ac={c.first-a.first,c.second-a.second},ab={b.first-a.first,b.second-a.second};
        double angle=acos((ac.first*ab.first+ac.second*ab.second)/dist(a,c)/dist(a,b));
        double len=h/sin(angle);
        pdd H={a.first+ac.first*len/dist(a,c),a.second+ac.second*len/dist(a,c)},
        G={H.first+b.first-a.first,H.second+b.second-a.second};
        printf("%.3lf %.3lf %.3lf %.3lf\n",G.first,G.second,H.first,H.second);
    }
    return 0;
}