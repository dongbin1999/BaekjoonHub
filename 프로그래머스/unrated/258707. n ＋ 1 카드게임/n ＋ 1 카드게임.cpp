#include<bits/stdc++.h>
using namespace std;

int solution(int coin, vector<int> cards) {
    int n=cards.size();
    vector<int> have(n+1),buy(n+1);
    int zero=0,one=0,two=0,ans=1;
    
    for(int i=0;i<n/3;i++){
        int x=cards[i];
        have[x]++;
        //가진 카드들로 한 턴을 넘길 수 있다.
        if(have[x]&&have[n+1-x])
            zero++,have[x]--,have[n+1-x]--;
    }
    for(int i=n/3;i<n;i+=2){
        int a=cards[i],b=cards[i+1];
        buy[a]++,buy[b]++;
        //만약 1코인 써서 카드 a만 구매하면 한 턴을 넘길 수 있다.
        if(buy[a]&&have[n+1-a])one++,buy[a]--,have[n+1-a]--;
        if(buy[b]&&have[n+1-b])one++,buy[b]--,have[n+1-b]--;
        //만약 2코인 써서 카드 a와 카드 n+1-a를 구매하면 한 턴을 넘길 수 있다.
        if(buy[a]&&buy[n+1-a])two++,buy[a]--,buy[n+1-a]--;
        if(buy[b]&&buy[n+1-b])two++,buy[b]--,buy[n+1-b]--;
        
        if(zero)zero--,ans++;
        else if(one&&coin)coin--,one--,ans++;
        else if(two&&coin>=2)coin-=2,two--,ans++;
        //코인이 없거나 카드 쌍이 없어 더 이상 라운드를 진행할 수 없다.
        else break;
    }
    return ans;
}