#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<ll> Tree(2 * n , 0);

    auto Build = [&]() -> void
    {
        for (ll i = 1; i <= n; i++)
        {
            Tree[i + n - 1] = a[i];
        }
        for (int i = n - 1; i >= 1; i--)
        {
            Tree[i] = min(Tree[i << 1], Tree[i << 1 | 1]);
        }
    };

    auto Update = [&](ll k, ll val) -> void
    {
        Tree[k + n - 1] = val;
        ll id = k + n - 1;
        while (id > 1)
        {
            Tree[id >> 1] = min(Tree[id], Tree[id ^ 1]);
            id >>= 1;
        }
    };

    auto Query = [&](ll a, ll b) -> ll
    {
        ll l = a + n -1, r = b + n -1;
        ll res = LLONG_MAX;
        while (l <= r)
        {
            if (l & 1)
            {
                res = min(Tree[l++], res);
            }
            if (!(r & 1))
            {
                res = min(Tree[r--], res);
            }
            l >>= 1;
            r >>= 1;
        }

        return res;
    };

    Build();

    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll k, u;
            cin >> k >> u;
            Update(k, u);
        }
        else
        {
            ll a, b;
            cin >> a >> b;

            cout << Query(a, b) << '\n';
        }
    }

    return 0;
}
