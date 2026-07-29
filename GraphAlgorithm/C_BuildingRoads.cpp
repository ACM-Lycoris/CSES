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

    vector<vector<ll>> graph(n + 1); // Adjacency list.
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a); // Add an edge.
    }

    vector<ll> vis(n + 1, 0);
    vector<ll> Isolates; // One node from each connected component.

    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            // Find this connected component with BFS.
            queue<ll> q;
            q.push(i);
            Isolates.emplace_back(i); // Use the first node as its representative.
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

    // All connected components are known.
    if (Isolates.size() == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << Isolates.size() - 1 << endl;

        // Connect the representative nodes.
        ll Cnt = Isolates.size();
        for (ll i = 0; i < Cnt - 1; i++)
        {
            cout << Isolates[i] << ' ' << Isolates[i + 1] << '\n';
        }
        cout << endl;
    }

    return 0;
}
