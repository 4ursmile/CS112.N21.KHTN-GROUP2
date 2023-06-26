#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll modulo = 1e9+7;

int S, n;
int DP(vector<vector<int>> &f, int n, int s)
{   
    if (n==s) return 1;
    if (s>n) return 0;
    if (n==0 || s==0) return 0;
    if (f[n][s]>=0) return f[n][s];
    return f[n][s] = (DP(f,n-1,s-1) + DP(f,n,s*2))%modulo;
}
int main() 
{
    cin >> n >> S;
    vector<vector<int>> f(n+1, vector<int>(n+1,-1));
    cout << DP(f, n, S);
	return 0;
}