// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(all(a));
    sort(all(b));

    ll i = 0, j = 0;

    ll ans = 0;

    while (i < n && j < m)
    {
        ll l = a[i] - k, r = a[i] + k;

        if (l <= b[j] && b[j] <= r)
        {
            ans++;
            i++;
            j++;
        }
        else
        {
            if (l > b[j])
            {
                j++;
            }
            else if (r < b[j])
            {
                i++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.