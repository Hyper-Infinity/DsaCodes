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

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (auto i : vec)
    {
        int u = i[0];
        int v = i[1];
        int w = i[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> ans;

    for (int i = 0; i < vertices; i++)
    {
        ans.push_back(INT_MAX);
    }

    set<pair<int, int>> s;
    ans[source] = 0;
    s.insert({0, source});

    while (!s.empty())
    {
        auto it1 = s.begin();
        pair<int, int> top = *it1;
        s.erase(it1);

        for (auto i : adj[top.second])
        {
            if ((top.first + i.second) < ans[i.first])
            {
                auto it2 = s.find({ans[i.first], i.first});

                if (it2 != s.end())
                {
                    s.erase(it2);
                }

                ans[i.first] = top.first + i.second;

                s.insert({ans[i.first], i.first});
            }
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