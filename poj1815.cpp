#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define INF 2147483647
#define max(x, y) (x>y?x:y)
#define min(x,y) (x>y?y:x)
using namespace std;
const int maxn = 2005;
const int maxm = 1000005;

int Vis[maxn], v[maxm], Head[maxn], Next[maxn], Dep[maxn], Flow[maxm], Cap[maxm];
int tot, n, m, s, t;

void Add(int a, int b, int _Cap)
{
    v[++tot] = b;Next[tot] = Head[a];Head[a] = tot;Cap[tot] = _Cap;Flow[tot] = 0;
    v[++tot] = a;Next[tot] = Head[b];Head[b] = tot;Cap[tot] = 0;Flow[tot] = 0;
}

int Bfs(int s, int t)
{
    memset(Vis, 0 ,sizeof(Vis));
    queue<int> Q;
    Q.push(s);
    Dep[s] = 0;
    while(!Q.empty()){
        int _x = Q.front();
        Q.pop();
        for(int i = Head[_x]; i > 0; i = Next[i]){
            if(Flow[i]>Cap[i]&&!Vis[v[i]]){
                Dep[v[i]] = Dep[_x] + 1;
                Vis[v[i]] = 1;
                Q.push(v[i]);
            }
        }
    }
    return Vis[t];
}

int Dfs(int u, int t, int a)
{
    if(u == t){
        return a;
    }
    int _l = a, fl = 0;
    for(int i = Head[u]; i >= 0; i = Next[i]){
        if(Dep[v[i]]==Dep[u]+1){
            int f = Dfs(v[i], t, min(_l, Cap[i]));
            if(f > 0){
                Flow[i]+=f;
                if(Cap[i] == 0)Flow[i-1] -= f;
                else Flow[i+1] -= f;
                fl+=f;
                _l -= f;
                if(_l == 0)break;
            }
        }
    }
    return fl;
}

int dinic(int s, int t)
{
    int fl = 0;
    while(Bfs(s, t)){
        fl += Dfs(s, t, INF);
    }
    return fl;
}

int main()
{
    int temp;
    scanf("%d%d%d", &n, &s, &t);
    for(int i = 0; i < n; i++)Add(i+1, i+1+n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &temp);
            if(temp && i != j){
                Add(i+1, j+1+n, 1);
                if(i+1 == s && j+1 == t){
                    printf("NO ANSWER!\n");
                    return 0;
                }
            }
        }
    }
    int _Ans = dinic(s, t);
    printf("%d", );
    return 0;
}