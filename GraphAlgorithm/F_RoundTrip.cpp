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

    vector<vector<ll>> graph(n + 1);
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    vector<ll> vis(n + 1, 0);
    vector<ll> pre(n + 1, -1);

    ll cycleStart = -1, cycleEnd = -1;

    auto DFS = [&](auto &&self, ll u, ll father) -> bool
    {
        vis[u] = true;
        for (ll v : graph[u])
        {
            if (v == father)
            {
                continue;
            }
            if (!vis[v])
            {
                // Visit this node for the first time.
                pre[v] = u;

                if (self(self, v, u))
                {
                    return true; // Stop after a cycle is found.
                }
            }
            else
            {
                // A cycle is found.
                pre[v] = u; // Close the cycle with this edge.
                cycleEnd = u;
                cycleStart = v;
                return true;
            }
        }
        // No cycle was found from this node.
        return false;
    };

    vector<ll> path;

    bool have = false;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bool ok = DFS(DFS, i, -1);
            if (!ok)
            {
                continue;
            }
            else
            {
                // Restore the cycle.
                have = true;

                ll v = cycleEnd;
                path.emplace_back(v);
                for (ll u = pre[v]; u != v; u = pre[u])
                {
                    path.emplace_back(u);
                }
                path.emplace_back(v);

                cout << path.size() << endl;
                for (ll num : path)
                {
                    cout << num << ' ';
                }
                cout << endl;
                return 0; // Stop after printing the cycle.
            }
        }
    }
    if (!have)
    {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
