#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    vector<int> odd(n),even(n);
    for(int i=0;i<n;i++){
        if(i==0||i==n-1)odd[i]=*max_element(a.begin(),a.end());
        else odd[i]=min(a[i],max(a[i-1],a[i+1]));
        if(i==0) even[i]=-1e9;
        else even[i]=max(a[i],a[i-1]);
    }
    int oddmx=odd[n/2],evenmx=even[n/2];
    for(int i=0;i<n;i++){
        if((n-i)%2){
            oddmx=max(oddmx,max(odd[(n-i)/2],odd[(n+i)/2]));
            printf("%d ",oddmx);
        }
        else{
            evenmx=max(evenmx,max(even[(n-i)/2],even[(n+i)/2]));
            printf("%d ",evenmx);
        }
    }
    return 0;
}