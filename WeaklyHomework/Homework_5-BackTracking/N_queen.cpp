#include <bits/stdc++.h>

using namespace std;
const int maxn = 100;
int n;
bool column[maxn];
bool diagonal1[2*maxn], diagonal2[2*maxn];
int back_map[maxn];
bool has_sol = false;
void print_sol()
{
    has_sol = true;
    cout << "[";
    for (size_t i = 0; i < n-1; i++)
    {
        cout << "(" << i+1 << ", " << back_map[i]+1 << ") ";
    }
    cout << "(" << n << ", " << back_map[n-1]+1 << ")]\n";
}
void backtracking(int k)
{
    for (size_t i = 0; i < n; i++)
    {
        if (column[i] || diagonal1[k+i] || diagonal2[k-i+n-1]) continue;
        column[i] = diagonal1[k+i] = diagonal2[k-i+n-1] = 1;
        back_map[k] = i;
        if (k == n-1) {
            print_sol();
        }
        else backtracking(k+1);
        column[i] = diagonal1[k+i] = diagonal2[k-i+n-1] = 0;
    }
    
}
int main() {
	//ifstream inf("in.inp");
	cin >> n;
    backtracking(0);
    if (!has_sol) 
        cout << "No solution found.";
	return 0;
}