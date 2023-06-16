#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)
#define point pair<int,int>
using namespace std;

int MinTrip(int n, int k, vector<int>& a) 
{
    vector<point> dp(1<<n, make_pair(n,0));

    dp[0] = {0, k};
    for (size_t mask = 1; mask < 1<<n; mask++)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (k-dp[mask & ~(1<<i)].second >= a[i])
            {
                dp[mask] = min(dp[mask], make_pair(dp[mask & ~(1<<i)].first, dp[mask & ~(1<<i)].second + a[i]));
            } else
            {
                dp[mask] = min(dp[mask], make_pair(dp[mask & ~(1<<i)].first + 1, a[i]));
            }
        }
    }
    
    return dp[(1<<n)-1].first;
}
int main() 
{
    //ifstream cin("in.inp");
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(int i = 0; i<n; i++)
            cin >> A[i];
    cout << MinTrip(n, k, A);
	return 0;
}