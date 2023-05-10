#include <bits/stdc++.h>
using namespace std;

int coinexchange(vector<int> &coins, int total)
{
    sort(coins.begin(), coins.end());
    int ans = 0;
    int index = coins.size() - 1;
    while (total && index >= 0)
    {
        if (total - coins[index] >= 0)
        {
            ans += total / coins[index];
            total = total % coins[index];
        }
        index--;
    }
    return ans;
}

int main()
{
    vector<int> coins;
    int n, c;
    cout << "enter the number of coins and total money -> ";
    cin >> n >> c;
    cout << "enter all coins" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }
    cout << "total coins required -> " << coinexchange(coins, c) << endl;
    return 0;
}

// output
/*
enter the number of coins and total money -> 4 23
enter all coins
2 4 6 17
total coins required -> 2
PS C:\Users\SHASHI RAJ\Desktop\4th sem\algo assign\assignment6 algolab>
*/