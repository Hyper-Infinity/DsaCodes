// given range form 1 - 10^6
// you are given with Q Queries each of Which have prime number as p.
// you have to find how many numbers are there in the range with minimum prime fector sa p.

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
int seive[N + 1];

void createSeive()
{
    for (int i = 2; i <= N; i++)
        seive[i] = 1;

    for (int i = 2; i * i <= N; i++)
    {
        if (seive[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (seive[j])
                {
                    seive[i]++;
                    seive[j] = 0;
                }
            }
        }
    }
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

    createSeive();

    int Q;
    cin >> Q;

    while (Q--)
    {
        int p;
        cin >> p;
        cout << seive[p] << endl;
    }

    return 0;
}