#include <bits/stdc++.h>
using namespace std;
int pa[100000],co[100000],se[100001];

int main(){
    int n,k,r,a,b,c;scanf("%d%d",&n,&k);
    while(k--){
        scanf("%d%d%d",&r,&a,&b);
        if(r==1){
            scanf("%d",&c);
            vector<int> x,y;
            int it=1000,lca;
            while(it--){
                if(se[a]){lca=a;break;}
                se[a]++,x.push_back(a),a=pa[a];
            }
            it=1000;
            while(it--){
                if(se[b]){lca=b;break;}
                se[b]++,y.push_back(b),b=pa[b];
            }
            for(auto i:x)if(i!=lca)co[i]=c;else break;
            for(auto i:y)if(i!=lca)co[i]=c;else break;
            for(auto i:x)se[i]=0;for(auto i:y)se[i]=0;
        }
        else if(r==2){
            pa[a]=b;
        }
        else{
            unordered_set<int> ans;
            vector<int> x,y;
            int it=1000,lca;
            while(it--){
                if(se[a]){lca=a;break;}
                se[a]++,x.push_back(a),a=pa[a];
            }
            it=1000;
            while(it--){
                if(se[b]){lca=b;break;}
                se[b]++,y.push_back(b),b=pa[b];
            }
            for(auto i:x)if(i!=lca)ans.insert(co[i]);else break;
            for(auto i:y)if(i!=lca)ans.insert(co[i]);else break;
            for(auto i:x)se[i]=0;for(auto i:y)se[i]=0;
            printf("%d\n",ans.size());
        }
    }
    return 0;
}