#include <bits/stdc++.h>
using namespace std;
int parttion(vector<int> &v, int lb, int ub)
{
    int key = v[ub];
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
void qs(vector<int> &v, int lb, int ub)
{
    if (lb < ub)
    {
        int q = parttion(v, lb, ub);
        qs(v, lb, q - 1);
        qs(v, q + 1, ub);
    }
}
int main()
{
    int t = 10;
    int n = 1000;
    cout << "N\tA.C \tW.C\tW.C\n";
    while (t--)
    {
        vector<int> v;
        for (int i = 0;
             i < n; i++)
        {
            int no = rand() % n + 1;
            v.push_back(no);
        }
        cout << endl;
        clock_t start, end;
        start = clock();
        qs(v, 0, n - 1);
        end = clock();
        cout << n << "\t" << (double)(end - start) << "\t";
        // worst case assecnding
        start = clock();
        qs(v, 0, n - 1);
        end = clock();
        cout << (double)(end - start) << "\t";
        // worst case desecnding
        sort(v.begin(), v.end(), greater<int>());
        start = clock();
        qs(v, 0, n - 1);
        end = clock();
        cout << (double)(end - start) << endl;
        n += 1000;
    }
    return 0;
}
// output
/*
N       A.C     W.C     W.C

1000    290     14321   4831

2000    634     40627   23319

3000    1025    108294  52685

4000    1120    205354  94626

5000    1847    334116  143212

6000    2079    466042  208544

7000    2555    638346  228045

8000    2273    592423  245438

9000    2608    734367  317157

10000   2819    906671  384306
*/