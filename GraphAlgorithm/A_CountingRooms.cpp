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

    ll ansCnt = 0;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (graph[i][j] == '.' && !vis[i][j])
            {
                // Start BFS for a new room.
                ansCnt++;
                
                queue<pair<ll, ll>> q;
                q.push({i, j});
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        ll nx = x + dx[k], ny = y + dy[k];
                        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m 
                            && !vis[nx][ny] && graph[nx][ny]=='.')
                        {
                            q.push({nx,ny});
                            vis[nx][ny]=true;
                        }
                    }
                }
            }
        }
    }

    cout<<ansCnt<<endl;

    return 0;
}
