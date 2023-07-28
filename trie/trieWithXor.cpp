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

class trieNode
{
private:
    trieNode* links[2];
public:
    trieNode()
    {
        links[0] = NULL;
        links[1] = NULL;
    }

    bool containsKey(int bit)
    {
        return links[bit];
    }

    trieNode* getNext(int bit)
    {
        return links[bit];
    }

    void putTrieNode(int bit)
    {
        trieNode* node = new trieNode();
        links[bit] = node;
    }
};

class Trie
{
private:
    trieNode* root;
public:
    Trie()
    {
        root = new trieNode();
    }

    void insertNum(int num)
    {
        trieNode* node = root;
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit))
                node->putTrieNode(bit);
            node = node->getNext(bit);
        }
    }

    int getMax(int x)
    {
        int ans = 0;
        trieNode* node = root;
        for(int i = 31; i >= 0; i--)
        {
            int bit = (x >> i) & 1 ? 0 : 1;
            if(node->containsKey(bit))
            {
                ans = ans | (1 << i);
                node = node->getNext(bit);
            }
            else
            {
                bit = bit ? 0 : 1;
                node = node->getNext(bit);
            }
        }
        return ans;
    }
};

int main()
{
    // #ifndef ONLINE_JUDGE
    /* freopen(input.txt, r, stdin); */
    /* freopen(output.txt, w, stdout); */
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}