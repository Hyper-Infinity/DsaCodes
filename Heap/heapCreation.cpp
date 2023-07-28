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

class maxHeap
{
private:
    int size, index;
    vector<int> arr;
public:
    maxHeap(int n)
    {
        size = n;
        index = 0;
        arr.resize(n + 1);
    }

    void insert(int val)
    {
        if(index < size)
        {
            arr[++index] = val;
            int i = index;
            while(i > 1)
            {
                if(arr[i] > arr[i >> 1])
                {
                    swap(arr[i], arr[i >> 1]);
                    i = i >> 1;
                }
                else
                    return;
            }
        }
        else
            cout << "Heap is full !!" << endl;
    }

    void remove()
    {
        if(index > 0)
        {
            arr[0] = arr[index];
            arr[index] = 0;
            index--;

            int currPosition = 0;
            int leftchild = currPosition * 2; 
            int rightchild = currPosition * 2 + 1;

            while((leftchild <= index && arr[leftchild] > arr[currPosition]) || (rightchild <= index && arr[rightchild] > arr[currPosition]))
            {
                if(leftchild <= index && rightchild <= index)
                {
                    int indexToReplace = arr[leftchild] > arr[rightchild] ? leftchild : rightchild;
                    swap(arr[currPosition], arr[indexToReplace]);
                    currPosition = indexToReplace;
                }
                else if(leftchild <= index)
                {
                    swap(arr[currPosition], arr[leftchild]);
                    currPosition = leftchild;
                }   
                else
                {
                    swap(arr[currPosition], arr[rightchild]);
                    currPosition = rightchild;
                }

                leftchild = currPosition * 2;
                rightchild = currPosition * 2 + 1;
            }
        }
        else
            cout << "Heap is empty !!" << endl;
    }

    void print()
    {
        for(int i = 1; i <= index; i++)
            cout << arr[i] << " ";
        cout << endl;
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

    int n;
    cin >> n;
    maxHeap mh(n);

    mh.insert(1);
    mh.insert(2);
    mh.insert(3);
    mh.insert(4);
    mh.insert(5);
    mh.insert(6);

    mh.print();

    mh.remove();
    mh.remove();

    mh.print();

    return 0;
}