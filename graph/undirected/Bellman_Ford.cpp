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

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{

    vector<int> dis(n + 1, INT_MAX);

    dis[src] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if ((dis[u] != INT_MAX) && ((dis[u] + w) < dis[v]))
            {
                dis[v] = dis[u] + w;
            }
        }
    }

    bool flag = false;

    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if ((dis[u] != INT_MAX) && ((dis[u] + w) < dis[v]))
        {
            flag = true;
        }
    }

    if (flag)
    {
        cout << "Negative cycle is present !" << endl;
    }
    else
    {
        for (auto i : dis)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return dis[dest];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}