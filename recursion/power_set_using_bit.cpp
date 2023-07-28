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

vector<string> AllPossibleStrings(string s)
{
    vector<string> ans;
    int n = s.length();

    for (int i = 0; i < (1 << n); i++)
    {
        string out = "";

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                out.push_back(s[j]);
            }
        }

        if (out.length() > 0)
        {
            ans.push_back(out);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s ;
    cin >> s;
    vector<string> ans;
    

    ans = AllPossibleStrings(s);

    for (auto it : ans)
    {
        cout << it << endl;
    }

    return 0;
}

