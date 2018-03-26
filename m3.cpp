#include<iostream>
#define mod 10007
#define LL long long
using namespace std;
LL num[2010][7000];

int main()
{
    int a, b, k, n, m;
    LL ans = 1;
    cin>>a>>b>>k>>n>>m;
    num[1][1] = num[1][2] = 1;
    for(int i=2; i<=k; i++) 
      for(int j=1; j<=i+1; j++)
        num[i][j] = (num[i-1][j-1]+num[i-1][j])%mod;
    ans = num[k][m+1];
    for(int i=1; i<=n; i++)
      ans = (ans*a) % mod;
    for(int j=1; j<=m; j++)
      ans = (ans*b) % mod;
    cout<<ans;
    return 0;
}