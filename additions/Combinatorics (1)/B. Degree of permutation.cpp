#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

struct Tem
{
    bool operator()(int val)
    {
        return val != 0;
    }
};

bool funct(vector<int> &arr, int &c_size)
{
    vector<int>::iterator it = find_if(arr.begin(), arr.end(), Tem());
    bool bool_res = it != arr.end();
    if (bool_res)
    {
        c_size = 1;
        int first = it - arr.begin() + 1;
        int last = first;

        while (true)
        {
            vector<int>::iterator it = arr.begin() + last - 1;
            last = *it;
            *it = 0;
            if (last == first) break;
            c_size++;
        }
    }
    return bool_res;
}

int GCD(int left, int right)
{
    if (left > right) swap(left, right);
    if (left == 0) return right;
    return GCD(left, right % left);
}

int main()
{
    int N = 0, val, res(1), c_size(0);
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    while (funct(arr, c_size)) res = res * c_size / GCD(res, c_size);

    cout << res;
}