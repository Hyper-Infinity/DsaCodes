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

class Node
{
public:
    int open;
    int close;
    int full;

    Node()
    {
        open = 0;
        close = 0;
        full = 0;
    }
};

Node merge(Node leftAns, Node rightAns)
{
    Node ans;
    
    ans.open = leftAns.open + rightAns.open - min(leftAns.open, rightAns.close);
    ans.close = leftAns.close + rightAns.close - min(leftAns.open, rightAns.close);
    ans.full = leftAns.full + rightAns.full + min(leftAns.open, rightAns.close);

    return ans;
}

void build(int index, int low, int high, string &s, vector<Node> &seg)
{
    // Base case
    if(low == high)
    {
        if(s[low] == '(')
            seg[index].open = 1;
        else
            seg[index].close = 1;
        return;
    }

    int mid = low + ((high - low) >> 1);
    build((2 * index) + 1, low, mid, s, seg);
    build((2 * index) + 2, mid + 1, high, s, seg);

    seg[index] = merge(seg[(2 * index) + 1], seg[(2 * index) + 2]);
}

Node quary(int index, int low, int high, int l, int r, vector<Node> &seg)
{
    if(high < l || low > r)
        return Node();
    else if(l <= low && high <= r)
        return seg[index];
    else
    {
        int mid = low + ((high - low) >> 1);
        Node leftAns = quary((2 * index) + 1, low, mid, l, r, seg);
        Node rightAns = quary((2 * index) + 2, mid + 1, high, l, r, seg);

        return merge(leftAns, rightAns);
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = s.length();

    vector<Node> seg(4 * n + 1);
    build(0, 0, n - 1, s, seg);

    int q;
    cin >> q;

    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << 2 * quary(0, 0, n - 1, --l, --r, seg).full << endl;
    }
    return 0;
}