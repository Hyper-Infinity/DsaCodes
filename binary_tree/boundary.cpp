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

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void traverseLeft(Node *root, vi &ans)
{
    // Base case
    if (root == NULL)
    {
        return;
    }

    // if current node is leaf node
    if ((root->left == NULL) && (root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);

    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node *root, vi &ans)
{
    if (root == NULL)
    {
        return;
    }
    // condition
    if ((root->left == NULL) && (root->right == NULL))
    {
        ans.push_back(root->data);
    }

    traverseLeaf(root->left, ans);

    traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vi &ans)
{
    // Base case
    if (root == NULL)
    {
        return;
    }

    // if current node is leaf node
    if ((root->left == NULL) && (root->right == NULL))
    {
        return;
    }

    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }

    // vapas aagaye to store karavalo kyoki hame reverce order me chahiye tha
    ans.push_back(root->data);
}

vi Boundary(Node *root)
{
    vi ans;

    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // left prat print/store
    traverseLeft(root->left, ans);

    // traverse leaf nodes

    // left subtree
    traverseLeaf(root->left, ans);

    // right subtree
    traverseLeaf(root->right, ans);

    // right part store/print
    traverseRight(root->right, ans);

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}