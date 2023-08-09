#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pair<ll,ll>> plll;

pll a[80001];
priority_queue<plll> pq;
priority_queue<ll> pq2;
ll s[40001],l[40001];

int main() {
	int n,k;scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i].y);//y가 내점수,x가 봇점수.
	for(int i=1;i<=n;i++) scanf("%lld",&a[i].x);
	sort(a+1,a+1+n,greater<pll>());
	ll bot=0,me=0;
	for(int i=1;i<=k;i++)pq.push({a[i].x+a[i].y,a[i]}),bot+=a[i].x;
	l[0]=-bot;
	for(int i=k+1;i<=k+k;i++)//봇 점수가 큰거 k+i개중에서 i개 고를거임.
	{
		pq.push({a[i].x+a[i].y,a[i]}),bot+=a[i].x;
		plll p=pq.top();pq.pop();
		bot-=p.y.x,me+=p.y.y;
		l[i-k]=me-bot;
	}
	
	me=0;
	for(int i=n;i>k+k;i--) pq2.push(a[i].y);
	for(int i=k+k;i>k;i--)
	{
		pq2.push(a[i].y);
		me+=pq2.top();pq2.pop();
		s[k+k+1-i]=me;
	}
	
	ll ans=-2e18;
	for(int i=0;i<=k;i++)ans=max(ans,s[i]+l[k-i]);
	printf("%lld",ans);
	
    return 0;
}