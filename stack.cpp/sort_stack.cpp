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
    
    
void insert_at_sort(stack<int> &s, int val)
{
    // Base case 
    if((s.empty()) || ((val >= s.top()) && (!s.empty()))) 
    {
        s.push(val);
        return;
    }

    // recursive step
    int element = s.top();
    s.pop();
    insert_at_sort(s, val);
    s.push(element);
}

void sort(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    // recursive step 
    int num = s.top();
    s.pop();
    sort(s);
    insert_at_sort(s, num);
}
    
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<int> s;

    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sort(s);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}