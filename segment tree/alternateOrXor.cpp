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

void SGTree(int index, int low, int high, vector<int> &arr, vector<int> &seg, int orr)
{
    // Base case
    if (low == high)
    {
        seg[index] = arr[low];
        return;
    }

    int mid = low + ((high - low) >> 1);

    SGTree((index * 2) + 1, low, mid, arr, seg, !orr);
    SGTree((index * 2) + 2, mid + 1, high, arr, seg, !orr);

    if (orr)
    {
        seg[index] = seg[(index * 2) + 1] | seg[(index * 2) + 2];
    }
    else
    {
        seg[index] = seg[(index * 2) + 1] ^ seg[(index * 2) + 2];
    }
}

void update(int index, int low, int high, vector<int> &arr, vector<int> &seg, int orr, int i, int val)
{
    // Base case
    if (low == high)
    {
        seg[index] = val;
        return;
    }

    int mid = low + ((high - low) >> 1);

    if (i <= mid)
    {
        update((index * 2) + 1, low, mid, arr, seg, !orr, i, val);
    }
    else
    {
        update((index * 2) + 2, mid + 1, high, arr, seg, !orr, i, val);
    }

    if (orr)
    {
        seg[index] = seg[(index * 2) + 1] | seg[(index * 2) + 2];
    }
    else
    {
        seg[index] = seg[(index * 2) + 1] ^ seg[(index * 2) + 2];
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    /* freopen(input.txt, r, stdin); */
    /* freopen(output.txt, w, stdout); */
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> arr;

    for (int i = 0; i < (1 << n); i++)
    {
        int in;
        cin >> in;
        arr.push_back(in);
    }

    vector<int> seg((4 * (1 << n)) + 1);
    int el = arr.size();

    if (n & 1)
    {
        SGTree(0, 0, el - 1, arr, seg, 1);
    }
    else
    {
        SGTree(0, 0, el - 1, arr, seg, 0);
    }

    // cout << n << ", " << el << endl;
    // for(auto i : arr)
    // {
    //     cout << i << " ";
    // }cout << endl;

    // for(auto i : seg)
    // {
    //     cout << i << " ";
    // }cout << endl;

    while (q--)
    {
        int i, val;
        cin >> i >> val;

        i--;

        if(n & 1)
        {
            update(0, 0, el - 1, arr, seg, 1, i, val);
        }
        else
        {
            update(0, 0, el - 1, arr, seg, 0, i, val);
        }
        cout << seg[0] << endl;
    }

    return 0;
}