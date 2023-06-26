#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#define max_int 101
using namespace std;

string ABC = "ABC";
string arr;
string Best;
int n;
int MinC;
vector<int> T(max_int);
bool issame(int i, int l)
{
    int j = i-l;
    for (size_t k = 0; k < l; k++)
        if (arr[i-k]!=arr[j-k])
            return false;
    return true;
}
bool check(int i)
{
    for (size_t k = 1; k <= i/2; k++)
    {
        if (issame(i,k))
        {
            return false;
        }
    }
    return true;
}
void BaB(int i) 
{
    for(char k:ABC) {
        arr[i] = k;
        if (check(i)) {
            if (k=='C') 
                T[i]=T[i-1]+1;
            else
                T[i] = T[i-1];
            if (T[i] + (n-i)/4 < MinC){
                if (i>=n) {
                    MinC = T[n];
                    Best = arr;
                } else
                    BaB(i+1);
            }

        }
    }
}
int main()
{
    cin >> n;
    arr.resize(n+1);
    MinC = INT_MAX;
    fill(arr.begin(), arr.end(), '.');
    BaB(1);
    cout << Best.substr(1,n);

}