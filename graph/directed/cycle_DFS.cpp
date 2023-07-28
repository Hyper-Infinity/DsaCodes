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

bool cycleDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &Dfsvisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    Dfsvisited[node] = true;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            bool ans = cycleDfs(it, visited, Dfsvisited, adj);
            if (ans)
            {
                return true;
            }
        }
        else if (Dfsvisited[it])
        {
            return true;
        }
    }
    Dfsvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    // creating an adj list
    unordered_map<int, list<int>> adj;
    for (auto it : edges)
    {
        int u = it.first;
        int v = it.second;

        adj[u].push_back(v); // u-->v {directed graph}
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> Dfsvisited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = cycleDfs(i, visited, Dfsvisited, adj);
            if (ans)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}