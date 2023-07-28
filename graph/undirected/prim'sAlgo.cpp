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

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < m; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> key;

    //     key.push({0, 1});
    key[1] = 0;

    for (int i = 1; i < n; i++)
    {
        //         pair<int, int> top = key.top();
        //         int wt = top.first;
        //         int node = top.second;
        int mini = INT_MAX;
        int node;

        for (int j = 1; j <= n; j++)
        {
            if ((!mst[j]) && (key[j] < mini))
            {
                mini = key[j];
                node = j;
            }
        }
        mst[node] = true;

        for (auto ngb : adj[node])
        {
            if (!mst[ngb.first])
            {
                if (ngb.second < key[ngb.first])
                {
                    parent[ngb.first] = node;
                    key[ngb.first] = ngb.second;
                }
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;

    for (int i = 2; i <= n; i++)
    {
        int v = i;
        int u = parent[i];
        int w = key[i];

        ans.push_back({{u, v}, w});
    }

    return ans;
}

// vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
// {
//     unordered_map<int, list<pair<int, int> > > adj;
    
//     for(auto i : g)
//     {
//         int u = i.first.first;
//         int v = i.first.second;
//         int w = i.second;
        
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     }
    
//     vector<int> parent(n + 1, -1);
//     vector<bool> mst(n + 1, false);
//     vector<int> keyInfo(n + 1, INT_MAX);
    
//     priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > key;
    
//     key.push({0, 1});
//     keyInfo[1] = 0;
    
//     while(!key.empty())
//     {
//         pair<int, int> top = key.top();
        
//         int curr = top.second;
        
//         mst[curr] = true;
        
//         key.pop();
        
//         for(auto it : adj[curr])
//         {
//             int v = it.first;
//             int w = it.second;
            
//             if(!mst[v])
//             {
//                 if(w < keyInfo[v])
//                 {
//                     parent[v] = curr;
//                     keyInfo[v] = w;
//                     key.push({w, v});
//                 }
//             }
//         }
//     }
    
//     vector<pair<pair<int, int>, int>> ans;

//     for (int i = 2; i <= n; i++)
//     {
//         int v = i;
//         int u = parent[i];
//         int w = keyInfo[i];

//         ans.push_back({{u, v}, w});
//     }

//     return ans;
// }


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}