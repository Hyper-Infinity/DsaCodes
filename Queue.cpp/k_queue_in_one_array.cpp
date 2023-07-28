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

class k_queue
{
private:
    int k; // Number of the queue.
    int s; // size of the array.
    int *arr;
    int *front;
    int *rear;
    int *next;
    int free_spot;

public:
    k_queue(int num, int size)
    {
        k = num;
        s = size;
        front = new int[k];
        rear = new int[k];
        arr = new int[s];
        next = new int[s];
        free_spot = 0;

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1;
    }

    void push(int data, int m) // m = kis number ki queue me push karana hai.
    {
        // if queue is full
        if (free_spot = -1)
        {
            cout << "Queue is full" << endl;
            return;
        }

        // if queue is not empty.

        // step 1 = finding the index free space to insert an element.
        int ind = free_spot;

        // step 2 = updating free_spot to next free space.
        free_spot = next[ind];

        // inserting 1st element.
        if (front[m - 1] == -1 && rear[m - 1] == -1)
        {
            // step 3 = updating front and rear of mth queue.
            front[m - 1] = ind;
            rear[m - 1] = ind;

            // updating next array
            next[ind] = -1;

            // inserting value at ind
            arr[ind] = data;
        }
        else
        {
            // step 3 = updating next array.
            next[rear[m - 1]] = ind;
            next[ind] = -1;

            // step 4 = updating rear
            rear[m - 1] = ind;

            // step 5 = inserting value at index.
            arr[ind] = data;
        }
    }

    int pop(int m) // m = kis number ki queue me se pop karana hai.
    {
        // if queue is empty.
        if ((front[m - 1] == -1) && (rear[m - 1] == -1))
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        // if Queue is not empty.

        // step 1 = finding the index.
        int ind = front[m - 1];

        // case 1 = Queue has only one element.
        if (next[ind] == rear[m - 1])
        {
            cout << "Popping element : " << arr[ind] << endl;
            arr[ind] = -1;

            // step 2 = upadting front and rear
            front[m - 1] = -1;
            rear[m - 1] = -1;

            // step 3 = updating next free space.
            next[ind] = free_spot;

            // step 4 = updating current free space.
            free_spot = ind;
        }
        else // case 2 = Queue has more than one element.
        {
            cout << "Popping element : " << arr[ind] << endl;
            arr[ind] = -1;

            // step 2 = upadting front.
            front[m - 1] = next[ind];

            // step 3 = updating next free space.
            next[ind] = free_spot;

            // step 4 = updating current free space.
            free_spot = ind;
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}