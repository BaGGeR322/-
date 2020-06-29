#include <iostream>
#include <vector>
#define INT_MAX 2147483647
using namespace std;

int main()
{
    int N, M;
    cin >> N;
    vector<vector<pair<int, int>>> arr(N);
    vector<int> mass1(N, INT_MAX), mass2(N), cost(N);
    vector<bool> prov(N);

    for (int i = 0; i < N; i++)
        cin >> cost[i];
    mass1[0] = 0;
    cin >> M;
    int k1, k2;
    for (int i = 0; i < M; i++)
    {
        cin >> k1 >> k2;
        k1--;
        k2--;
        arr[k1].push_back(make_pair(k2, cost[k1]));
        arr[k2].push_back(make_pair(k1, cost[k2]));
    }

    for (int i = 0; i < N; i++)
    {
        int tmp = -1;
        for (int j = 0; j < N; j++)
            if (!prov[j] && (tmp == -1 || mass1[j] < mass1[tmp]))
                tmp = j;
        if (mass1[tmp] == INT_MAX)
            break;
        prov[tmp] = true;
        for (int j = 0; j < arr[tmp].size(); j++)
        {
            int tEmp = arr[tmp][j].first;
            int len = arr[tmp][j].second;
            if (mass1[tmp] + len < mass1[tEmp])
            {
                mass1[tEmp] = mass1[tmp] + len;
                mass2[tEmp] = tmp;
            }
        }
    }
    if (mass1[N - 1] == INT_MAX) cout << -1;
    else cout << mass1[N - 1];
}