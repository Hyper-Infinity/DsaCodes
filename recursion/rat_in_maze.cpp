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

// Time com = 4^(n^2);

bool is_safe(vector<vi> v, int n, vector<vi> visited, int newx, int newy)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && (v[newx][newy] == 1) && (visited[newx][newy] == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void path(vector<vi> v, int n, vector<vi> visited, int x, int y, string out, vector<string> &ans)
{
    // falatu case
    if (v[0][0] == 0)
    {
        return;
    }

    // Base case
    if ((x == (n - 1)) && (y == (n - 1)))
    {
        ans.push_back(out);
        return;
    }

    // visited for current path
    visited[x][y] = 1;

    // total 4 possibilities --> U, D, R, L;

    // [1] --> U
    int newx = x - 1;
    int newy = y;
    if (is_safe(v, n, visited, newx, newy))
    {
        out.push_back('U');
        path(v, n, visited, newx, newy, out, ans);
        out.pop_back();
    }

    // [1] --> D
    newx = x + 1;
    newy = y;
    if (is_safe(v, n, visited, newx, newy))
    {
        out.push_back('D');
        path(v, n, visited, newx, newy, out, ans);
        out.pop_back();
    }

    // [1] --> R
    newx = x;
    newy = y + 1;
    if (is_safe(v, n, visited, newx, newy))
    {
        out.push_back('R');
        path(v, n, visited, newx, newy, out, ans);
        out.pop_back();
    }

    // [1] --> L
    newx = x;
    newy = y - 1;
    if (is_safe(v, n, visited, newx, newy))
    {
        out.push_back('L');
        path(v, n, visited, newx, newy, out, ans);
        out.pop_back();
    }

    visited[x][y] = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vi> v;
    vector<string> ans;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vi input;
        for (int j = 0; j < n; j++)
        {
            int in;
            cin >> in;
            input.push_back(in);
        }
        v.push_back(input);
    }

    vector<vi> visited;

    for (int i = 0; i < n; i++)
    {
        vi input;
        for (int j = 0; j < n; j++)
        {
            input.push_back(0);
        }
        visited.push_back(input);
    }

    int x = 0;
    int y = 0;

    string out = "";

    path(v, n, visited, x, y, out, ans);
    sort(all(ans));

    for (auto it : ans)
    {
        cout << it << endl;
    }

    return 0;
}