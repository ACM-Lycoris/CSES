#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<char>> graph(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        string line;
        cin >> line;
        for (int j = 1; j <= m; j++)
        {
            graph[i][j] = line[j - 1];
        }
    }

    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
    vector<vector<pair<ll, ll>>> pre(n + 1, vector<pair<ll, ll>>(m + 1)); // 前驱点

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<char> Path;
    bool ok = false;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (graph[i][j] == 'A')
            {
                // 开始

                queue<pair<ll, ll>> q;
                q.push({i, j});

                vis[i][j] = true;

                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    if (graph[x][y] == 'B')
                    {
                        ok = true;
                        while (true)
                        {
                            auto [preX, preY] = pre[x][y]; // 获取上一个节点
                            if (preX == x - 1)
                            {
                                // 上一个点往下来的
                                Path.emplace_back('D');
                            }
                            else if (preX == x + 1)
                            {
                                Path.emplace_back('U');
                            }
                            else if (preY == y + 1)
                            {
                                Path.emplace_back('L');
                            }
                            else if (preY == y - 1)
                            {
                                Path.emplace_back('R');
                            }

                            if (graph[preX][preY] == 'A')
                            {
                                break;
                            }
                            else
                            {
                                x = preX;
                                y = preY;
                            }
                        }
                        goto end_loop;
                    }

                    for (ll k = 0; k < 4; k++)
                    {
                        ll nx = x + dx[k];
                        ll ny = y + dy[k];

                        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && (graph[nx][ny] == '.' || graph[nx][ny] == 'B'))
                        {
                            q.push({nx, ny});
                            vis[nx][ny] = true;
                            pre[nx][ny] = {x, y}; // 从x,y -> nx,ny
                        }
                    }
                }
            }
        }
    }

end_loop:
{
    if (ok)
    {
        cout << "YES\n"
             << Path.size() << endl;
        reverse(Path.begin(), Path.end());
        for (char c : Path)
        {
            cout << c;
        }
        cout << endl;
    }
    else
    {
        cout << "NO\n";
    }
};

    return 0;
}