#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
vector<int>adjacency_list[MAXN],components[MAXN],rev_adj[MAXN];
stack<int>node;
bool visited[MAXN],component[MAXN];
int numofcom = 0;
void dfs1(int source)
{
    visited[source] = 1;

    for(int i = 0; i < adjacency_list[source].size(); i++)
    {
        if(!visited[adjacency_list[source][i]])
        {
            dfs1(adjacency_list[source][i]);
        }
    }

    node.push(source);

}

void dfs2(int source)
{
    component[source] = numofcom;
    visited[source] = 1;
    components[numofcom].push_back(source);

    for(int i = 0; i < rev_adj[source].size(); i++)
    {
        if(!visited[rev_adj[source][i]])
        {
            dfs2(rev_adj[source][i]);
        }
    }

}

void SCC(int n)
{

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
            dfs1(i);
    }

    memset(visited,0,sizeof visited);

    while(!node.empty())
    {
        int a = node.top();

        node.pop();

        if(!visited[a])
        {
            dfs2(a);
            numofcom++;
        }

    }

}

int main()
{
    int n,m;
    cout<<"Number of node : ";cin>>n;

    cout<<"Number of edge : ";cin>>m;


    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        adjacency_list[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    SCC(n);
    cout<<"Total : "<<numofcom<<endl;
    cout<<"Component are : ";
    for(int i = 0; i < numofcom; i++)
    {

            for(auto it:components[i])
                cout<<it<<" ";
            cout<<endl;

    }

    return 0;

}
