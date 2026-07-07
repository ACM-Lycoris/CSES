// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    ll sum = (1+n)*n/2;
    if(sum&1)cout<<"NO\n";
    else{
        cout<<"YES\n";
        vector<ll> set1,set2;
        sum/=2;
        ll curSum=0;
        for(int i=n;i>=1;i--){
            if(i+curSum<=sum){
                set1.push_back(i);
                curSum+=i;
            }else{
                set2.push_back(i);
            }
        }
        cout<<set1.size()<<'\n';
        for(int num:set1){
            cout<<num<<' ';
        }
        cout<<endl;
        cout<<set2.size()<<'\n';
        for(int num:set2){
            cout<<num<<' ';
        }
        

    }

    return 0;
}