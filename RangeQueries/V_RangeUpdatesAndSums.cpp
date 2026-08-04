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
    vector<ll> t(n + 1);

    for (ll i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    vector<ll> Tree(4 * n + 5, 0), LazyAdd(4 * n + 5, 0), LazySet(4 * n + 5, 0);
    vector<bool> haveSet(4 * n + 5, false);

    auto build = [&](auto &&self, int p, int l, int r) -> void
    {
        if (l == r)
        {
            Tree[p] = t[l];
            return;
        }
        ll mid = l + (r - l) / 2;
        self(self, p * 2, l, mid);
        self(self, p * 2 + 1, mid + 1, r);
        Tree[p] = Tree[p * 2] + Tree[p * 2 + 1];
    };

    auto ApplyAdd = [&](ll p, ll len, ll k) -> void
    {
        Tree[p] += len * k;
        LazyAdd[p] += k;
    };

    auto ApplySet = [&](ll p, ll len, ll x) -> void
    {
        Tree[p] = x * len;
        haveSet[p] = true;
        LazySet[p] = x;
        LazyAdd[p] = 0;
    };

    auto pushDown = [&](ll p, ll l, ll r) -> void
    {
        if (l == r)
        {
            return;
        }
        ll mid = l + (r - l) / 2;
        ll lenL = mid - l + 1, lenR = r - mid;
        if (haveSet[p])
        {
            ApplySet(p * 2, lenL, LazySet[p]);
            ApplySet(p * 2 + 1, lenR, LazySet[p]);
            haveSet[p] = false;
        }
        if (LazyAdd[p])
        {
            ApplyAdd(p * 2, lenL, LazyAdd[p]);
            ApplyAdd(p * 2 + 1, lenR, LazyAdd[p]);
            LazyAdd[p] = 0;
        }
    };

    auto updateAdd = [&](auto &&self, ll p, ll l, ll r, ll ql, ll qr, ll k) -> void
    {
        if (ql <= l && r <= qr)
        {
            ApplyAdd(p, r - l + 1, k);
            return;
        }
        pushDown(p, l, r);
        ll mid = l + (r - l) / 2;
        if (ql <= mid)
        {
            self(self, p * 2, l, mid, ql, qr, k);
        }
        if (qr > mid)
        {
            self(self, p * 2 + 1, mid + 1, r, ql, qr, k);
        }

        Tree[p] = Tree[p << 1] + Tree[p << 1 | 1];
    };

    auto updateSet = [&](auto &&self, ll p, ll l, ll r, ll ql, ll qr, ll x) -> void
    {
        if (ql <= l && r <= qr)
        {
            ApplySet(p, r - l + 1, x);
            return;
        }
        pushDown(p, l, r);
        ll mid = l + (r - l) / 2;
        if (ql <= mid)
        {
            self(self, p * 2, l, mid, ql, qr, x);
        }
        if (qr > mid)
        {
            self(self, p * 2 + 1, mid + 1, r, ql, qr, x);
        }

        Tree[p] = Tree[p << 1] + Tree[p << 1 | 1];
    };

    auto Query = [&](auto &&self, ll p, ll l, ll r, ll ql, ll qr) -> ll
    {
        if (ql <= l && r <= qr)
        {
            return Tree[p];
        }
        pushDown(p, l, r);
        if (qr < l || ql > r)
        {
            return 0;
        }
        ll mid = l + (r - l) / 2;
        ll res = 0;
        if (ql <= mid)
        {
            res += self(self, p * 2, l, mid, ql, qr);
        }
        if (qr > mid)
        {
            res += self(self, p * 2 + 1, mid + 1, r, ql, qr);
        }
        return res;
    };

    build(build, 1, 1, n);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        { // 区间加值修改
            ll a, b, k;
            cin >> a >> b >> k;
            updateAdd(updateAdd, 1, 1, n, a, b, k);
        }
        else if (type == 2)
        { // 区间赋值修改
            ll a, b, x;
            cin >> a >> b >> x;
            updateSet(updateSet, 1, 1, n, a, b, x);
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            ll res = Query(Query, 1, 1, n, a, b);
            cout << res << '\n';
        }
    }

    return 0;
}
