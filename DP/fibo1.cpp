#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    int p1 = 0;
    int p2 = 1;

    if(n == 0)
    {
        return p1;
    }
    
    for(int i = 2; i <= n; i++)
    {
        int curr = p1 + p2;
        p1 = p2;
        p2 = curr;
    }
    
    return p2;
}

int main()
{
    int n;
    cin >> n;
    
    cout << fib(n);
}