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

int pivot(vi &v, int f, int r)
{
    // p = pivot
    int p = v[f];

    // pi = pivot index
    int pi;

    int add = 0;

    for (int i = f + 1; i <= r; i++)
    {
        if (v[i] < p)
        {
            add++;
        }
    }
    pi = f + add;

    swap(v[f], v[pi]);

    int i = f;
    int j = r;

    while ((i < pi) && (j > pi))
    {
        while (v[i] < p)
        {
            i++;
        }
        while (v[j] > p)
        {
            j--;
        }
        
        if ((i < pi) && (j > pi))
        {
            swap(v[i], v[j]);
        }
    }
    return pi;
}   
    
    
void quick_sort(vi &v, int f, int r)
{
    //Base case
    if (f >= r)
    {
        return;
    }

    //Step 1
    int p = pivot(v, f, r);

    //Recursive call for laft part
    quick_sort(v, f, p - 1);

    //Recursive call for right part
    quick_sort(v, p + 1, r);
}
    
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vi v = {2, 4, 8, 5, 6, 1, 2, 3};

    int n = v.size();

    quick_sort(v, 0, n - 1);

    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}