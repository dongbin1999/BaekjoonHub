#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int A[1000001];
int index[1000001];

/*void print_ma(map<int, int>ma)
{
    for (auto it = ma.begin(); it != ma.end(); it++)
        printf("(%d %d [%d]) ", it->first, it->second, index[it->second]);
    printf("\n");
}*/

int main(void)
{
    int N, temp;
    scanf("%d", &N);
    map<int, int> ma;
    map<int, int>::iterator it;
    scanf("%d", &A[1]);
    ma.insert({ A[1], 1 });
    index[1] = 0;

    //print_ma(ma);

    for (int i = 2; i <= N; i++)
    {
        scanf("%d", &A[i]);
        it = ma.lower_bound(A[i]);
        if (it == ma.begin())
            index[i] = 0;
        else
        {
            it--;
            index[i] = it->second;
            it++;
        }
        if (it != ma.end())
            ma.erase(it);
        ma.insert({ A[i],i });
        //print_ma(ma);
    }

    printf("%d\n", ma.size());
    vector<int> v;
    it = ma.end(); it--;
    temp = it->second;
    while (temp != 0)
    {
        v.push_back(A[temp]);
        temp = index[temp];
    }
    if (ma.size() != v.size())
        v.push_back(ma.begin()->first);

    int size = v.size();
    for (int i = size - 1; i >= 0; i--)
        printf("%d ", v[i]);
    return 0;
}
