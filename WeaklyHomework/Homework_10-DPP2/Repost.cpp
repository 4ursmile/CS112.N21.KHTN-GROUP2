#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)

using namespace std;

void to_lower(string &a)
{
    std::transform(a.begin(), a.end(), a.begin(), [](unsigned char k) {return tolower(k);});
}

int main() 
{
    //ifstream cin("in.inp");
    string a, b,c;
    map<string, int> F;
    F["polycarp"] = 1;
    int n;
    cin >> n;
    int res = 0;
    fort(i,1,n)
    {
        cin >> a >> b >> c;
        to_lower(a);
        to_lower(c);
        F[a] = F[c] + 1;
        res = max(res, F[a]);
    }
    cout << res;

	return 0;
}