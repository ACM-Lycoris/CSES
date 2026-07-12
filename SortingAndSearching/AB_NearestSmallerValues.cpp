// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<ll> x(n+2);

    x[0]=0;x[n+1]=0;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }

    stack<ll> h;//单调栈
    vector<ll> ans(n+2);
    ans[0]=0;
    h.push(0);

    for(int i=1;i<=n;i++){

        if(x[i]>x[i-1]){
            ans[i]=i-1;
            h.push(i);
        }else{
            while (!h.empty() && x[h.top()]>=x[i])
            {
                h.pop();
            }
            //弹出后的栈顶对应索引就是这个答案
            ans[i]=h.top();
            h.push(i);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.