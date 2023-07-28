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

// Time com = n!.

bool is_safe(int n, int col, int row, vector<vi> &board, mi &r, mi &ud, mi &ld)
{
    // for same row
    if (r[row])
    {
        return false;
    }

    // for upper diagnol
    if (ud[(n - 1) + (col - row)])
    {
        return false;
    }

    // for lower diagnol
    if (ld[row + col])
    {
        return false;
    }

    return true;
}

void solve(int n, int col, vector<vi> &board, vector<vector<vi>> &ans, mi &r, mi &ud, mi &ld)
{
    // Base case
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    // Recursive steps
    for (int row = 0; row < n; row++)
    {
        if (is_safe(n, col, row, board, r, ud, ld))
        {
            board[row][col] = 1;
            r[row] = 1;
            ld[row + col] = 1;
            ud[(n - 1) + (col - row)] = 1;
            solve(n, col + 1, board, ans, r, ud, ld);
            // Back track
            board[row][col] = 0;
            r[row] = 0;
            ld[row + col] = 0;
            ud[(n - 1) + (col - row)] = 0;
        }
    }
}

bool check(vector<vi> &ans, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ans[i][j] == 1)
            {
                return true;
            }
        }
    }
    return false;
}

void print(vector<vi> &ans, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vi> board(n, vi(n, 0));
    vector<vector<vi>> ans;
    mi r;
    mi ud;
    mi ld;

    solve(n, 0, board, ans, r, ud, ld);

    for (auto it : ans)
    {
        if (check(it, n))
        {
            print(it, n);
            cout << endl
                 << endl;
        }
    }

    if ((n == 2) || (n == 3))
    {
        cout << "There is no such Combination possible" << endl;
    }

    return 0;
}