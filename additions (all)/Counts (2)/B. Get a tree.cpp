#include<iostream>
#include<vector>
using namespace std;
int mass[101], arr[101][101];

void funct(int tmp, int N)
{
    mass[tmp] = 1;
    for(int i = 1; i < N+1; i++)
    if (arr[tmp][i] && !mass[i])
    {
      cout << tmp << " " << i << endl;
      funct(i, N);
    }
}

int main()
{
    int N, M, a, b;
    cin >> N >> M;
    for (int i=0;i<M;i++)
    {
        cin >> a >> b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    funct(1, N);
}