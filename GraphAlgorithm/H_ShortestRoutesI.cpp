#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

const ll INF = 5e18;//INF要开大一点

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);

    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; //[dist,u]
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u])
        {
            // 已经更新过
            continue;
        }

        for (auto [v, nextD] : adj[u])
        {

            if (dist[u] + nextD < dist[v])
            {
                dist[v] = dist[u] + nextD;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << ' ';
    }
    cout << endl;

    return 0;
}
