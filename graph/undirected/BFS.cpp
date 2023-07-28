/* <<<<< CODE BY SRP >>>>> */
/* <<<<< SAMARTH >>>>> */
/* <<<<< JAY HIND >>>>> */

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef vector<long long int> vli;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef map<int, int> mi;
typedef multimap<int, int> mmi;
typedef unordered_map<int, int> umi;
typedef set<int> si;
typedef multiset<int> msi;
typedef unordered_set<int> usi;

// BFS --> breadth first search.
void bfs(int node, unordered_map<int, bool> &visited, unordered_map<int, set<int>> &adj, vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int element = q.front();
        ans.push_back(element);
        q.pop();
        for (auto it : adj[element])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // creating adj_list
    unordered_map<int, set<int>> adj;
    for (auto it : edges)
    {
        int u = it.first;
        int v = it.second;

        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<int> ans;
    // chacking if node is visited or not.
    unordered_map<int, bool> visited;
    for (int i = 0; i < vertex; i++)
    {
        visited[i] = false;
    }

    // starting of BFS
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(i, visited, adj, ans);
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}