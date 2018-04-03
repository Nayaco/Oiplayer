#include <cstdio>
using namespace std;
const int MAX_N = 10000, MAX_M = 30000;
int head[MAX_N], next[MAX_N], v[MAX_M], cap[MAX_M], dep[MAX_N], f[MAX_M];
int tot, n, m;
void add(int a, int b, int c){
    tot++;v[tot] = b;
    next[tot] = head[a];head[a] = tot;cap[tot] = c;f[tot] = 0;
    tot++;v[tot] = a;
    next[tot] = head[b];head[b] = tot;cap[tot] = 0;f[tot] = 0;
}
int main(){
    return 0;
}