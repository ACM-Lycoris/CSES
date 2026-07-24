// Find the XOR of all sliding window OR values.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    optimize();

    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    int right = x;

    vector<int> suf(n + 1); // OR values from each position to the end of its block.
    for (int i = 1; i <= n; i++)
    {
        suf[i] = (i == 1 ? x : (1LL * suf[i - 1] * a + b) % c);
        // Build the generated array first.
    }

    for (int i = n - 1; i >= 1; i--)
    {
        // Keep the last value of each block unchanged.
        if (i % k == 0)
        {
            continue;
        }
        else
        {
            suf[i] |= suf[i + 1];
        }
    }

    vector<int> pref(n + 1);

    for (int i = 1; i <= n; i++)
    {
        right = (i == 1 ? x : (1LL * right * a + b) % c);

        if (i % k == 1 || k == 1)
        {
            pref[i] = right;
        }
        else
        {
            pref[i] = (pref[i - 1] | right);
        }
    }

    // The block prefix and suffix values are ready.
    int ans = 0;
    int L = 1; // Left end of the window.

    for (int R = min(n, k); R <= n; R++)
    {
        int curOr = (suf[L] | pref[R]);
        ans ^= curOr;
        L++;
    }

    cout << ans << endl;

    return 0;
}
