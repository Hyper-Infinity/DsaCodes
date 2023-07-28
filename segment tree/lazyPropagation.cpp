/* <<<<< CODE BY SRP >>>>> */
/* <<<<< SAMARTH >>>>> */
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

class sumSGTree
{
    public :
    vector<int> seg, lazy;

    sumSGTree(int n)
    {
        seg.resize((4 * n) + 1);
        lazy.resize((4 * n) + 1);
    }

    void build(int index, int low, int high, vector<int> &arr)
    {
        // Base case
        if(low == high)
        {
            seg[index] = arr[low];
            return;
        }

        int mid = low + ((high - low) >> 1);

        build((index * 2) + 1, low, mid, arr);
        build((index * 2) + 2, mid + 1, high, arr);

        seg[index] = seg[(index * 2) + 1] + seg[(index * 2) + 2];
    }

    void update(int index, int low, int high, int l, int r, int val)
    {
        // Update the previous remaning updates
        // and propagation downwards
        if(lazy[index] != 0)
        {
            seg[index] += (high - low + 1) * lazy[index];

            // propogate the lazy updates downwards
            // for the remaning nodes to gate update 
            if(low != high)
            {
                lazy[(index * 2) + 1] += lazy[index];
                lazy[(index * 2) + 2] += lazy[index];
            }
        }
        lazy[index] = 0;

        // no overlaping
        // case - 1 --> l r low high
        // case - 2 --> low high l r
        if((r < low) || (high < l))
        {
            return;
        }

        // complete overlaping 
        // l low high r
        if((l <= low) && (high <= r))
        {
            seg[index] += (high - low + 1) * val;

            // propogate the lazy updates downwards
            // for the remaning nodes to gate update 
            if(low != high)
            {
                lazy[(index * 2) + 1] += val;
                lazy[(index * 2) + 2] += val;
            }
            return;
        }

        int mid = low + ((high - low) >> 1);

        update((index * 2) + 1, low, mid, l, r, val);
        update((index * 2) + 2, mid + 1, high, l, r, val);

        seg[index] = seg[(index * 2) + 1] + seg[(index * 2) + 2];
    }

    int sumQuery(int index, int low, int high, int l, int r)
    {
        // Update the previous remaning updates
        // and propagation downwards
        if(lazy[index] != 0)
        {
            seg[index] += (high - low + 1) * lazy[index];

            // propogate the lazy updates downwards
            // for the remaning nodes to gate update 
            if(low != high)
            {
                lazy[(index * 2) + 1] += lazy[index];
                lazy[(index * 2) + 2] += lazy[index];
            }
        }
        lazy[index] = 0;

        // no overlaping
        // case - 1 --> l r low high
        // case - 2 --> low high l r
        if((r < low) || (high < l))
        {
            return 0;
        }

        // complete overlaping 
        // l low high r
        if((l <= low) && (high <= r))
        {
            return seg[index];
        }

        int mid = low + ((high - low) >> 1);

        int left = sumQuery((index * 2) + 1, low, mid, l, r);
        int right = sumQuery((index * 2) + 2, mid + 1, high, l, r);

        return left + right;
    }
};

class minSGTree
{
    public :
    vector<int> seg, lazy;

    minSGTree(int n)
    {
        seg.resize((4 * n) + 1);
        lazy.resize((4 * n) + 1);
    }

    void build(int index, int low, int high, vector<int> &arr)
    {
        // Base case
        if(low == high)
        {
            seg[index] = arr[low];
            return;
        }

        int mid = low + ((high - low) >> 1);

        build((index * 2) + 1, low, mid, arr);
        build((index * 2) + 2, mid + 1, high, arr);

        seg[index] = min(seg[(index * 2) + 1], seg[(index * 2) + 2]);
    }

    void update(int index, int low, int high, int l, int r, int val)
    {
        // Update the previous remaning updates
        // and propagation downwards
        if(lazy[index] != 0)
        {
            seg[index] += lazy[index];

            // propogate the lazy updates downwards
            // for the remaning nodes to gate update 
            if(low != high)
            {
                lazy[(index * 2) + 1] += lazy[index];
                lazy[(index * 2) + 2] += lazy[index];
            }
        }
        lazy[index] = 0;

        // no overlaping
        // case - 1 --> l r low high
        // case - 2 --> low high l r
        if((r < low) || (high < l))
        {
            return;
        }

        // complete overlaping 
        // l low high r
        if((l <= low) && (high <= r))
        {
            seg[index] += val;

            // propogate the lazy updates downwards
            // for the remaning nodes to gate update 
            if(low != high)
            {
                lazy[(index * 2) + 1] += val;
                lazy[(index * 2) + 2] += val;
            }
            return;
        }

        int mid = low + ((high - low) >> 1);

        update((index * 2) + 1, low, mid, l, r, val);
        update((index * 2) + 2, mid + 1, high, l, r, val);

        seg[index] = min(seg[(index * 2) + 1], seg[(index * 2) + 2]);
    }

    int sumQuery(int index, int low, int high, int l, int r)
    {
        // Update the previous remaning updates
        // and propagation downwards
        if(lazy[index] != 0)
        {
            seg[index] += lazy[index];

            // propogate the lazy updates downwards
            // for the remaning nodes to gate update 
            if(low != high)
            {
                lazy[(index * 2) + 1] += lazy[index];
                lazy[(index * 2) + 2] += lazy[index];
            }
        }
        lazy[index] = 0;

        // no overlaping
        // case - 1 --> l r low high
        // case - 2 --> low high l r
        if((r < low) || (high < l))
        {
            return INT_MAX;
        }

        // complete overlaping 
        // l low high r
        if((l <= low) && (high <= r))
        {
            return seg[index];
        }

        int mid = low + ((high - low) >> 1);

        int left = sumQuery((index * 2) + 1, low, mid, l, r);
        int right = sumQuery((index * 2) + 2, mid + 1, high, l, r);

        return min(left, right);
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