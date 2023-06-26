#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)
#define forrange(i,a,b) for(int i = a; i<b; i++)
using namespace std;
const ll modulo = 1e9+7;
typedef vector<int> Array;

bool CheckExtreme(Array &A, ll k)
{
    if (k >= A.size()-2)
        return false;
    if (k <= 1)
        return false;
    return (A[k] > A[k-1] && A[k] > A[k+1]) || (A[k] < A[k-1] && A[k] < A[k+1]);
}
void TransactionChange(Array &A,int &NOfExtreme,char Type, ll k, ll value, int &outN)
{
    ll Tmp = A[k];
    if (Type == 'P')
        Tmp = value;
    int before = CheckExtreme(A, k-1) + CheckExtreme(A, k) + CheckExtreme(A, k+1);
    A[k] = value;
    int after = CheckExtreme(A, k-1) + CheckExtreme(A, k) + CheckExtreme(A, k+1);
    A[k] = Tmp;
    outN = NOfExtreme+(after-before);
    if (Type == 'P')
        NOfExtreme += (after-before);
}
int main()
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    Array a(n+2);
    fort(i,1,n)
        cin >> a[i];
    int count_extreme = 0;
    fort(i,1,n)
        count_extreme += CheckExtreme(a, i);
    fort(i,1,m)
    {
        char type;
        ll k, value;
        int outN = 0;
        cin >> type >> k >> value;
        TransactionChange(a, count_extreme,type, k, value, outN);
        cout << outN << '\n';
    }
	return 0;
}