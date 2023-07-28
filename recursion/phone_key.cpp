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

void phone_key(string &degit, string out, int ind, vector<string> &m, vector<string> &ans)
{
    // Base case
    if (ind >= degit.length())
    {
        ans.push_back(out);
        return;
    }

    // recursive steps
    int map_ind = degit[ind] - '0';
    string map = m[map_ind];

    for (int i = 0; i < map.length(); i++)
    {
        out.push_back(map[i]);
        phone_key(degit, out, ind + 1, m, ans);
        out.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string degit;
    cin >> degit;

    // cout << degit << endl;

    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ans;

    string out;

    phone_key(degit, out, 0, mapping, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}