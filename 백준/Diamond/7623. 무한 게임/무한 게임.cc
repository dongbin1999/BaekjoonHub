#include <bits/stdc++.h>
using namespace std;
int GCD(int a,int b){return b?GCD(b,a%b):a;}
#define UNIQUE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());

int a[10001],b[10001];

int main() {
	int tc;scanf("%d",&tc);
	while(tc--)
	{
		int amx=0,amn=1e9,bmx=0,bmn=1e9;
		int n,m;scanf("%d %d",&n,&m);
		vector<int> v;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),amx=max(amx,a[i]),amn=min(amn,a[i]),v.push_back(a[i]);
		for(int i=1;i<=m;i++)scanf("%d",&b[i]),bmx=max(bmx,b[i]),bmn=min(bmn,b[i]),v.push_back(b[i]);
		if(amx<=bmn||bmx<=amn){printf("NO\n");continue;}
		int k=abs(v[1]-v[0]);
		for(int i=2;i<v.size();i++)k=GCD(k,abs(v[i]-v[i-1]));
		bool ok=k==1||(k==2&&v[0]%2)||(k==3&&v[0]%3!=0);
		printf(ok?"YES\n":"NO\n");
	}
	return 0;
}