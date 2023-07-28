

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


    
int solve(int n, vector<int> &dp)
{
    // base case
    if(n == 0)
    {
        return 1;
    }
    else if(n < 0)
    {
        return 0;
    }
    
    if(dp[n] != -1)
    {
        return dp[n];
    }
    
    dp[n] = (solve(n - 1, dp) % MOD + solve(n - 2, dp) % MOD) % MOD;
    
    return dp[n] % MOD;
    
}

void countDistinctWays(int nStairs) {
    
    vector<int> dp(nStairs + 1, -1);
    
    cout << solve(nStairs, dp) << endl;
}
    
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    //t = 1;
    
    while(t--)
    {
        int n;
        cin >> n;
        countDistinctWays(n);
    }
    
    return 0;
}