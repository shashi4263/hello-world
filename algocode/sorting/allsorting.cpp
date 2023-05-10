#include <bits/stdc++.h>
#include <ctime>
using namespace std;
typedef long long ll;
void print(ll arr[], ll n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubble(ll arr[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        ll c = 0;
        for (ll j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                c++;
            }
        }
        if (c == 0)
        {
            break;
        }
    }
}
void insertion(ll arr[], ll n)
{
    for (ll i = 1; i < n; i++)
    {
        ll key = arr[i];
        ll j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void selection(ll arr[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        ll s = i;
        for (ll j = i + 1; j < n; j++)
        {
            if (arr[s] > arr[j])
            {
                s = j;
            }
        }
        swap(arr[i], arr[s]);
    }
}
void shell(ll arr[], ll n)
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
void heapify(ll arr[], ll n, ll i)
{
    ll curr = i;
    ll lc = 2 * i + 1;
    ll rc = 2 * i + 2;
    if (lc < n && arr[lc] > arr[curr])
    {
        curr = lc;
    }
    if (rc < n && arr[rc] > arr[curr])
    {
        curr = rc;
    }
    if (curr != i)
    {
        swap(arr[i], arr[curr]);
        heapify(arr, n, curr);
    }
}
void heap(ll arr[], ll n)
{
    for (ll i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (ll i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}
void merge(ll arr[], ll l, ll mid, ll h)
{
    vector<ll> v1;
    vector<ll> v2;
    for (ll i = l; i <= mid; i++)
    {
        v1.push_back(arr[i]);
    }
    for (ll i = mid + 1; i <= h; i++)
    {
        v2.push_back(arr[i]);
    }
    ll x = l;
    ll i = 0, j = 0;
    while (i != v1.size() && j != v2.size())
    {
        if (v1[i] <= v2[j])
        {
            arr[x++] = v1[i++];
        }
        else
        {
            arr[x++] = v2[j++];
        }
    }
    while (i != v1.size())
    {
        arr[x++] = v1[i++];
    }
    while (j != v2.size())
    {
        arr[x++] = v2[j++];
    }
}
void mergesort(ll arr[], ll l, ll h)
{
    ll mid = (l + h) / 2;
    if (l >= h)
    {
        return;
    }
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, h);
    merge(arr, l, mid, h);
}
int main()
{
    int x = 10;
    ll n = 1000;
    cout << "n B.S S.S I.S H.S Shell.S" << endl;
    while (x > 0)
    {
        ll arr[6][n];
        double time[6];
        for (int i = 0; i < n; i++)
        {
            int no = rand() % n + 1;
            arr[0][i] = no;
            arr[1][i] = no;
            arr[2][i] = no;
            arr[3][i] = no;
            arr[4][i] = no;
            arr[5][i] = no;
        }
        // bubble sort
        clock_t start, end;
        start = clock();
        bubble(arr[0], n);
        end = clock();
        time[0] = (double)(end - start);
        // selection sort
        start = clock();
        selection(arr[1], n);
        end = clock();
        time[1] = (double)(end - start);
        // insertion sort
        start = clock();
        insertion(arr[2], n);
        end = clock();
        time[2] = (double)(end - start);
        // merge sort
        start = clock();
        mergesort(arr[3], 0, n - 1);
        end = clock();
        time[3] = (double)(end - start);
        // heap sort
        start = clock();
        heap(arr[4], n);
        end = clock();
        time[4] = (double)(end - start);
        // shell sort
        start = clock();
        shell(arr[5], n);
        end = clock();
        time[5] = (double)(end - start);
        cout << n << " ";
        for (int i = 0; i < 6; i++)
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
n B.S S.S I.S H.S Shell.S
1000 3 2 1 3 0 0
2000 18 6 5 3 0 1
3000 34 14 7 5 1 0
4000 69 25 14 5 1 1
5000 98 35 21 7 2 1
6000 137 52 29 8 2 1
7000 190 69 41 10 2 1
8000 269 89 53 11 2 2
9000 320 112 64 13 3 2
10000 410 139 82 15 3 2
*/