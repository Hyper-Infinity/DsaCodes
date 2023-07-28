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
    
    
void solve()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int xorAns = 0;
    for(int i = 0; i < n; i++)
        xorAns ^= arr[i];
    
    int index = 0;
    while(xorAns)
    {
        if(xorAns & (1 << index))
            break;
        index++;
    }

    int ans1 = 0;
    int ans2 = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] & (1 << index))
            ans1 ^= arr[i];
        else
            ans2 ^= arr[i];
    }

    cout << ans1 << " " << ans2 << endl;
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
    // cin >> t;
    t = 1;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}