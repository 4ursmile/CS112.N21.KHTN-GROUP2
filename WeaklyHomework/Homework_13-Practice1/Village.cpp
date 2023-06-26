#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)

using namespace std;
const ll modulo = 1e9+7;

int Solve(int n, vector<vector<int>>& A, vector<int>& RN ) 
{
    vector<vector<ll>> dp((1<<(n-1)), vector<ll>(n));
    dp[1][0] = 1;
    for (size_t mask = 1; mask < (1<<(n-1)) - 2; mask+=2)
    {
        for (size_t u = 0; u < n-1; u++)
            if (mask & (1<<u))
                for(int v:A[u])
                if (!(mask & (1<<v)) && v < n-1)
                    dp[mask | (1<<v)][v] = (dp[mask | (1<<v)][v] + dp[mask][u])%modulo;
    }
    ll ans = 0;
    for (int u:RN)
        ans = (ans+dp[(1<<(n-1))-1][u]) % modulo;
    return ans;

}
int main() 
{
    ifstream cin("in.inp");
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n);
    vector<int> RN;
    int u,v;
    for(int i = 0; i<m; i++)
    {
        cin >> u >> v;
        A[u-1].push_back(v-1);
        if (v==n)
            RN.push_back(u-1);

    }

    cout << Solve(n, A, RN);
	return 0;
}