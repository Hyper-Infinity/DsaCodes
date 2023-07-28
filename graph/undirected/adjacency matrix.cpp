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

class graph
{
    public : 
    int numberOfNode;
    vector<vector<int>> adj;

    graph(int num)
    {
        this->numberOfNode = num;

        for(int i = 0; i < num; i++)
        {
            vector<int> temp(num, 0);
            adj.push_back(temp);
        }
    }

    void add_edge(int u, int v, bool directed)
    {
        // directed = 1 --> directed graph 
        // directed = 0 --> undirected graph

        adj[u][v] = 1;

        if(!directed)
        {
            adj[v][u] = 1;
        }
    }

    void print_matrix()
    {   int temp1 = 0;
        for(auto it : adj)
        {
            cout << temp1 << "-> ";
            for(auto i : it)
            {
                cout << i << " ";
            }
            temp1++;
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

    graph g(n);

    int m;
    cout << "Enter the number of edges you want to insert" << endl;
    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g.add_edge(u, v, 0);
    }

    g.print_matrix();

    return 0;
}