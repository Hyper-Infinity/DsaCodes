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

int first_occerence(vector<int> &arr, int size, int key)
{
    int f = 0;
    int b = size - 1;
    int ans = -1;
    int mid = 0;

    while (f <= b)
    {
        mid = f + (b - f) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            b = mid - 1;
        }
        else if (arr[mid] < key)
        {
            f = mid + 1;
        }
        else
        {
            b = mid - 1;
        }
    }
    return ans;
}

int last_occerence(vector<int> &arr, int size, int key)
{
    int f = 0;
    int b = size - 1;
    int ans = -1;
    int mid = 0;

    while (f <= b)
    {
        mid = f + (b - f) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            f = mid + 1;
        }
        else if (arr[mid] < key)
        {
            f = mid + 1;
        }
        else
        {
            b = mid - 1;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    // t = 1;

    vi v;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        v.push_back(in);
    }
    int key;
    cin >> key;

    cout << "The first occurence of the element " << key << " is : " << first_occerence(v, n, key) << endl
         << endl;
    cout << "The last occurence of the element " << key << " is : " << last_occerence(v, n, key) << endl;

    return 0;
}