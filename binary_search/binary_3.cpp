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

int pivot(vli &v, int n)
{
    int f = 0;
    int b = n - 1;
    int ans = 0;
    int mid = 0;

    while (f < b)
    {
        mid = f + (b - f) / 2;

        if (v[mid] >= v[0])
        {
            f = mid + 1;
        }
        else
        {
            b = mid;
        }
    }
    return f;
    // OR return b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    // t = 1;

    vli v;
    for (int i = 0; i < n; i++)
    {
        ll in;
        cin >> in;
        v.push_back(in);
    }

    cout << "The pivot of the array is at an index : " << pivot(v, n) << endl;

    return 0;
}