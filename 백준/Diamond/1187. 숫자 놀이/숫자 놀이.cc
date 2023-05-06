#include <bits/stdc++.h>
using namespace std;
typedef pair<int,vector<int>> piv;

int main() {
	int n;scanf("%d",&n);
	vector<piv> p;
	for(int i=1;i<=2*n-1;i++)
	{
		int k;scanf("%d",&k);
		vector<int> v;v.push_back(k);
		p.push_back({k,v});
	}
	while(p.size()>1)
	{
		vector<piv> t;
		vector<piv> v[2];
		for(auto i:p) v[i.first%2].push_back(i);
		for(int i=1;i<v[0].size();i+=2)
		{
			piv temp;temp.first=(v[0][i].first+v[0][i-1].first)/2;
			for(auto j:v[0][i].second) temp.second.push_back(j);
			for(auto j:v[0][i-1].second) temp.second.push_back(j);
			t.push_back(temp);
		}
		for(int i=1;i<v[1].size();i+=2)
		{
			piv temp;temp.first=(v[1][i].first+v[1][i-1].first)/2;
			for(auto j:v[1][i].second) temp.second.push_back(j);
			for(auto j:v[1][i-1].second) temp.second.push_back(j);
			t.push_back(temp);
		}
		p=t;
	}
	for(auto i:p[0].second)printf("%d ",i);
	return 0;
}