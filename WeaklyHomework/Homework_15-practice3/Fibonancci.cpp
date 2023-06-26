#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)
#define forrange(i,a,b) for(int i = a; i<b; i++)
using namespace std;
const ll modulo = 1e9+7;

struct Matrix
{    
    vector<vector<ll>> matrix;
    Matrix(ll n, ll m)
    {
        matrix = vector<vector<ll>>(n, vector<ll>(m, 0));
    }
    Matrix()
    {
        matrix = {{1,1},{1,0}};
    }
    Matrix(const Matrix& b)
    {
        this->matrix = b.matrix;
    }
    Matrix operator*(const Matrix& b)
    {
        if (this->matrix[0].size() != b.matrix.size())
            return Matrix(0,0);
        Matrix res(this->matrix.size(), b.matrix[0].size());
        forrange(i,0,res.matrix.size())
            forrange(j,0,res.matrix[0].size())
                forrange(k,0,this->matrix[0].size())
                    res.matrix[i][j] = (res.matrix[i][j] + (this->matrix[i][k]*b.matrix[k][j])%modulo)%modulo;
        return res;
    }
    Matrix power(ll n)
    {
        if (n == 1)
            return *this;
        Matrix tmp = power(n/2);
        if (n%2 == 0)
            return tmp*tmp;
        return tmp*tmp*(*this);
    }
};

ll solve(ll n)
{
    if (n==0)
        return 0;
    if (n<3)
        return 1;
    Matrix a;
    Matrix res = a.power(n-1);
    Matrix baseCase(2,1);
    baseCase.matrix[0][0] = 1;
    res = res*baseCase;
    return res.matrix[0][0];
}

int main()
{ 
    //ifstream cin("in.inp");
    ll n;
    cin >> n;
    cout << solve(n) << endl;
	return 0;
}