#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;
const int maxn = 2005;
int Pa[maxn], Pb[maxn];
LL F[maxn][maxn];
int Prea[maxn], Preb[maxn];
int n, m;
int k1, k2 , c;
LL ans;

LL max(LL x, LL y)
{
    return (x>y?x:y);
}

void init()
{
    ans = 0;
    sort(Pa, Pa + n);
    sort(Pb, Pb + m);
    Prea[0] = 0;
    Preb[0] = 0;
    F[0][0] = 0;
    for(int j = 1; j <= n; j++)
    {
        Prea[j] = Prea[j - 1] + Pa[j - 1];
    }
    for(int j = 1; j <= n && Prea[j] <= c; j++)
    {
        LL temp = c - Prea[j];
        F[j][0] = F[j - 1][0] + temp * k1;
        ans = max(ans, F[j][0]);
    }

    for(int j = 1; j <= m; j++)
    {
        Preb[j] = Preb[j - 1] + Pb[j - 1];
    }
    for(int j = 1; j <= m && Preb[j] <= c; j++)
    {
        LL temp = c - Preb[j];
        F[0][j] = F[0][j - 1] + temp * k2;
        ans = max(ans, F[0][j]);
    }
}

void DP(){
    for(int i = 1; i <= n && Prea[i] <= c; i++)
    {
        for(int j = 1; j <= m && Prea[i] + Preb[j] <= c; j++)
        {
            LL temp = c - Prea[i] - Preb[j];
            F[i][j] = max(F[i - 1][j] + temp * k1, F[i][j - 1] + temp * k2);
            ans = max(ans, F[i][j]);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int re = 0; re < T; re++)
    {
        scanf("%d%d%d", &k1, &k2, &c);
        scanf("%d%d", &n, &m);
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &Pa[j]);
        }
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &Pb[j]);
        }
        init();
        DP();
        printf("%lld\n", ans);
    }
    return 0;
}
/*
2
999999 999998 999999
2 3
1 999999
1 999996 999997
*/