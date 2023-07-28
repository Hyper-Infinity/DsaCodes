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

void permutation(string &input, int ind, vector<string> &ans)
{
    // Base case
    if (ind >= input.length())
    {
        ans.push_back(input);
        return;
    }

    // Recursive steps
    for (int i = ind; i < input.length(); i++)
    {
        swap(input[ind], input[i]);
        permutation(input, ind + 1, ans);
        // in this case perfom back track if you are passing input string by reference.
        // Back track
        swap(input[ind], input[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    cout << endl;

    vector<string> ans;

    permutation(s, 0, ans);

    for (auto it : ans)
    {
        cout << it << endl;
    }

    return 0;
}