#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n + 1, vector<char>(m + 1));

    queue<pair<int, int>> q;                                         // 多源广搜用队列
    vector<vector<int>> MonsterDist(n + 1, vector<int>(m + 1, 1e8)); // 每一个点，最快有怪物到达的时候
    vector<vector<bool>> visM(n + 1, vector<bool>(m + 1, false));

    int Ax, Ay;

    for (int i = 1; i <= n; i++)
    {
        string line;
        cin >> line;
        for (int j = 1; j <= m; j++)
        {
            graph[i][j] = line[j - 1];
            if (graph[i][j] == 'M')
            {
                q.push({i, j});
                MonsterDist[i][j] = 0; // 已有怪物
                visM[i][j] = true;
                // 一起放入队列，做多源BFS
            }
            if (graph[i][j] == 'A')
            {
                Ax = i;
                Ay = j;
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && graph[nx][ny] != '#')
            {
                // MonsterDist[nx][ny]=min(MonsterDist[nx][ny],MonsterDist[x][y]+1);//距离更新
                if (!visM[nx][ny] || (visM[nx][ny] && MonsterDist[x][y] + 1 < MonsterDist[nx][ny]))
                {
                    q.push({nx, ny});
                    visM[nx][ny] = true;
                    MonsterDist[nx][ny] = min(MonsterDist[nx][ny], MonsterDist[x][y] + 1);
                }
            }
        }
    }

    // 怪物广搜完成，开始玩家寻路
    vector<vector<bool>> visA(n + 1, vector<bool>(m + 1, 0));
    vector<vector<pair<int, int>>> pre(n + 1, vector<pair<int, int>>(m + 1));
    vector<vector<int>> PlayerDist(n + 1, vector<int>(m + 1, 1e8));
    queue<pair<int, int>> qA;

    visA[Ax][Ay] = true;

    PlayerDist[Ax][Ay] = 0;

    vector<char> path;

    qA.push({Ax, Ay});

    bool ok = false;

    while (!qA.empty())
    {
        auto [x, y] = qA.front();
        qA.pop();
        if (x == 1 || x == n || y == 1 || y == m)
        {
            // Escape
            ok = true;

            while (x!= Ax || y != Ay)
            {
                auto [preX, preY] = pre[x][y];
                if (preY == y - 1)
                {
                    path.push_back('R');
                }
                else if (preY == y + 1)
                {
                    path.push_back('L');
                }
                else if (preX == x - 1)
                {
                    path.push_back('D');
                }
                else if (preX == x + 1)
                {
                    path.push_back('U');
                }
                x = preX;
                y = preY;
                if (x == Ax && y == Ay)
                {
                    break;
                }
            }

            reverse(all(path));
            cout << "YES\n";
            cout << path.size() << "\n";
            for (auto c : path)
            {
                cout << c;
            }
            cout << "\n";
            return 0;
        }

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && graph[nx][ny] != '#')
            {
                if (!visA[nx][ny] && (PlayerDist[x][y] + 1 < MonsterDist[nx][ny]))
                {
                    qA.push({nx, ny});
                    visA[nx][ny] = true;
                    pre[nx][ny] = {x, y};
                    PlayerDist[nx][ny] = min(PlayerDist[nx][ny], PlayerDist[x][y] + 1);
                }
            }
        }
    }

    if (!ok)
    {
        cout << "NO\n";
    }

    return 0;
}
