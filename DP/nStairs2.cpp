

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

void countDistinctWays(int nStairs)
{

    vector<int> dp(nStairs + 1, -1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= nStairs; i++)
    {
        dp[i] = ((dp[i - 1]) % MOD + (dp[i - 2]) % MOD) % MOD;
    }

    cout << dp[nStairs];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    // t = 1;

    while (t--)
    {
        int n;
        cin >> n;
        countDistinctWays(n);
    }

    return 0;
}