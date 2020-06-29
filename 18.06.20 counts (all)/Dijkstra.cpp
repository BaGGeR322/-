#include <iostream>
#include <vector>
#define INT_MAX 2147483647
using namespace std;

int main()
{
	int N, S, F;
	cin >> N >> S >> F;
	S--; F--;
	int val = INT_MAX;
	vector<vector<pair<int, int>>> arr(N);
	vector<int> mass1(N, val), mass2(N);
	vector<bool> prov(N);

	mass1[S] = 0;
	for (int i = 0, tmp; i < N; i++) 
		for (int j = 0; j < N; j++) 
        {
			cin >> tmp;
			if (i != j && tmp != -1) 
                arr[i].push_back(make_pair(j, tmp));
		}

	for (int i = 0; i < N; i++) 
    {
		int k = -1;
		for (int j = 0; j < N; j++)
			if (!prov[j] && (k == -1 || mass1[j] < mass1[k])) k = j;

		if (mass1[k] == val) break;
		prov[k] = true;
		for (int j = 0; j < arr[k].size(); j++) 
        {
			int res = arr[k][j].first;
			int len = arr[k][j].second;
			if (mass1[k] + len < mass1[res]) 
            {
				mass1[res] = mass1[k] + len;
				mass2[res] = k;
			}
		}
	}
	if (mass1[F] == val) cout << -1;
	else cout << mass1[F];
}