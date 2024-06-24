#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1),pi2=pi*2;
void solve(){
    int n;scanf("%d",&n);
    vector<double> v(n),r;double b;
    for(auto &a:v)scanf("%lf%lf",&a,&b),r.push_back(pi2-a);
    for(int slice=n;slice>=1;slice--){
        if(n%slice)continue;
        for(int i=0;i<n;i++){
            vector<int> cnt(slice);
            for(auto a:v){
                int idx=(a-v[i]<0?a-v[i]+pi2:a-v[i])/(pi2/slice);
                cnt[idx]++;
            }
            if(*max_element(cnt.begin(),cnt.end())==*min_element(cnt.begin(),cnt.end())){
                printf("%d",slice);return;
            }
            vector<int> cnt2(slice);
            for(auto a:v){
                int idx=(a-v[i]+0.000000001<0?a-v[i]+0.000000001+pi2:a-v[i]+0.000000001)/(pi2/slice);
                cnt2[idx]++;
            }
            if(*max_element(cnt2.begin(),cnt2.end())==*min_element(cnt2.begin(),cnt2.end())){
                printf("%d",slice);return;
            }
            vector<int> rcnt(slice);
            for(auto a:r){
                int idx=(a-r[i]<0?a-r[i]+pi2:a-r[i])/(pi2/slice);
                rcnt[idx]++;
            }
            if(*max_element(rcnt.begin(),rcnt.end())==*min_element(rcnt.begin(),rcnt.end())){
                printf("%d",slice);return;
            }
            vector<int> rcnt2(slice);
            for(auto a:r){
                int idx=(a-r[i]+0.000000001<0?a-r[i]+0.000000001+pi2:a-r[i]+0.000000001)/(pi2/slice);
                rcnt2[idx]++;
            }
            if(*max_element(rcnt2.begin(),rcnt2.end())==*min_element(rcnt2.begin(),rcnt2.end())){
                printf("%d",slice);return;
            }
        }
    }
}

int main(){
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Data Set %d: ",i);
        solve();
        printf(" slices\n\n");
    }
}