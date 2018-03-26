#include <cstdio>
using namespace std;
const int MAX_N = 1005,MAX_M = 100005;
int LEN[MAX_M], V[MAX_M], HEAD[MAX_N], NEXT[MAX_M], VIS[MAX_N], DIST[MAX_N];
int DNF[MAX_N], LOW[MAX_N], TIME;
int ANS[MAX_N];
int stack[MAX_N], stk_len;
int tot, n, m;
void ADD(int a,int b){...}
void TANJAN_DFS(int x){
    if(DNF[x] == LOW[x]){

    }
    for(int i = HEAD[x]; i; i= NEXT[i]){
        
    }
}