#include <cstdio>
using namespace std;
#define LL long long
LL n, m;
LL ans;
int main()
{
    while(1){
        scanf("%lld%lld",&n,&m);
        if(n == 0 && m == 0)break;
        if(n >= m/2){
            ans = m / 2;
            printf("%lld\n", ans);
        }else{
            ans = n + (m - 2 * n) / 4;
            printf("%lld\n", ans);
        }
    }
    return 0;
}