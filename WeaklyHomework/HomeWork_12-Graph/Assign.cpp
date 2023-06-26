#include<bits/stdc++.h>
using namespace std;

#define mset(a,v) memset(a, v, sizeof a)
const int N = 200, INF = 1e9;
int g[N][N], n, my[N];
bool vy[N];

void enter() {
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) 
            cin >> g[i][j];
}

bool dfs(int s, int lim) {
    for(int u = 0; u < n; ++u) if(!vy[u] && g[s][u] <= lim) {
        vy[u] = true;
        if(my[u] == -1 || dfs(my[u], lim)) return my[u] = s, true;
    }
    return false;
}

int solve() {
    int l = 0, h = INF;
    while(l < h) {
        mset(my, -1); int mid = (l + h) / 2; bool ok = true;
        for(int i = 0; mset(vy, 0), i < n && ok; ++i) ok &= dfs(i, mid);
        if(ok) h = mid; else l = mid + 1;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    enter();
    cout << solve() << endl;
    return 0;
}