#include <iostream>
#include <vector>
using namespace std;
void funct(vector<int> arr, int val, int N)
{
    if (val == N)
    {
        for (int i = 0; i < N; i++) cout << arr[i];
        cout << "\n";
    }
    else
        for (int i = val; i < N; i++)
        {
            swap(arr[val], arr[i]);
            funct(arr, val + 1, N);
        }
}

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        arr[i] = i + 1;
    funct(arr, 0, N);
}