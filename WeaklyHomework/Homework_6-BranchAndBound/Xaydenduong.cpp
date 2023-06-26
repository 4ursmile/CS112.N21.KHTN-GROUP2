#include <bits/stdc++.h>
using namespace std;
const int maxR = 2500;
int n, m;
bool canPlace(vector<int>& houses, int radius)
{
    int k = 0;
    for(int i = 0; i < m; i++) 
    {
        int coverd = houses[k] + 2*radius;
        while (k<n && houses[k] <= coverd)
            k++;
        if (k>=n) return 1;
    }

    return 0;
}
int L_search(vector<int>& houses)
{
    for (size_t i = 1; i <= maxR; i++)
    {
        if (canPlace(houses, i)) return i;
    }
    return -1;
}
int main()
{
    n = m = 0;
    cin >> n >> m;
    vector<int> houses(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> houses[i];
    }
    sort(houses.begin(),houses.end());
    cout << L_search(houses);
    return 0;
}