#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void sort(vector<int> &v, int m)
{
    vector<int> f(m + 1, 0);
    // frequency table
    for (int i = 0; i < v.size(); i++)
    {
        f[v[i]]++;
    }
    // cf table
    for (int i = 1; i <= m; i++)
    {
        f[i] += f[i - 1];
    }
    // sorting
    vector<int> b(v.size() + 1, 0);
    for (int i = v.size(); i >= 0; i--)
    {
        b[f[v[i]]--] = v[i];
    }
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = b[i + 1];
    }
}
int main()
{
    int t = 10;
    int n = 1000;
    cout << "N\tA.C \tB.C\tW.C\n";
    while (t--)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x = rand() % 25 + 1;
            v.push_back(x);
        }
        clock_t start, end;
        start = clock();
        sort(v, 25);
        end = clock();
        cout << n << "\t" << (double)(end - start) << "\t";
        // best case assecnding
        start = clock();
        sort(v, 25);
        end = clock();
        cout << (double)(end - start) << "\t";
        // worst case desecnding
        sort(v.begin(), v.end(), greater<int>());
        start = clock();
        sort(v, 25);
        end = clock();
        cout << (double)(end - start) << endl;
        n += 1000;
    }
}

// output
/*
N	A.C 	B.C	W.C
1000	54	48	53
2000	99	93	93
3000	152	126	137
4000	205	182	189
5000	231	240	217
6000	276	264	273
7000	314	300	315
8000	387	349	375
9000	417	390	417
10000	470	479	472
*/