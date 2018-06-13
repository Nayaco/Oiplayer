#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn = 10005;
const int maxe = 1000005;
const long INF = ~(1<<31);
int tot;
int n;
int v[maxe], head[maxn], nexte[maxe], w[maxe], u[maxn];
void add(int a, int b, int len){
    tot++;
    v[tot] = b; nexte[tot] = head[a];
    head[a] = tot; w[tot] = len;
}
bool spfa(int s){
    queue<int> q;
    int vis[maxn];
    int nums[maxn];
    memset(vis, 0, sizeof(vis));
    memset(nums, 0, sizeof(nums));
    for(int i = 0; i < n; i++)u[i+1] = INF;
    u[s] = 0;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for(int i = head[x]; i != 0; i = nexte[i]){
            if(w[i] + u[x] < u[v[i]]){
                vis[v[i]] = 1;
                q.push(v[i]);
                u[v[i]] = w[i] + u[x];
                nums[v[i]]++;
                if(nums[v[i]] > 2*n){
                    return 0;
                }
            }
        }
    }
    return 1;
}


int main(int argc, char const *argv[])
{
    int m;
    int x, y;
    int s;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m ; i++){}
    return 0;
}
