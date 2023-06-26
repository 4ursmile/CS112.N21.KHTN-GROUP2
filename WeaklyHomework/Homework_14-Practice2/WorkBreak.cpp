#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)
#define forrange(i,a,b) for(int i = a; i<b; i++)
using namespace std;
bool Solve(string &s, vector<string> wordDict)
{
  int n = s.size();
  vector<bool> dp(n, 0);
  dp[0] = 1;
  forrange(i,0,n-1)
    for(auto word: wordDict)
    {
      int len = word.size();
      if (i + len <= n && s.substr(i+1, len) == word)
        dp[i+len] = dp[i+len] || dp[i];
    }
  return dp[n-1];
}
int main()
{
  //ifstream cin("in.inp");
  string s;
  cin >> s;
  s = " " + s;
  int n;
  cin >> n;
  vector<string> wordDict(n);
  forrange(i,0,n)
  {
    cin >> wordDict[i];
  }
  std::cout << boolalpha << Solve(s, wordDict);
	return 0;
}