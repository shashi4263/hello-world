#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int lb, int ub)
{
    int key = v[ub]; // pivot element
    int lo = lb - 1;
    for (int i = lb; i < ub; i++)
    {
        if (v[i] <= key)
        {
            swap(v[i], v[++lo]);
        }
    }
    swap(v[ub], v[++lo]);
    return lo;
}

int kst(vector<int> &v, int q, int lb, int ub)
{
    while (lb <= ub)
    {
        int x = partition(v, lb, ub);
        if (x == q)
        {
            return v[x];
        }
        else if (q < x)
        {
            return (kst(v, q, 0, x - 1));
        }
        else
        {
            return (kst(v, q, x + 1, ub));
        }
    }
    return -1;
}

int main()
{
    vector<int> v;
    int n;
    cout << "enter the total number of element -> ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter " << (i + 1) << " th element -> ";
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << "enter the position -> ";
    int q;
    cin >> q;
    cout << kst(v, q - 1, 0, n - 1) << endl;
    return 0;
}

// output
/*
enter the total number of element -> 5
enter 1 th element -> 2
enter 2 th element -> 3
enter 3 th element -> 4
enter 4 th element -> 6
enter 5 th element -> 24
enter the position -> 4
6
*/