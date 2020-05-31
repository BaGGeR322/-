#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void BucketSort(vector<int>& data, int N)
{
	vector<vector<int>> bucket(N / 2);
	cin >> data[0];
	int min = data[0], max = data[0];
	for (int i = 1; i < N; i++)
	{
		cin >> data[i];
		if (max < data[i]) max = data[i];
		if (min > data[i]) min = data[i];
	}
	double x = (double(max - min)) / (N / 2);
	for (int i = 0, j; i < N; i++)
	{
		j = (int)((data[i] - min) / x);
		bucket.at(j >= (N / 2) ? (N / 2) - 1 : j).push_back(data[i]);
	}
	for (int i = 0; i < (N/2); i++) 
		sort(bucket[i].begin(), bucket[i].end());
	for (int i = 0, j = 0; i < N/2; i++)
		for (int k = 0; k < bucket[i].size(); k++) data[j++] = bucket[i][k];

	for (int i = 0; i < N; cout << data[i] << " ", i++);
}

int main()
{
	int N;
	cin >> N;
	vector<int> arr(N);
	BucketSort(arr, N);
}