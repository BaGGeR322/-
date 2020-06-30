#include <iostream>
#include <vector>
#define intmax 10000000
using namespace std;
int main()
{
    int k(0), N;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] < 0)
                arr[i][j] = intmax;
        }
    for (k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
    k = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (arr[i][j] < intmax && arr[i][j] > k)
                k = arr[i][j];
    cout << k;
}