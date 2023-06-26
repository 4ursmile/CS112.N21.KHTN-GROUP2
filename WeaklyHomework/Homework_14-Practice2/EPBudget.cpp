#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)
#define forrange(i,a,b) for(int i = a; i<b; i++)
using namespace std;

int Solve(vector<vector<int>> A, vector<int> Nodes)
{
  int n = A.size();
  int k = Nodes.size();
  forrange(i,0,n)
    forrange(u,0,n)
      forrange(v,0,n)
        A[u][v] = min(A[u][v], A[u][i] + A[i][v]);
  vector<vector<int>> dp(1<<(k), vector<int>((k), INT_MAX));
  dp[1][0] = 0;
  for( int mask=1; mask < 1<<k; mask++)
    forrange(u, 0, k)
      if (mask & (1<<u) && dp[mask][u] != INT_MAX)
        forrange(v,0,k)
          if (!(mask & (1<<v)))
            dp[mask | (1<<v)][v] = min(dp[mask | (1<<v)][v], dp[mask][u] + A[Nodes[u]][Nodes[v]]);
  int res = INT_MAX;
  forrange(i,0,k)
  {
    res = min(res, dp[(1<<k)-1][i]);
  }
  return res;

}
int main()
{ 
  ifstream cin("in.inp");
  int n, k;
  cin >> n >> k;
  vector<vector<int>> A(n, vector<int>(n,0));
  forrange(i,0,n)
    forrange(j,0,n) {
      cin >> A[i][j];
    }
  vector<int> Nodes(k+1);
  fort(i,1,k) {
    cin >> Nodes[i];
    Nodes[i]--;
  }
  std::cout << Solve(A, Nodes);
	return 0;
}