#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)

using namespace std;

int n, m;
vector<vector<int>> Edges;
vector<int> dp;
int maxSearch(int u)
{
    if (dp[u] > 0) 
        return dp[u];
    dp[u] = 1;

    for(auto v:Edges[u]) {
        dp[u] = max(dp[u], maxSearch(v)+1);
    }
    return dp[u];
}

int main() 
{
    cin >> n >> m;
    Edges.resize(n+1);
    dp.resize(n+1);
    int u,v;
    for (size_t i = 0; i < m; i++)
    {
        cin >> u >> v;
        Edges[u].push_back(v);
    }
    int L = 0;
    fort(i,1,n)
        L = max(L, maxSearch(i));

    cout<< L -1;

	return 0;
}