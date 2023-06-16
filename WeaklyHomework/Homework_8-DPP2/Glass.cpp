#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)

using namespace std;

int MinCost(int n, int k, vector<vector<int>>& a) 
{
    vector<ll> dp(pow(2,n)+1, INT_MAX);
    dp[0] = 0;
    ll mincost = INT_MAX;
    for (size_t mask = 0; mask < pow(2,n); mask++)
    {
        for (size_t u = 0; u < n; u++)
        {
            if ((1<<u)&mask)
            {

                for (size_t v = 0; v < n; v++)
                {
                    if (!((1<<v)&mask)) {

                        dp[mask] = min(dp[mask], dp[mask & ~(1<<u)] + a[u][v]);
                        //cout << mask << " " << dp[mask] << " | " << " " << u << " " << v << endl;

                    }

                }
            }   
        }
        if ( n - __popcount(mask) == k){
            mincost = min(mincost, dp[mask]);
        } 
        
    }
    return mincost;
}
int main() 
{
    //ifstream cin("in.inp");
    int n, k;
    cin >> n >> k;
    vector<vector<int>> A(n, vector<int>(n));
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> A[i][j];
    cout << MinCost(n, k, A);
	return 0;
}