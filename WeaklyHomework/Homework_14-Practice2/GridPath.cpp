#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)
using namespace std;
const ll modulo = 3;
int totalSum = 0;
int step = 0;
pair<int, int> Direction[] {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char DirectionChar[] {'U', 'D', 'L', 'R'};
void Solve(int x, int y, int step , vector<vector<bool>> &check, string &targetPath)
{
  if (x == 7 && y == 1)
  {
    if (step == 48)
      totalSum++;
    return;
  }  
  if (step == 48)
    return;
  if (check[x-1][y]&& check[x+1][y])
    if (check[x][y-1] == check[x][y+1])
        return;
  if (check[x][y-1]&& check[x][y+1])
    if (check[x-1][y] == check[x+1][y])
        return;
  for (int i = 0; i < 4; i++)
  {
    int nextX = x + Direction[i].first;
    int nextY = y + Direction[i].second;
    if (check[nextX][nextY] == 0)
    {
      check[nextX][nextY] = 1;
      if (targetPath[step] == '?' || DirectionChar[i] == targetPath[step])
        Solve(nextX, nextY, step+1, check, targetPath);
      check[nextX][nextY] = 0;
    }
  }
}
int main()
{
  ifstream cin("in.inp");
  string targetPath;
  vector<char> path(48, '?'); 
  cin >> targetPath;
  vector<vector<bool>> check(9, vector<bool>(9,0));
  fort(i,0,8)
    check[0][i] = check[8][i] = check[i][0] = check[i][8] = 1;
  check[1][1] = 1;
  Solve(1,1, 0, check, targetPath);
  std::cout << totalSum;
	return 0;
}