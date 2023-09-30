#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int ti=0; ti<tc; ti++){
        bool first_win=false;
        int n,m,k;
        cin>>n>>m>>k;
        if(m<=2*k-1) first_win=true;
        else if(n%2==1 && m%2==1) first_win=true;
        cout<<(first_win? "Yuto":"Platina");
        cout<<"\n";
    }
}