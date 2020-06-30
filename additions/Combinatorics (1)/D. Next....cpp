#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = N - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            int min = i + 1;
            for (int j = i + 2; j < N; j++)
                if (arr[j] > arr[i] && arr[j] < arr[min]) min = j;
            swap(arr[i], arr[min]);
            reverse(&arr[i + 1], &arr[N]);
            break;
        }
        if (i == 0)
            reverse(&arr[i], &arr[N]);
    }
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    return 0;
}