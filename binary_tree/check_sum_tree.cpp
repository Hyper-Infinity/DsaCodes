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

pair<bool, int> FastCheck(node *root)
{
    // Base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    // if leaf node
    if ((root->l == NULL) && (root->r == NULL))
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    // Recursive steps
    pair<bool, int> left = FastCheck(root->l);
    pair<bool, int> right = FastCheck(root->r);

    bool left_check = left.first;
    bool right_check = right.first;
    bool current_check = (root->data == left.second + right.second) ? true : false;

    pair<bool, int> ans;
    ans.first = (left_check && right_check && current_check) ? true : false;
    ans.second = left.second + right.second  + root->data;
    return ans;
}

bool check_sum_tree(node *root)
{
    return FastCheck(root).first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}