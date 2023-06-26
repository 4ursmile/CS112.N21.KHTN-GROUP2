#include<cstring>
#include<queue>
#include<iostream>
using namespace std;

const int N = 1e5;
long long d[N], h;
int a, b, c, INF;

void enter() {
    cin >> h >> a >> b >> c;
}

void solve() {
    memset(d, 0x3f, sizeof d);
    d[0] = 0;
    priority_queue<pair<long long, int> > q;
    q.push(make_pair(0, 0));
    while(!q.empty()) {
        long long du = -q.top().first;
        int u = q.top().second; q.pop();
        if(d[(u + a) % c] > du + a) {
            d[(u + a) % c] = du + a;
            q.push(make_pair(-d[(u + a) % c], (u + a) % c));
        }
        if(d[(u + b) % c] > du + b) {
            d[(u + b) % c] = du + b;
            q.push(make_pair(-d[(u + b) % c], (u + b) % c));
        }
    }
}

void print() {
    long long res = 0;
    for(int u = 0; u < c; ++u) {
        if(d[u] >= h) continue;
        res += (h - d[u] - 1) / c + 1;
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    enter();
    solve();
    print();
    return 0;
}