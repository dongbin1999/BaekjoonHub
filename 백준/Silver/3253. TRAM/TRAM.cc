#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, st, en;
    cin >> n >> st >> en;

    vector<vector<int>> conn(n + 1, vector<int>());
    int cnt, index;
    for (int i = 1; i <= n; i++) {
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> index;
            conn[i].push_back(index);
        }
    }
    vector<int> dist_from_st(n + 1, INT32_MAX);
    dist_from_st[st] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, st });
    while (!pq.empty()) {
        int cdist = -pq.top().first;
        int cidx = pq.top().second;
        pq.pop();
        
        if (conn[cidx].size() > 0) {
            int nidx = conn[cidx][0];
            if (dist_from_st[cidx] < dist_from_st[nidx]) {
                dist_from_st[nidx] = dist_from_st[cidx];
                pq.push({ -dist_from_st[nidx], nidx });
            }
        }
        for (int i = 1; i < conn[cidx].size(); i++) {
            int nidx = conn[cidx][i];
            if (dist_from_st[cidx] + 1 < dist_from_st[nidx]) {
                dist_from_st[nidx] = dist_from_st[cidx] + 1;
                pq.push({ -dist_from_st[nidx], nidx });
            }
        }
    }
    dist_from_st[st] = 0;
    cout << (dist_from_st[en] == INT32_MAX ? -1 : dist_from_st[en]);
}