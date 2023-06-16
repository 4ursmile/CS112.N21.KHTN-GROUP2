#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> edge_map;
int n, m;
vector<bool> flag;
int e_count;
vector<int> clustes;
edge_map emap;
void DFS(int i)
{
    if (flag[i]) return;
    flag[i] = 1;
    e_count++;
    for (int j : emap[i])
        DFS(j);
}
int main()
{
    n = m = 0;
    cin >> n >> m;
    int a, b;
    emap.resize(n);
    for (size_t i = 0; i < m; i++)
    {
        cin >> a>> b;
        emap[a-1].push_back(b-1);
        emap[b-1].push_back(a-1);
    } 
    flag.resize(n);
    for (int i = 0; i < n; i++)
    {
        e_count = 0;
        if(!flag[i])
        {
            DFS(i);
            clustes.push_back(e_count);
        }
    }
    if (clustes.size()==1)
    {
        cout << 0;
        return 0;
    }
    int d_total = 0;
    int c_size = clustes.size();
    for (size_t i = 0; i < c_size-1; i++)
    {
        for(size_t j = i+1; j < c_size; j++)
            d_total+=clustes[i]*clustes[j];
    }
    cout << d_total;
    return 0;
}