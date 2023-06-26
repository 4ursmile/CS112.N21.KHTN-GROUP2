#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define ford(i,b,a) for (int i = b; i>=a; i--)
using namespace std;
int m,n;
vector<vector<int>> trans_arr;
vector<vector<int>> arr;
bool done;
void set_size(vector<vector<int>> &arr, int m, int n)
{
    arr.resize(m);
    for (size_t i = 0; i < m; i++) {
        arr[i].resize(n);
    }
}
bool inside(int x, int y)
{
    return x>0 && y>0 && x<=m && y<=n; 
}
int check(int x, int y)
{
    int total = trans_arr[x][y];
    fort(i, -1, 1)
        fort(j, -1, 1)
            if (i!=0 || j!=0) {
                int xx = x+i, yy = y+j;
                if (inside(xx,yy)) 
                    total-=arr[xx][yy];
            }
    return total;
}
bool process(int i)
{
    for (size_t j = 2; j < i; j++)
       if (inside(i,j)) {
            arr[i][j] = 0;
            int t = check(i-1,j-1);
            if (t != 0 && t!= 1) return false;
            arr[i][j] = t;
        }
    for (size_t j = 2; j < i; j++)
        if (inside(j,i)) {
            arr[j][i] = 0;
            int t = check(j-1,i-1);
            if (t != 0 && t!= 1) return false;
            arr[j][i] = t;
        }
    if (inside(i,i)) {
        arr[i][i] = 0;
        int t = check(i-1,i-1);
        if (t != 0 && t!= 1) return false;
        arr[i][i] = t;
    }
    return true;
}
    
void LastCheck(int k)
{
    fort(i,1,m)
        if (check(i,n) != 0)
            return;
    fort(i,1,n)
        if (check(m,i) != 0)
            return;
    fort(i, 1, m) {
        fort(j, 1, n)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    exit(0);
}
void BaB(int i) 
{
    if (done) 
        cout << 1 << endl;
    if (i>m && i>n){
        LastCheck(i);
        return;
    }
    if (i==1) {
        arr[i][i] = 0;
        BaB(i+1);
        arr[i][i] = 1;
        BaB(i+1);
        return;
    } 
    for(arr[i][1] = 0; arr[i][1]<=1; arr[i][1]++)
        for(arr[1][i] = 0; arr[1][i]<=1; arr[1][i]++) {
            bool ok = process(i);
            if (inside(i,1) && check(i-1,1)) 
                ok = false;
            if (inside(1,i) && check(1,i-1))
                ok = false;
            if (ok) BaB(i+1); 
        }
}
int main()
{
    //ifstream cin("in.inp");
    done = false;
    cin >> m >> n;
    int mac = max(m,n);
    set_size(trans_arr, mac+2, mac+2);
    set_size(arr, mac+2, mac+2);
    fort(i,1,m)
        fort(j,1,n)
            cin >> trans_arr[i][j];
    BaB(1);
    return 0;
}