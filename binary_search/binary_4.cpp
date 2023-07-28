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

    
ll aprox_sqrt(ll n)
{
    ll f = 0;
    ll b = n;
    ll ans = 0;
    ll mid = 0;

    while (f <= b)
    {
        mid = f + (b - f) / 2;

        if ((mid * mid) <= n)
        {
            ans = mid;
            f = mid + 1;
        }
        else
        {
            b = mid - 1;
        }
    }
    return ans;
}
    
double final_sqrt(ll n, ll p)
{
    double ans = aprox_sqrt(n);
    double add = 1;
    for (ll i = 1; i <= p; i++)
    {
        add = add / 10;
        while ((ans * ans) < n)
        {
            ans = ans + add;
        }
        ans = ans - add;
    }
    return ans + add;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    //t = 1;

    cout << "Squar root of " << t << " is : " << final_sqrt(t, 3) << endl; 
    
    return 0;
}