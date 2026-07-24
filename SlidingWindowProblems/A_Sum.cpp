// Find the XOR of all sliding window sums.
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

    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    ll lastX = x; // Value that leaves the next window.
    ll res = 0;
    ll curSum = 0; // Sum of the current window.
    ll nextX;
    for (int i = 1; i <= n; i++)
    {
        
        if (i == 1)
        {
            nextX = x;
        }
        else
        {
            nextX = (nextX * a + b) % c;
        }

        if (i < k)
        {
            curSum += nextX;
        }
        else
        {
            // Update a full window.
            curSum += nextX;
            if (i == k)
            {
                res = curSum;
            }
            else
            {

                curSum -= lastX;
                lastX = (lastX * a + b) % c;
                res ^= curSum;
            }
        }
    }
    cout << res << endl;

    return 0;
}
