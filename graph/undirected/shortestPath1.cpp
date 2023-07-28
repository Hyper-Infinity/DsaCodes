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

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    unordered_map<int, list<int>> adj;

    for (auto it : edges)
    {
        int u = it.first;
        int v = it.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //     for(auto i : adj)
    //     {
    //         cout << i.first << "--> ";
    //         for(auto j : i.second)
    //         {
    //             cout << j << " ";
    //         }
    //         cout << endl;
    //     }

    unordered_map<int, bool> visited;

    unordered_map<int, int> parent;

    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while (!q.empty())
    {
        int element = q.front();
        q.pop();

        for (auto it : adj[element])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = true;
                parent[it] = element;
            }
        }
    }

    //     for(auto i : parent)
    //     {
    //         cout << i.second << " || ";
    //     }cout << endl;

    vector<int> ans;

    int currNode = t;
    ans.push_back(currNode);

    while (currNode != s)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}