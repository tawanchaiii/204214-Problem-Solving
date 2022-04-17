#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector<pii> G[100001];
vector<int> num;
int n, m, l;
int sum = 0, maxw = -1, maxn = -1;
int main()
{
    num.push_back(0);
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        num.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    vector<int> dist(n+1,1e9);
    queue<pii> q;
    dist[1] = 0;
    q.push({1, 0});
    while (!q.empty())
    {
        int u = q.front().first;
        q.pop();
        for (auto it : G[u])
        {
            int v = it.first;
            int w = it.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                q.push({v, dist[v]});
            }
        }
    }
    for(int i=2;i<=n;i++){
        sum+= min(dist[i]*l,dist[i]*num[i]);
    }
    cout << sum;
}