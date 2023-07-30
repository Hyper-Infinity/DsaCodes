// Given the number n in the range 1 - 10^6 you have to print all the prime fectorisation of the number n

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
vector<int> Kprimes;

void cerateSeive()
{
    for (int i = 2; i <= N; i++)
        seive[i] = true;

    for (int i = 2; i * i <= N; i++)
    {
        if (seive[i])
        {
            for (int j = i * i; j <= N; j += i)
                seive[j] = false;
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (seive[i])
            Kprimes.push_back(i);
    }
}

void solve(int n, int index)
{
    if (n == 1)
        return;

    if (n % Kprimes[index] != 0)
        solve(n, index + 1);
    else
    {
        cout << Kprimes[index] << " ";
        solve(n / Kprimes[index], index);
    }
}

// if only 1 number is given (not t test cases)
// root(n) solution is here
void print_PrimeFectorisation(int n)
{
    for(int i = 2; i * i <= n; i++)
    {
        while(n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }
    if(n > 1) cout << n;
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
    // t = 1;
    cerateSeive();

    while (t--)
    {
        int n;
        cin >> n;
        solve(n, 0);
        cout << endl;
    }

    return 0;
}