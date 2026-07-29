#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    vector<int> color(n + 1, 0);
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {

        if (color[i] != 0)
        {
            continue;
        }

        queue<int> q;
        q.push(i);
        color[i] = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : graph[u])
            {
                if (color[v] == 0)
                {
                    color[v] = 3 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u])
                {
                    // Two linked nodes have the same color.
                    ok = false;
                    break;
                }
            }
        }
        if (!ok)
        {
            break;
        }
    }

    if (!ok)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << color[i] << " ";
    }
    cout << "\n";

    return 0;
}
