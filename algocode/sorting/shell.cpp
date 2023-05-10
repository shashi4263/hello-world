#include <bits/stdc++.h>
#include <ctime>
using namespace std;
typedef long long ll;
void print(vector<ll> arr, ll n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void shell(vector<ll> &arr, ll n)
{
    ll i = n / 2;
    while (i)
    {
        for (ll j = i; j < n; j++)
        {
            ll key = arr[j];
            ll k = j - i;
            while (k >= 0 && arr[k] > key)
            {
                arr[k + i] = arr[k];
                k = k - i;
            }
            arr[k + i] = key;
        }
        i = i / 2;
    }
}
int main()
{
    int x = 10;
    ll n = 1000;
    cout << "n A.C B.C W.C " << endl;
    while (x > 0)
    {
        vector<ll> arr;
        double time[3];
        for (int i = 0; i < n; i++)
        {
            int no = rand() % n + 1;
            arr.push_back(no);
        }
        clock_t start, end;
        // shell sort
        // average case
        start = clock();
        shell(arr, n);
        end = clock();
        time[0] = (double)(end - start);
        // best case
        start = clock();
        shell(arr, n);
        end = clock();
        time[1] = (double)(end - start);
        // worst case
        reverse(arr.begin(), arr.end());
        start = clock();
        shell(arr, n);
        end = clock();
        time[2] = (double)(end - start);
        cout << n << " ";
        for (int i = 0; i < 3; i++)
        {
            cout << time[i] << " ";
        }
        cout << endl;
        n += 1000;
        x--;
    }
}
// output
/*
  n A.C B.C W.C
1000 0 0 0
2000 1 0 0
3000 1 0 0
4000 2 0 1
5000 2 0 1
6000 2 0 1
7000 3 1 3
8000 4 1 1
9000 3 1 2
10000 4 1 2
*/