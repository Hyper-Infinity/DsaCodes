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

// class SGTree
// {
//     vector<int> seg;

//     SGTree(int n)
//     {
//         seg.resize((4 * n) + 1);
//     }

//     void build(int index, int low, int high, vector<int> &arr)
//     {
//         // Base case
//         if (low == high)
//         {
//             seg[index] = arr[low];
//             return;
//         }

//         int mid = low + ((high - low) >> 1);

//         build((2 * index) + 1, low, mid, arr);
//         build((2 * index) + 2, mid + 1, high, arr);

//         seg[index] = min(seg[(2 * index) + 1], seg[(2 * index) + 2]);
//     }

//     int minQuery(int index, int low, int high, int l, int r)
//     {
//         // no overLap
//         // case - 1 --> low high l r
//         // case - 2 --> l r low high
//         if ((l > high) || (r < low))
//         {
//             return INT_MAX;
//         }
//         // complete overLap
//         // l low high r
//         if ((l <= low) && (high <= r))
//         {
//             return seg[index];
//         }

//         int mid = low + ((high - low) >> 1);
//         int left = minQuery((index * 2) + 1, low, mid, l, r);
//         int right = minQuery((index * 2) + 2, mid + 1, high, l, r);

//         return min(left, right);
//     }

//     void update(int index, int low, int high, int i, int val)
//     {
//         // Base case
//         if (low == high)
//         {
//             seg[index] = val;
//             return;
//         }

//         int mid = low + ((high - low) >> 1);

//         if (i <= mid)
//         {
//             update((index * 2) + 1, low, mid, i, val);
//         }
//         else
//         {
//             update((index * 2) + 2, mid + 1, high, i, val);
//         }
//         seg[index] = min(seg[(2 * index) + 1], seg[(2 * index) + 2]);
//     }
// };

class SGTree
{
private:
    vector<int> seg;

public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int *arr, int index, int low, int high)
    {
        // Base case
        if (low == high)
        {
            seg[index] = arr[low];
            return;
        }

        int mid = low + ((high - low) >> 1);
        build(arr, (2 * index) + 1, low, mid);
        build(arr, (2 * index) + 2, mid + 1, high);
        seg[index] = min(seg[(2 * index) + 1], seg[(2 * index) + 2]);
    }

    int minQuery(int index, int low, int high, int l, int r)
    {
        if (l > high || r < low)
            return INT_MAX;
        else if (low >= l && high <= r)
            return seg[index];
        else
        {
            int mid = low + ((high - low) >> 1);
            int leftAns = minQuery((2 * index) + 1, low, mid, l, r);
            int rightAns = minQuery((2 * index) + 2, mid + 1, high, l, r);
            return min(leftAns, rightAns);
        }
    }

    void pointUpdate(int index, int low, int high, int i, int val)
    {
        // base case
        if (low == high)
        {
            seg[index] = val;
            return;
        }

        int mid = low + ((high - low) >> 1);
        if (i <= mid)
            pointUpdate((2 * index) + 1, low, mid, i, val);
        else
            pointUpdate((2 * index) + 2, mid + 1, high, i, val);

        seg[index] = min(seg[(2 * index) + 1], seg[(2 * index) + 2]);
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