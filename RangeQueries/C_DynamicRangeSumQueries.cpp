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

    vector<ll> tree(4 * n + 5);

    auto build = [&](auto &&self, int p, int l, int r) -> void
    {
        if (l == r)
        {
            tree[p] = a[l];
            return;
        }

        int mid = l + (r - l) / 2;

        self(self, p * 2, l, mid);
        self(self, p * 2 + 1, mid + 1, r);

        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    };

    auto update = [&](auto &&self, int p, int pos, ll val, int left, int right) -> void
    {
        // p对应树上坐标，pos,left,right对应原数组坐标
        if (left == right)
        {
            tree[p] = val;
            return;
        }

        int mid = left + (right - left) / 2;

        if (mid >= pos)
        {
            self(self, p * 2, pos, val, left, mid);
        }
        else
        {
            self(self, p * 2 + 1, pos, val, mid + 1, right);
        }

        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    };

    auto query = [&](auto &&self, int p, int l, int r, int ql, int qr) -> ll
    {
        if (l >= ql && r <= qr)
        {
            return tree[p];
        }

        if (r < ql || l > qr)
        {
            return 0;
        }

        int mid = l + (r - l) / 2;
        ll leftSum = self(self, p * 2, l, mid, ql, qr);
        ll rightSum = self(self, p * 2 + 1, mid + 1, r, ql, qr);

        return leftSum + rightSum;
    };

    build(build, 1, 1, n);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            ll k, u;
            cin >> k >> u;
            update(update, 1, k, u, 1, n);
        }
        else
        {
            ll r, l;
            cin >> l >> r;

            ll ans = query(query, 1, 1, n, l, r);
            cout << ans << '\n';
        }
    }

    return 0;
}
