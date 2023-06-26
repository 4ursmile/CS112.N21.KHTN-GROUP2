#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)
using namespace std;
const ll modulo = 3;
  
int nCrModpDP(int n, int r, int p) {
  // The array C is going to store last row of
  // pascal triangle at the end. And last entry
  // of last row is nCr
  int C[r + 1];
  memset(C, 0, sizeof(C));

  C[0] = 1; // Top row of Pascal Triangle

  // One by constructs remaining rows of Pascal
  // Triangle from top to bottom
  for (int i = 1; i <= n; i++) {
    // Fill entries of current row using previous
    // row values
    for (int j = min(i, r); j > 0; j--)

      // nCj = (n-1)Cj + (n-1)C(j-1);
      C[j] = (C[j] + C[j - 1]) % p;
  }
  return C[r];
}

// Lucas Theorem based function that returns nCr % p
// This function works like decimal to binary conversion
// recursive function.  First we compute last digits of
// n and r in base p, then recur for remaining digits
int nCrModpLucas(int n, int r, int p) {
  // Base case
  if (r == 0)
    return 1;

  // Compute last digits of n and r in base p
  int ni = n % p, ri = r % p;

  // Compute result for last digits computed above, and
  // for remaining digits.  Multiply the two results and
  // compute the result of multiplication in modulo p.
  return (nCrModpLucas(n / p, r / p, p) * // Last digits of n and r
          nCrModpDP(ni, ri, p)) %
         p; // Remaining digits
}

int Solve(int n, vector<int> A)
{
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum =(sum + (A[i]*nCrModpLucas(n-1,i-1,modulo))%modulo)%modulo;
    }
    sum = n%2 == 0?(-sum)%3+3:sum%3;
    return sum%3;
}
int main()
{
    ifstream cin("in.inp");
    int n, m;
    cin >> n;
    vector<int> A(1);
    map<char, int> Dic;
    Dic['R'] = 0;
    Dic['W'] = 1;
    Dic['B'] = 2;
    vector<char> ReDic {'R', 'W', 'B'};
    char c;
    for(int i = 0; i<n; i++)
    {
        cin >> c;
        A.push_back(Dic[c]);
    }
    std::cout << ReDic[Solve(n, A)];
	return 0;
}