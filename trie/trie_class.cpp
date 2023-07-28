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
    public:
        char data;
        trieNode* children[26];
        bool flag;

        trieNode(char data)
        {
            this->data = data;
            for(int i = 0; i < 26; i++)
                this->children[i] = NULL;
            flag = false;
        }
};

class Trie 
{
    private:
        trieNode* root;
    private:
        void insertUtil(trieNode* root, string &s, int index)
        {
            // Base case
            if(index >= s.length())
            {
                root->flag = true;
                return;
            }

            int position = s[index] - 'a';
            trieNode* child;

            if(root->children[position])
                child = root->children[position];
            else
            {
                child = new trieNode(s[index]);
                root->children[position] = child;
            }
            insertUtil(child, s, index + 1);
        }

        bool searchUtil(trieNode* root, string &s, int index)
        {
            // Base case
            if(index >= s.length())
            {
                if(root->flag)
                    return true;
                return false;
            }

            int position = s[index] - 'a';

            if(root->children[position])
                return searchUtil(root->children[position], s, index + 1);
            else
                return false;
        }

        void deleteTrieNode(trieNode* root)
        {
            int check = 1;
            if(root->flag) check = 0;

            for(int i = 0; i < 26; i++)
            {
                if(root->children[i])
                    check = 0;
            }

            if(check)
            {
                trieNode* temp = root;
                root = NULL;
                delete temp;
            }
        }

        void deleteUtil(trieNode* root, string &s, int index)
        {
            // Base case
            if(index >= s.length())
            {
                if(root->flag)
                {
                    root->flag = false;
                    deleteTrieNode(root);
                    return;
                }
                cout << "Word Not Found, Nothing To Delete !" << endl;
                return;
            }

            int position = s[index] - 'a';

            if(root->children[position])
            {
                deleteUtil(root->children[position], s, index + 1);
                deleteTrieNode(root);
            }
            else 
            {
                cout << "Word Not Found, Nothing To Delete !" << endl;
                return;
            }
        }

    public:
        Trie()
        {
            this->root = new trieNode('#');
        }

        void insertWord(string s)
        {
            insertUtil(root, s, 0);
        }

        bool searchWord(string s)
        {
            return searchUtil(root, s, 0);
        }

        void deleteWord(string s)
        {
            deleteUtil(root, s, 0);
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

    Trie trie;
    
    trie.insertWord("remove");
    trie.insertWord("remote");
    trie.insertWord("recycle");
    trie.insertWord("samarth");
    trie.insertWord("sam");

    // cout << trie.searchWord("rem") << endl;
    // cout << trie.searchWord("sem") << endl;
    // cout << trie.searchWord("sam") << endl;
    // cout << trie.searchWord("samarth") << endl;
    // cout << trie.searchWord("prachi") << endl;

    // cout << trie.searchWord("sam") << endl;
    // cout << trie.searchWord("samarth") << endl;
    // trie.deleteWord("samarth");
    // trie.deleteWord("samarth");
    // cout << trie.searchWord("sam") << endl;
    // cout << trie.searchWord("samarth") << endl;

    return 0;
}