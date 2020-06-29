#include <iostream>
#include <vector>
#define INT_MAX 2147483647
using namespace std;

void cycle(bool& Case, vector<vector<int>> arr, vector<int> mass, int N, int tmp) 
{
	mass[tmp] = 1;
	for (int i = 0; i < N && !Case; i++) 
		if (arr[tmp][i] == 1) 
        {
			if (mass[i] == 0) cycle(Case, arr, mass, N, i);
			else if (mass[i] == 1) 
            {
				Case = true;
				return;
			}
		}
	mass[tmp] = 2;
}

int main()
{
    int N;
    cin >> N;
    bool k = false;
    vector<vector<int>> arr(N, vector<int>(N, 0));
    vector<int> mass(N);
    for (int i = 0; i < N; mass[i] = 0, i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    for (int i = 0; i < N; i++)
        if (!mass[i])
            {
                cycle(k, arr, mass, N, i);
                if (k)
                { 
                    cout << 1;
                    return 0;
                }
            }
    cout << 0;
}