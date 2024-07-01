#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

map<int,string> ma;

int main(){
    ma[0]="baby";
    ma[1]="sukhwan";
    ma[2]="2";
    ma[3]="1";
    ma[4]="very";
    ma[5]="cute";
    ma[6]="2";
    ma[7]="1";
    ma[8]="in";
    ma[9]="bed";
    ma[10]="2";
    ma[11]="1";
    ma[12]="baby";
    ma[13]="sukhwan";
    int n;scanf("%d",&n);n--;
    int add=n/14;
    if(ma[n%14].size()>1)cout<<ma[n%14];
    else{
        int x=stoi(ma[n%14])+add;
        if(x>=5)printf("tu+ru*%d",x);
        else{
            printf("tu");
            while(x--)printf("ru");
        }
    }
}