#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)

using namespace std;
template <typename T>
void resize(vector<vector<T>>& vec, int m, int n)
{
    vec.resize(m);
    for (size_t i = 0; i < m; i++)
        vec[i].resize(n);
}
int DP(string &a, string &b)
{
    vector<int> L1(b.size()+1);
    vector<int> L2(b.size()+1);
    fort(i,1,a.size()) {
        fort(j,1,b.size()) 
            if (a[i-1] == b[j-1])
                L2[j] = L1[j-1] + 1;
            else
                L2[j] = max(L1[j], L2[j-1]);
        swap(L1,L2);
    }   
    return L1[b.size()];
}

int main() 
{
    //ifstream cin("in.inp");
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << DP(a,b);
	return 0;
}