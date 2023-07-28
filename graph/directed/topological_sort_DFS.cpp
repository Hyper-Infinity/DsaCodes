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

void topological_DFS(int node, vector<bool> &visited, unordered_map<int, list<int>> &adj, stack<int> &ans)
{
    visited[node] = true;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            topological_DFS(it, visited, adj, ans);
        }
    }
    ans.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{

    // creating an adj list
    unordered_map<int, list<int>> adj;
    vector<int> ans;

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v); // u-->v {directed graph}
    }

    stack<int> rev_ans;
    vector<bool> visited(v);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topological_DFS(i, visited, adj, rev_ans);
        }
    }

    while (!rev_ans.empty())
    {
        ans.push_back(rev_ans.top());
        rev_ans.pop();
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