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

#include <bits/stdc++.h>

bool iscycleDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, set<int>> &adj)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            bool ans = iscycleDFS(it, node, visited, adj);
            if (ans)
            {
                return true;
            }
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // creating adj_list
    unordered_map<int, set<int>> adj;

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];

        adj[u].insert(v);
        adj[v].insert(u);
    }

    // current node is visited or not.
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool check = iscycleDFS(i, -1, visited, adj);
            if (check)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}