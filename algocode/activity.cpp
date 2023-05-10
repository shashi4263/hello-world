#include <bits/stdc++.h>
using namespace std;

void print(vector<pair<int, int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
}

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

void job(vector<pair<int, int>> &t)
{
    sort(t.begin(), t.end(), cmp); // sort in non decreasing order
    // print(t);
    vector<pair<int, int>> v; // empty vectors pair
    int ans = 0;
    int index = t.size() - 1;
    // cout<<index<<endl;
    v.push_back(t[0]);
    ans++;
    int current = t[0].second; // initialize
    for (int i = 1; i < t.size(); i++)
    {
        if (t[i].first >= current)
        {
            ans++;
            current = t[i].second;
            v.push_back(t[i]);
        }
    }
    cout << "jobs no. of job can performed are ->" << ans << "\nthey are -> " << endl;
    print(v);
}

int main()
{
    vector<pair<int, int>> t;
    int n, c;
    cout << "enter the total number of activities" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter " << (i + 1) << "th starting and finishing time -> ";
        int x, y;
        cin >> x >> y;
        pair<int, int> p = {x, y};
        t.push_back(p);
    }
    job(t);
    return 0;
}

// output
/*
enter the total number of activities
4
enter 1th starting and finishing time -> 2 4
enter 2th starting and finishing time -> 3 6
enter 3th starting and finishing time -> 5 7
enter 4th starting and finishing time -> 6 4
jobs no. of job can performed are ->3
they are ->
2 4
6 4
5 7

*/