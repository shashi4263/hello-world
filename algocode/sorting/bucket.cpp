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
void sort(vector<int> &v, int n)
{
    vector<int> b[n];
    for (int i = 0; i < v.size(); i++)
    {
        int bi = v[i] / 100;
        b[bi].push_back(v[i]);
    }
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            v[index++] = b[i][j];
}
int main()
{
    int t = 9;
    int n = 1000;
    cout << "N\tA.C \tB.C\tW.C\n";
    while (t--)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x = rand() % n + 1;
            v.push_back(x);
        }
        // print(v);
        clock_t start, end;
        start = clock();
        sort(v, 100);
        end = clock();
        // print(v);
        cout << n << "\t" << (double)(end - start) << "\t";
        // best case assecnding
        start = clock();
        sort(v, 100);
        end = clock();
        cout << (double)(end - start) << "\t";
        // worst case desecnding
        sort(v.begin(), v.end(), greater<int>());
        start = clock();
        sort(v, 100);
        end = clock();
        cout << (double)(end - start) << endl;
        n += 1000;
    }
}
/*
N	A.C 	B.C	W.C
1000	341	237	291
2000	690	480	474
3000	1016	693	709
4000	1309	960	955
5000	1627	1115	1221
6000	1998	1317	1436
7000	2245	1606	1638
8000	2599	1853	1916
9000	2950	2065	2193*/