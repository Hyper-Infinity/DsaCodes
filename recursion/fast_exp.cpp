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

    ll fast_exp(ll a, ll b , ll mod)
    {
        // base case
        if (b == 0)
        {
            return 1;
        }
        if (b == 1)
        {
            return a;
        }
    
        // RECURSIVE CALL
        ll ans = (fast_exp(a, b / 2 , mod))%mod;
    
        if (b & 1)
        {
            return ((a)*(ans * ans)%mod)%mod;
        }
        else
        {
            return (ans * ans)%mod;
        }
    }
    int countFriendsPairings(int n) 
    { 
        ll mod = 1e9 + 7;
        ll ans = 0;
        for(int i = 0 ; i <= n/2 ; i++){
            long long z = 1;
            long long d = 1;
            for(int j = 1 ; j<=i ; j++){
                d*=j;
                d%=mod;
                ll r = j-1;
                long long x = ((n - 2*r)*(n-2*r - 1))/2; x%=mod;
                z *= x;
                z%=mod;
            }
            ans+=(z * (fast_exp(d , mod -2 , mod)))%mod;
            ans%=mod;
        }
        return (int)ans;
    }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout<<countFriendsPairings(8);

    return 0;
}