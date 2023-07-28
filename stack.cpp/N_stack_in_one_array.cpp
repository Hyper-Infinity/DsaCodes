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

class Nstacks
{
private:
    int *arr;
    int *top;
    int *next;
    int s; // size of the array
    int n; // number of stacks
    int free_spot;

public:
    Nstacks(int num, int size)
    {
        n = num;
        s = size;
        free_spot = 0;

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Initialising top of every stack with -1.
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // next[i] stors 2 things -->
        // 1 : next empty space when next[i] is not alloted to any stack.
        // 2 : when next[i] is alloted to any stack then it stors index previous element of that stack.
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1;
    }

    bool push(int val, int m) // val = jo element push karana hai vo  and m = kis number ke stack me.
    {
        // case 1 = if stack is full
        if (free_spot == -1)
        {
            cout << "stack over-flow" << endl;
            return false;
        }

        // case 2 = stack is not full.

        // step 1 = allote index to current free space.
        int index = free_spot;

        // step 2 = update free_spot (current free space)
        free_spot = next[free_spot];

        // step 3 = update next pointing to the previous element of that stack.
        next[index] = top[m - 1];

        // step 4 = update top pointing to the current element of that stack.
        top[m - 1] = index;

        // step 5 = store the value at index
        arr[index] = val;

        return true;
    }

    void pop(int m) // m = kis stack me se pop karana hai.
    {
        // if stack is empty
        if (top[m - 1] == -1)
        {
            cout << "Stack under_flow" << endl;
        }

        // stack is not empty.

        // step 1 = finding the index of the top element of that stack.
        int ind = top[m - 1];
        cout << "poping element : " << arr[ind] << endl;

        // step 2 = update the top[m - 1]
        top[m - 1] = next[ind];

        // step 3 = update the next[ind] with next free space.
        next[ind] = free_spot;

        // step 4 = updating free_spot.
        free_spot = ind;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Nstacks s1(3, 6);

    s1.push(10, 1);
    s1.push(20, 1);
    s1.push(30, 2);

    s1.pop(3);

    return 0;
}