/* <<<<< JAY HIND >>>>> */

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
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

// union by rank
class DSUR
{
private:
    vector<int> rank;
    vector<int> parent;
public:
    DSUR(int n)
    {
        rank.resize(n + 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        // Base case
        if(parent[node] == node)
            return node;
        
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;

        if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else if (rank[pv] > rank[pu]){
            parent[pu] = pv;
        }
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    bool inSameCompo(int u, int v)
    {
        return findParent(u) == findParent(v);
    }
};

// union by size 
class DSUS
{
private:
    vector<int> size;
    vector<int> parent;
public:
    DSUS(int n)
    {
        size.resize(n + 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        // Base case
        if(parent[node] == node)
            return node;
        
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;

        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else if (size[pv] > size[pu]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    bool inSameCompo(int u, int v)
    {
        return findParent(u) == findParent(v);
    }
};

int main()
{
    // #ifndef ONLINE_JUDGE
    /* freopen(input.txt, r, stdin); */
    /* freopen(output.txt, w, stdout); */
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}
