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

bool is_safe(int n, int col, int row, vector<vi> &board)
{
    // for same row
    int x = row;
    int y = col;

    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    // for upper diagnol
    x = row;
    y = col;

    while ((x >= 0) && (y >= 0))
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x--;
    }

    // for lower diagnol
    x = row;
    y = col;

    while ((x < n) && (y >= 0))
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }

    return true;
}

void solve(int n, int col, vector<vi> &board, vector<vector<vi>> &ans)
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
        if (is_safe(n, col, row, board))
        {
            board[row][col] = 1;
            solve(n, col + 1, board, ans);
            board[row][col] = 0;
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

    solve(n, 0, board, ans);

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