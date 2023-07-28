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

class Graph
{
public:
    int n;
    int e;
    unordered_map<int, list<pair<int, int>>> adj;

    Graph(int n, int e)
    {
        this->n = n;
        this->e = e;
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
    }

    void printGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << "--> ";
            for (auto j : i.second)
            {
                cout << "[" << j.first << ", " << j.second << "] ";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo)
    {
        visited[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                dfs(i.first, visited, topo);
            }
        }

        topo.push(node);
    }

    void shortestPath(int s)
    {
        unordered_map<int, bool> visited;
        stack<int> topo;

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            ans.push_back(INT_MAX);
        }

        ans[s] = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, topo);
            }
        }

        while(!topo.empty())
        {
            int top = topo.top();
            topo.pop();

            if (ans[top] != INT_MAX)
            { 
                for (auto j : adj[top])
                {
                    if ((j.second + ans[top]) < ans[j.first])
                    {
                        ans[j.first] = j.second + ans[top];
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;

        // <<<<<<<<<<<<<<<<<<<< USING DIJKSTRA'S ALGORITHAM >>>>>>>>>>>>>>>>>>>>>>>>

        // vector<int> ans(n, INT_MAX);

        // set<pair<int, int>> s1;

        // ans[s] = 0;
        // s1.insert({0, s});

        // while(!s1.empty())
        // {
        //     pair<int, int> top = *(s1.begin());

        //     s1.erase(s1.begin());

        //     int dis = top.first;
        //     int  node = top.second;

        //     for(auto i : adj[node])
        //     {
        //         if((dis + i.second) < ans[i.first])
        //         {
        //             ans[i.first] = dis + i.second;
        //             s1.insert({ans[i.first], i.first});
        //         }
        //     }
        // }

        // for (int i = 0; i < n; i++)
        // {
        //     cout << ans[i] << " ";
        // }
        // cout << endl;

    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Graph g(6, 9);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printGraph();

    g.shortestPath(1);

    return 0;
}