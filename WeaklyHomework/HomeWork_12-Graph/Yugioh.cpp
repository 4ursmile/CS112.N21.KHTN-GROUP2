#include<iostream>
#include<algorithm>
#include<cstring>
#define fr(a,b,c) for(a=b;a<=c;a++)
using namespace std;

int n,k,sm,re,d[222],a[222][222];

void dfs(int x,int val)
{
    int i;
    d[x]=1;
    fr(i,1,n)
      if (!d[i] && a[x][i]<val) dfs(i,val); 
}

int main()
{
    int i,j;
    cin >> n >> k;
    fr(i,1,n) fr(j,1,n) cin >> a[i][j];
    int l=0,r=32767;
    while (l<=r)
    {
       int m=(l+r)/2;
       memset(d,0,sizeof(d));
       sm=0;
       fr(i,1,n)
         if (!d[i]) dfs(i,m),sm++;
       if (sm>=k)
       {
           re=m; l=m+1;
       }
       else r=m-1;  
    }
    cout << re << endl;
    return 0;
}