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

class SGTree
{
    public :
    vector<int> seg, lazy;

    SGTree(int n)
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

    void update(int index, int low, int high, int l, int r)
    {
        if(lazy[index])
        {
            seg[index] = (high - low + 1) - seg[index];

            if(low != high)
            {
                lazy[(index * 2) + 1] = !lazy[(index * 2) + 1];
                lazy[(index * 2) + 2] = !lazy[(index * 2) + 2];
            }
        }
        lazy[index] = 0;

        // no overlaping
        if((r < low) || (high < l))
        {
            return;
        }

        // complete overlaping
        if((l <= low) && (high <= r))
        {
            seg[index] = (high - low + 1) - seg[index];

            if(low != high)
            {
                lazy[(index * 2) + 1] = !lazy[(index * 2) + 1];
                lazy[(index * 2) + 2] = !lazy[(index * 2) + 2];
            }
            return;
        }

        int mid = low + ((high - low) >> 1);

        update((index * 2) + 1, low, mid, l, r);
        update((index * 2) + 2, mid + 1, high, l, r);

        seg[index] = seg[index * 2 + 1] + seg[index * 2 + 2];
    }

    int query(int index, int low, int high, int l, int r)
    {
        if(lazy[index])
        {
            seg[index] = (high - low + 1) - seg[index];

            if(low != high)
            {
                lazy[(index * 2) + 1] = !lazy[(index * 2) + 1];
                lazy[(index * 2) + 2] = !lazy[(index * 2) + 2];
            }
        }
        lazy[index] = 0;

        // no overlaping
        if((r < low) || (high < l))
        {
            return 0;
        }

        // complete overlaping
        if((l <= low) && (high <= r))
        {
            return seg[index];
        }

        int mid = low + ((high - low) >> 1);

        int left = query((index * 2) + 1, low, mid, l, r);
        int right = query((index * 2) + 2, mid + 1, high, l, r);

        return left + right;
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

    int n;
    cin >> n;
    
    vector<int> arr(n, 0);

    for(int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        arr[i] = in;
    }

    SGTree st(n);

    st.build(0, 0, n - 1, arr);

    int q;
    cin >> q;

    while (q--)
    {
        int type;
        cin >> type;
        int l, r;
        cin >> l >> r;

        if(type == 1)
        {
            cout << st.query(0, 0, n - 1, l, r) << endl;
        }
        else
        {
            st.update(0, 0, n - 1, l, r);
        }
    }

    return 0;
}