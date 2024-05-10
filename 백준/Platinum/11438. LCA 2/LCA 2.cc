#include <cstdio>
#include <vector>
using namespace std;

vector<int> tree[100001]; //tree[i] : i번 노드와 연결된 정점벡터.
int d[100001]; //i번 노드의 깊이(루트노드에서부터의 거리)
int sparse_table[100001][17]; //2^17 > 100000 // spa[i][j] : i번째노드의 2^j번째 부모.

void go(int node, int depth, int parent)
{
	sparse_table[node][0] = parent; //어떤 노드의 1( == 2^0)번째 부모. 1번(루트)노드의 부모도 1이라고 가정.
	d[node] = depth; //깊이 저장.

	//어떤 노드의 2^i번째 부모는, 그 노드의 2^(i-1)번째 부모의 2^(i-1)번째 부모임.
	for (int i = 1; i < 17; i++)
		sparse_table[node][i] = sparse_table[sparse_table[node][i - 1]][i - 1];

	int size = tree[node].size(); //모든 자식노드 방문할거임.
	for (int i = 0; i < size; i++)
		//(부모가 아닌)모든 자식 노드들을 dfs순회방문. dfs이므로 부모로가는 경로가 항상 존재함.
		if (parent != tree[node][i])
			go(tree[node][i], depth + 1, node); //자식과 부모간의 가중치가 1이고, 자식의 부모는 자기자신임.
}

int LCA(int a, int b)
{
	if (d[a] > d[b]) //일단, b의 깊이가 더 깊거나 같게 설정해줌.
		swap(a, b);
	for (int i = 16; i >= 0; i--) //우선 둘의 높이를 맞춰줄거임. 빠른 연산을 위해서, i=16부터--. 
		if (d[sparse_table[b][i]] >= d[a]) //b의 어떤(2^i번째) 부모인데도 a보다 깊거나 같다면,
			b = sparse_table[b][i]; //b를 올려줌.

	if (a == b) return a; //b를 다 올렸더니 a와 같아졌다면, 둘의 최소공통조상은 a.

	//두 노드가 합쳐지지 않을 때(조상이 서로 다를 때), 두 노드를 올려줌. 마찬가지 이유로 i=16부터.
	for (int i = 16; i >= 0; i--)
		if (sparse_table[a][i] != sparse_table[b][i])
		{
			a = sparse_table[a][i]; 
			b = sparse_table[b][i];
		}

	return sparse_table[a][0]; //a,b의 한단계 위가 두 노드의 최소공통조상이다.
}

int main()
{
	int N, M, a, b;
	scanf("%d", &N);
	for (int i = 1; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	go(1, 0, 1);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a, b));
	}
	return 0;
}