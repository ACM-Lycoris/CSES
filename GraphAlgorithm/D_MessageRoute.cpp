#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    vector<int> vis(n + 1, 0);
    vector<int> pre(n + 1, -1);

    queue<int> q;
    q.push(1);
    vis[1] = true;
    // 固定从1开始搜
    bool ok=false;

    vector<int> path;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u==n){
            //找到
            ok=true;
            path.emplace_back(n);//找到了才能放
            //还原最短路
            while(true){
                int PreU=pre[u];//找到前驱节点
                path.emplace_back(PreU);
                if(PreU==1){
                    break;//结束
                }else{
                    u=PreU;//不是就继续
                }
            }

            break;
        }
        for(int v : graph[u])
        {
            if(!vis[v]){
                q.push(v);
                vis[v]=true;
                pre[v]=u;
            }
        }
    }

    if(ok){
        cout<<path.size()<<endl;
        reverse(all(path));
        for(int x:path){
            cout<<x<<' ';
        }
        cout<<endl;
    }else{
        cout<<"IMPOSSIBLE\n";
    }


    return 0;
}
