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

    ll n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n + 1, vector<char>(m + 1));
    vector<vector<int>> Temp(n + 1, vector<int>(m + 1, 0)); // 列有效高度

    for (int i = 1; i <= n; i++)
    {
        string line;
        cin >> line;
        line = ' ' + line;
        for (int j = 1; j <= m; j++)
        {
            graph[i][j] = line[j];
        }
    }

    ll maxS = 0;

    for (int i = 1; i <= n; i++)
    {
        // 对于每一行
        vector<ll> curCol(m + 2, 0);
        for (int j = 1; j <= m; j++)
        {
            char c = graph[i][j];
            if (c == '*')
            {
                curCol[j] = 0;
                Temp[i][j] = 0;
            }
            else
            {
                curCol[j] = Temp[i - 1][j] + 1;
                Temp[i][j] = Temp[i - 1][j] + 1;
            }
        }

        stack<int> stk;
        stk.push(0);

        for (int j = 1; j <= m + 1; j++)
        {
            while (!stk.empty() && curCol[j] < curCol[stk.top()])
            {
                ll h = curCol[stk.top()];
                stk.pop();
                ll l = j - stk.top() - 1;
                ll s = l * h;
                maxS = max(maxS, s);
            }
            stk.push(j);
        }
    }
    cout << maxS << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.