#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 300005;
int v[maxn], head[maxn], next[maxn], tail[maxn], num[maxn];
int tot;

void push(int a, int w)
{
    tot++;
    v[tot] = w;
    next[tot] = head[a];
    head[a] = tot;
    if(num[a]==0)tail[a] = tot;
    num[a]++;
}

int pop(int a)
{
    if(num[a] == 0)return -1;
    int t = v[head[a]];
    head[a] = next[head[a]];
    num[a]--;
    return t;
}

void merge(int a, int b)
{
    if(num[b] == 0)return;
    if(num[a] == 0)tail[a] = tail[b];
    next[tail[b]] = head[a];
    head[a] = head[b];
    num[a] += num[b];
    num[b] = 0;
}

int main()
{
    //freopen("in1.in", "r", stdin);
    //freopen("out1.out", "w", stdout);
    int T, n, m, q;
    int x, y, z;
    scanf("%d", &T);
    for(int re = 0; re < T; re++)
    {
        memset(num, 0, sizeof(num));
        scanf("%d%d", &n, &q);
        for(int i = 0; i < q; i++)
        {
            scanf("%d",&x);
            switch(x)
            {
                case 1:
                {
                    scanf("%d%d", &y, &z);
                    push(y, z);
                    break;
                }
                case 2:
                {
                    scanf("%d", &y);
                    int ans = pop(y);
                    if(ans > 0)printf("%d\n", ans);
                        else printf("EMPTY\n");
                    break;
                }
                case 3:{
                    scanf("%d%d", &y, &z);
                    merge(y, z);
                    break;
                }
            }
        }
    }
    return 0;
}

/*
2
2 15
1 1 10
1 1 11
1 2 12
1 2 13
3 1 2
1 2 14
2 1
2 1
2 1
2 1
2 1
3 2 1
2 2
2 2
2 2
3 7
3 1 2
3 1 3
3 2 1
2 1
2 2
2 3
2 3
*/