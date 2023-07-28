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

void heapify(vector<int> &arr, int size, int index)
{
    int largest = index;
    int leftchild = index * 2 + 1;
    int rightchild = index * 2 + 2;

    if(leftchild <= size && arr[leftchild] > arr[largest])
        largest = leftchild;
    if(rightchild <= size && arr[rightchild] > arr[largest])
        largest = rightchild;
    
    if(index != largest)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapsort(vector<int> &arr, int size)
{
    // base case
    if(size < 1)
        return;

    // step 1 
    swap(arr[size], arr[0]);
    size--;

    heapify(arr, size, 0);
    heapsort(arr, size);
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

    vector<int> arr;
    int n;
    cin >> n;
    arr.resize(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for(int i = n >> 1 - 1; i >= 0; i--)
        heapify(arr, n - 1, i);
    
    heapsort(arr, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}