#include <iostream>
using namespace std;

void bubbleSort(int data[], int mass1[], int lenD)
{
	int tmp = 0;
	for (int i = 0; i < lenD; i++)
		for (int j = (lenD - 1); j >= (i + 1); j--)
			if (data[j] < data[j - 1])
			{
				swap(data[j], data[j - 1]);
				swap(mass1[j], mass1[j - 1]);
			}
}

int main()
{
	int N;
	cin >> N;
	if (N <= 1)
	{
		cout << N;
		return 0;
	}
	bool* a = new bool[N];
	int* s = new int[N];
	int* f = new int[N];
	int tmp(1);
	for (int i = 0; i < N; cin >> s[i] >> f[i], a[i] = true, i++);
	bubbleSort(f, s, N);
	for (int i = 0; i < N; i++)
		if (a[i])
			for (int j = 0; j < N; j++)
			{
				if (a[j])
				{
					if (f[i] <= s[j])
					{
						tmp++;
						break;
					}
					else a[j] = false;
				}
			}
	cout << tmp;
}