// The answer is in the depth of five fathoms. Waiting to be retrieved.
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

    ll lastX = x; // 应该被弹走的
    ll res = 0;
    ll curSum = 0; // 当前窗口的和
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
            // 滑动窗口触发
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
// The answer is in the depth of five fathoms. And has always been her.