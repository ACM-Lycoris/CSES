// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline void optimize(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    optimize();

    ll n;
    cin>>n;
    vector<ll> a(n+2,0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    stack<ll> stk;
    stk.push(0);

    ll ans=0;

    for(int i=1;i<=n+1;i++){
        while(!stk.empty() && a[i]<a[stk.top()]){
            
            ll curHigh=a[stk.top()];
            stk.pop();
            ll curLen=i-stk.top()-1;
            ll curS=curLen*curHigh;
            ans=max(ans,curS);
        }
        stk.push(i);
    }

    cout<<ans<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.