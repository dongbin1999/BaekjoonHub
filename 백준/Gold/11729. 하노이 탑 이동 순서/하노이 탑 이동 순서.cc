#include <cstdio>
#include <vector>
using namespace std;

struct go
{
    int from, to;
};

int K;
vector<go> v;

void hanoi(int n, int from, int temp, int to)
{
    if (n == 1)
    {
        v.push_back({ from, to });
        K++;
        return;
    }
    hanoi(n - 1, from, to, temp);
    v.push_back({ from, to });
    K++;
    hanoi(n - 1, temp, from, to);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    hanoi(N, 1, 2, 3);
    printf("%d\n", K);
    int size = v.size();
    for (int i = 0; i < size; i++)
        printf("%d %d\n", v[i].from, v[i].to);
    return 0;
}