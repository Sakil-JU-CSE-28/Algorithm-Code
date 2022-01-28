#include<bits/stdc++.h>
using namespace std;
#define maxn 5000

const int INF = 1000000000;
int n,m;
int capacity[maxn][maxn];
vector<int>adj[maxn];

int bfs(int s, int t, vector<int>& parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int next : adj[cur])
        {
            if (parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                {
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }

    }
    return 0;
}

int EdmondKarp(int s, int t)
{
    int flow = 0;
    vector<int> parent(n + 1);
    int new_flow;
    while (new_flow = bfs(s, t, parent))
    {
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {

            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main()
{
    cout<<"Enter number of Node : ";
    cin>>n;
    cout<<"Enter number of edge : ";
    cin>>m;
    cout<<"Enter the information of edges : \n";

    for(int i = 0; i < m; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] = c;
    }
    int s,t;
    cout<<"Enter source node : ";
    cin>>s;
    cout<<"Enter destination : ";
    cin>>t;
    cout<<"Maximum flow = "<<EdmondKarp(s,t)<<endl;
    return 0;
}

