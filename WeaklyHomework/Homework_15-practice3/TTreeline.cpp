#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)
#define forrange(i,a,b) for(int i = a; i<b; i++)
using namespace std;
const ll modulo = 1e9+7;
typedef vector<vector<ll>> Matrix;
Matrix preprocess(Matrix &A)
{
    Matrix sum(A.size(), vector<ll>(A[0].size(), 0));
    sum[0][0] = A[0][0];
    fort(i,1,A.size()-1)
        sum[i][0] = sum[i-1][0] + A[i][0];
    fort(j,1,A[0].size()-1)
        sum[0][j] = sum[0][j-1] + A[0][j];
    fort(i,1,A.size()-1)
        fort(j,1,A[0].size()-1)
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + A[i][j];
    return sum;
}
ll solve(Matrix &A, ll k)
{
    if (k == 0)
        return 0;
    if (A.size() == 1 && A[0].size() == 1)
        return A[0][0];
    if (A.size()==0)
        return 0;
    Matrix sum = preprocess(A);
    ll maxS = 0;
    int m = A.size(), n = A[0].size();
    forrange(i, k-1, m)
    {
        forrange(j,k-1, n)
        {
            ll tmp = sum[i][j];
            if (i-k >= 0)
                tmp -= sum[i-k][j];
            if (j-k >= 0)
                tmp -= sum[i][j-k];
            if (i-k >= 0 && j-k >= 0)
                tmp += sum[i-k][j-k];
            maxS = max(maxS, tmp);
        }
    }
    return maxS;
}

int main()
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("in.inp");
    ll m,n,k;
    cin >> m >> n >> k;
    Matrix a(m, vector<ll>(n,0));
    fort(i,0,m-1)
        fort(j,0,n-1)
            cin >> a[i][j];
    cout << solve(a, k);
	return 0;
}