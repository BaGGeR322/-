#include <iostream>
using namespace std;
void heapify(int* mass, int i, int& size)
{
	int l = i * 2 + 1, r = i * 2 + 2, cur = i;
	if (l<size && mass[l]>mass[cur])
		cur = l;
	if (r<size && mass[r]>mass[cur])
		cur = r;
	if (i != cur)
	{
		swap(mass[i], mass[cur]);
		heapify(mass, cur, size);
	}
}
void build_heap(int* mass, int& size)
{
	for (int i = (size / 2) - 1; i > -1; i--)
		heapify(mass, i, size);
}
void add_val(int* mass, int val, int& size)
{
	mass[size] = val;
	size++;
	int cur = size - 1;
	int p = (cur / 2) - 1;
	while (p > 0 && mass[p] < mass[cur])
	{
		swap(mass[p], mass[cur]);
		cur = p;
		p = (cur / 2) - 1;
	}
}
void del_BigVal(int* mass, int& size)
{
	int tmp = mass[0];
	mass[0] = mass[size - 1];
	size--;
	heapify(mass, 0, size);
}
void sort(int* mass, int& size)
{
	/*
	while (size > 0)
	{
		swap(mass[size - 1], mass[0]);
		size--;
		heapify(mass, 0, size);
	}
	*/
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(mass, size, i);

	for (int i = size - 1; i >= 0; i--)
	{
		swap(mass[0], mass[i]);
		heapify(mass, 0, i);
	}
}

int main()
{
	int a, size = 0, N;
	cin >> N;
	int* bin_tree = new int[N];
	for (int i = 0; i < N; cin >> a, add_val(bin_tree, a, size), i++);
	build_heap(bin_tree, size);
	sort(bin_tree, size);
	for (int i = 0; i < size; i++)
		cout << bin_tree[i] << " ";
}