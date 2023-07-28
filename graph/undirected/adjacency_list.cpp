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

template <typename T>

class graph
{
public:
    unordered_map<T, list<T>> adj;

    void AddEdge(T u, T v, bool directed)
    {
        // directed = 0 --> undirected.
        // directed = 1 --> directed.

        // create an edge from u to v.
        if (adj[u].front() == -1)
        {
            adj[u].pop_back();
        }

        adj[u].push_back(v);

        if (!directed)
        {
            if (adj[v].front() == -1)
            {
                adj[v].pop_back();
            }
            // if graph is not a directed graph then create an edge from v to u.
            adj[v].push_back(u);
        }
    }

    void print_list()
    {
        for (auto i : adj)
        {
            cout << i.first << "--> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cout << "Enter the number of nodes you want to insert" << endl;
    cin >> n;

    graph<int> g;

    for (int i = 1; i <= n; i++)
    {
        g.adj[i].push_back(-1);
    }

    int m;
    cout << "Enter the number of edges you want to insert" << endl;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.AddEdge(u, v, 0);
    }
    g.print_list();

    return 0;
}