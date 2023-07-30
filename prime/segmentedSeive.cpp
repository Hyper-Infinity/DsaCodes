// given range L - R ( 1 <= L, R <= 10^12) and (R - L <= 10^6), you have to print all the primes in the range 
// total Q quires Q <= 10

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

const int N = 1000000;
bool seive[N + 1];
vector<int> ds;
void createSeive()
{
    for(int i = 2; i <= N; i++)
        seive[i] = true;
    
    for(int i = 2; i * i <= N; i++)
    {
        if(seive[i])
        {
            for(int j = i * i; j <= N; j += i)
                seive[j] = false;
        }
    }

    for(int i = 2; i <= N; i++)
    {
        if(seive[i])
            ds.push_back(i);
    }
}
    
void solve()
{
    int l, r; 
    cin >> l >> r; 

    vector<bool> dummySeive(r - l + 1, true);
    for(int i = 0; ds[i] * ds[i] <= r; i++)
    {
        int firstMultiple = (l / ds[i]) * ds[i];
        if(firstMultiple < l) firstMultiple += ds[i];

        for(int j = max(firstMultiple, ds[i] * ds[i]); j <= r; j += ds[i])
            dummySeive[j - l] = false;
    }

    for(int i = l; i <= r; i++)
    {
        if(dummySeive[i - l] && i != 1 && i != 0)
            cout << i << " ";
    }
    cout << endl;
}
    
int main()
{
     // #ifndef ONLINE_JUDGE
     /* freopen(input.txt, r, stdin); */
     /* freopen(output.txt, w, stdout); */
     // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    //t = 1;

    createSeive();
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}