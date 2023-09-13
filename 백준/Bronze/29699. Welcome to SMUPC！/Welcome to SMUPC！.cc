#include <bits/stdc++.h>
using namespace std;
string s="WelcomeToSMUPC";

int main(){
    int n;scanf("%d",&n);
    printf("%c",s[(n-1)%s.size()]);
    return 0;
}