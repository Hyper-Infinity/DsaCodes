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

bool is_safe(int row, int col, int val, vector<vi> &v)
{
    for (int i = 0; i < 9; i++)
    {
        // check for row
        if (v[row][i] == val)
        {
            return false;
        }

        // check for col
        if (v[i][col] == val)
        {
            return false;
        }

        // check for 3X3 matrix
        if (v[(3 * (row / 3)) + (i / 3)][(3 * (col / 3)) + (i % 3)] == val)
        {
            return false;
        }
    }
    return true;
}

bool sudoku(vector<vi> &v)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            // empty cell found
            if (v[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (is_safe(row, col, val, v))
                    {
                        v[row][col] = val;

                        // Recursive call
                        bool check_aage_possible_hai_ya_nahi = sudoku(v);

                        if (check_aage_possible_hai_ya_nahi)
                        {
                            return true;
                        }
                        else
                        {
                            // Back track
                            v[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void print(vector<vi> &v)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vi> v;
    // vector<vi> ans;

    for (int i = 0; i < 9; i++)
    {
        vi input;
        for (int j = 0; j < 9; j++)
        {
            int in;
            cin >> in;
            input.push_back(in);
        }
        v.push_back(input);
    }
    // ans = v;
    if (sudoku(v))
    {
        cout << "Solution of this sudoku is possible" << endl << endl << "The solution of the given sudoku is : " << endl;
        print(v);
    }
    else
    {
        cout << "Solution of this sudoku is not possible" << endl;
    }

    return 0;
}