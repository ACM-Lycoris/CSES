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

    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    int right = x;

    vector<int> suf(n + 1); // 后缀
    for (int i = 1; i <= n; i++)
    {
        suf[i] = (i == 1 ? x : (1LL * suf[i - 1] * a + b) % c);
        // 先存下原数组
    }

    for (int i = n - 1; i >= 1; i--)
    {
        // 块尾不做处理，直接等于原值
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

    // 前后缀已生成
    int ans = 0;
    int L = 1; // 左索引

    for (int R = min(n, k); R <= n; R++)
    {
        int curOr = (suf[L] | pref[R]);
        ans ^= curOr;
        L++;
    }

    cout << ans << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.