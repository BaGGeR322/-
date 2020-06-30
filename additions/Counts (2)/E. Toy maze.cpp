#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct Pos
{
    int i, j;
    Pos(const int i, const int j) : i(i), j(j) {}
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N + 2, vector<int>(M + 2, 1));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> arr[i][j];
    const int temp = -1;
    vector<vector<int>> len(N + 2, vector<int>(M + 2, -1));
    queue<Pos> q;
    len[1][1] = 0;
    q.push(Pos(1, 1));
    while (!q.empty())
    {
        Pos cur = q.front();
        q.pop();
        if (arr[cur.i][cur.j] == 2)
        {
            cout << len[cur.i][cur.j];
            return 0;
        }
        for (int i = -1; i < 2; i++)
            for (int j = -1; j < 2; j++)
                if (i * i + j * j == 1)
                {
                    int ni = cur.i, nj = cur.j;
                    while (arr[ni][nj] != 2 && arr[ni + i][nj + j] != 1)
                    {
                        ni += i;
                        nj += j;
                    }
                    if (len[ni][nj] == -1)
                    {
                        len[ni][nj] = len[cur.i][cur.j] + 1;
                        q.push(Pos(ni, nj));
                    }
                }
    }
    cout << 1;
}