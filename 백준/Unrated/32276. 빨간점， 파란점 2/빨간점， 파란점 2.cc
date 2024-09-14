#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

char s[500005];

void solve() {
	int n; scanf("%d", &n);
	scanf("%s", s);
	int x[2][2];
	x[0][0] = x[0][1] = x[1][0] = x[1][1] = 0;
	for (int i = 1; i < n; i++)
		x[s[i - 1] == 'R'][s[i] == 'R']++;
	x[s[n - 1] == 'R'][s[0] == 'R']++;
	int bb = x[0][0], br = x[0][1], rb = x[1][0], rr = x[1][1];
	if (!bb && !rr)printf("%d\n", 1 + (br > 2));
	else if (!rb || !br)printf("0\n");
	else {
		//몇번째?
		vector<int> RR;
		deque<char> dq;
		for (int i = 0; i < n; i++)dq.push_back(s[i]);
		while (dq.front() == dq.back())dq.push_back(dq.front()), dq.pop_front();
		bool b = dq.front() == 'B'; int flag = 0;
		for (int i = 1; i < n; i++) {
			//printf("[%c %d %d] ", dq[i],(dq[i]=='B')!=b,(int)flag);
			if ((dq[i] == 'B') != b) {
				RR.push_back(flag);
				b ^= 1, flag = 0;
			}
			else flag = 1;
		}
		RR.push_back(flag);
//		for (int i = 0; i < RR.size(); i++)printf("%d ", RR[i]);
	//	printf("\n");
		vector<int> idx;
		for (int i = 0; i < RR.size(); i++)
			if (RR[i])idx.push_back(i);
		int mx = 0;
		for (int i = 1; i < idx.size(); i++)mx = max(mx, idx[i] - idx[i - 1]);
		mx = max(mx, idx[0] + (int)RR.size() - idx.back());
		if (mx * 2 <= (int)RR.size())printf("0\n");
		else printf("1\n");
		//printf("[%d %d]\n", mx,(int)RR.size());
	}
	fflush(stdout);
}

int main() {
	int tc; scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		printf("Case #%d\n", i);
		solve();
	}
}