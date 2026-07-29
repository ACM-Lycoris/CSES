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

    vector<vector<ll>> graph(n + 1); // 邻接表
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a); // 建边
    }

    vector<ll> vis(n + 1, 0);
    vector<ll> Isolates; // 独立连通块代表点

    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            // 广搜染色
            queue<ll> q;
            q.push(i);
            Isolates.emplace_back(i); // 干脆以第一个点为代表点
            vis[i] = true;
            while (!q.empty())
            {
                ll u = q.front();
                q.pop();
                for (ll v : graph[u])
                {
                    if (!vis[v])
                    {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
    }

    // 探索完成
    if (Isolates.size() == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << Isolates.size() - 1 << endl;

        // 把每一个独立连通块的代表点连在一起
        ll Cnt = Isolates.size();
        for (ll i = 0; i < Cnt - 1; i++)
        {
            cout << Isolates[i] << ' ' << Isolates[i + 1] << '\n';
        }
        cout << endl;
    }

    return 0;
}
