#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX(x,y) x>y?x:y
using namespace std;
const int MAX_N = 1005,MAX_M = 100005;
int LEN[MAX_M],V[MAX_M],HEAD[MAX_N],NEXT[MAX_M],VIS[MAX_N],DIST[MAX_N];
int tot,n,m;
void add(int a, int b, int w){tot++;V[tot] = b;NEXT[tot] = HEAD[a];HEAD[a] = tot;LEN[tot] = w;}

bool SPFA(int X){
    queue<int> Q;
    for(int i = 1; i < n + 1; i++){
        DIST[i] = 1<<20;
    }DIST[X] = 0;
    Q.push(X);VIS[X] = 1;
    while(!Q.empty()){
        int k = Q.front();Q.pop();
        for(int i = HEAD[k] ; i; i = NEXT[i]){
            if(DIST[V[i]]>DIST[k]+LEN[i]){
                DIST[V[i]]=DIST[k]+LEN[i];
                if(!(VIS[V[i]]&1)){
                    Q.push(V[i]);
                    VIS[V[i]]++;
                    if(VIS[V[i]]>1000)return 0;
                }
            }
        }
    }
    return 1;
}
int main(){
    
}