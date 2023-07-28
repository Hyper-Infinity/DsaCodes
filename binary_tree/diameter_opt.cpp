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

class node
{
public:
    int data;
    node *l;
    node *r;

    node(int val)
    {
        this->data = val;
        this->l = NULL;
        this->r = NULL;
    }
};

int height(node *root)
{
    // Base case.
    if (root == NULL)
    {
        return 0;
    }

    // Recursive steps
    return max(height(root->l), height(root->r)) + 1;
}

pair<int, int> Fast_Diameter(node *root) //  <<< O(n) >>>  //
{
    // pair<int, int> --> pair.first = diameter , pair.second = height;
    // Base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = Fast_Diameter(root->l);
    pair<int, int> right = Fast_Diameter(root->r);

    int option1 = left.first;
    int option2 = right.first;
    int option3 = left.second + right.second + 1;

    pair<int, int> ans = make_pair(max(option1, max(option2, option3)), max(left.second, right.second) + 1);

    return ans;
}

int opt_diameter(node *root)
{
    return Fast_Diameter(root).first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}