#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
const int NV = 10005, NE = 100005; 
int v[NE], head[NV], _next[NE], indeg[NV];
int n, m, tot = 0, num = 0;
int ans[NV];
void add(int a, int b){
    v[++tot] = b;_next[tot] = head[a]; head[a] = tot; indeg[b]++;
}

void topsort(){
    queue<int> q;
    for(int i = 1; i < n + 1; i++){
        if(indeg[i] == 0)q.push(i);
    }
    while(!q.empty()){
        int x = q.front();q.pop();
        ans[num++] = x;
        for(int i = head[x]; i != 0; i = _next[i]){
            indeg[v[i]] --;
            if(indeg[v[i]] == 0){
                q.push(v[i]);
            }
        }
    }
    return;
}
int main(){
    scanf("%d%d", &n, &m);
    int j, k;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &j, &k);
        add(j, k);
    }
    topsort();
    for(int i = 0; i < n; i++)printf("%d", ans[i]);
    while(1)getchar();
    return 0;
}