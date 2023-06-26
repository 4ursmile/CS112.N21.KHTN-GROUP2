#include <bits/stdc++.h>

using namespace std;
const int maxn = 100;
int n;
int arr[maxn];
int target_sum;
vector<int> sol;
int current_sum = 0;
void print_sol()
{
    for(int k:sol)
    {
        cout << k << " ";
    }
    cout << "\n";
}
void backtracking(int k, int pi)
{
    for (size_t i = pi+1; i < n; i++)
    {
        if (current_sum+arr[i] > target_sum) continue;
        current_sum += arr[i];
        sol.push_back(arr[i]);
        if(current_sum == target_sum) {
            print_sol();
        }
        else backtracking(k+1, i);
        sol.pop_back();
        current_sum-=arr[i];
    }
}
int main() {
	//ifstream cin("in.inp");
	cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> target_sum;
    current_sum = 0;
    backtracking(0, -1);
	return 0;
}