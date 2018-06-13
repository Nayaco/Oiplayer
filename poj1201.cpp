#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#define t_max(x, y, z) (x>y?(x>z?x:z):(y>z?y:z))
#define INF -1
const int maxv = 51005,
          maxe = 110005;

using namespace std;

int tot;
int v[maxe],
    head[maxv],
    nexte[maxe],
    w[maxe],
    u[maxv];

void add(int s, int t, int weight){
    tot++;
    v[tot] = t;
    nexte[tot] = head[s];
    head[s] = tot;
    w[tot] = weight;
}

void Spfa(int s, int n){
    queue<int> q;
    bool vis[maxv];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++)u[i + 1] = INF;
    q.push(s);
    u[s] = 0;
    vis[s] = 1;
    while(!q.empty()){
        int x = q.front();q.pop();vis[x] = 0;
        for(int i = head[x]; i != 0; i = nexte[i]){
            int k = v[i];
            if(w[i] + u[x] >= u[k]){
                u[k] = w[i] + u[x];
                if(!vis[k]){
                    q.push(k);
                    vis[k] = 1;
                }
            }
        }
    }
    
}


int main(int argc, char const *argv[])
{
    int n, s, t, weight;
    int maxn = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &s, &t, &weight);
        add(s, t + 1 ,weight);
        maxn = max(t + 1, maxn);
    }
    for(int i = 1; i < maxn; i++)add(i, i + 1, 0);
    Spfa(1, maxn);
    printf("%d", u[maxn]);
    //while(1)getchar();
    return 0;
}

/*
6
3 7 3
8 10 3
6 8 1
1 3 1
10 11 1
4 11 8
*/