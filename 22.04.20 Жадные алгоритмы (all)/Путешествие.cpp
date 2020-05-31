#include <iostream>
using namespace std;
void bubbleSort(int data[], int lenD)
{
	for (int i = 0; i < lenD; i++)
		for (int j = (lenD - 1); j >= (i + 1); j--)
			if (data[j] > data[j - 1])
				swap(data[j - 1], data[j]);
}

int main()
{
	int N, k, S, tmp;
	cin >> N >> k >> S;
	tmp = k;
	int* arr = new int[S];
	for (int i = 0; i < S; i++)
	{
		cin >> arr[i];
		if (arr[i] <= k) tmp += arr[i];
		else tmp += k;
	}

	if (N <= k)
	{
		cout << 0;
		return 0;
	}
	else if (tmp < N)
	{
		cout << -1;
		return 0;
	}
	else
	{
		tmp = k;
		bubbleSort(arr, S);
		for (int i = 0; i < S; i++)
		{
			if (tmp >= N)
			{
				cout << i;
				return 0;
			}
			if (arr[i] <= k) tmp += arr[i];
			else tmp += k;
		}
		cout << S;
	}
}