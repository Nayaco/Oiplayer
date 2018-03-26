#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int N_V = 100005;
const int N_E = 100005;
int Head[N_V], V[N_E], Next[N_E], deg[N_V], Vis[N_V];
int tot, n;

void init(){
    memset(Head,0,sizeof(Head));
    memset(V,0,sizeof(V));
    memset(Next,0,sizeof(Next));
    memset(deg,0,sizeof(deg));
    tot = 0;n = 0;
}

void add(int a, int b){
    tot++; V[tot] = b; Next[tot] = Head[a];
    Head[a] = tot; deg[b]+=2;
    tot++; V[tot] = a; Next[tot] = Head[b];
    Head[b] = tot; deg[a]+=2;
        
}

void Topsort(){
    for(int i = 1; i <=n; i++)Vis[i] = 0;
    int NN = n;
    priority_queue<int, vector<int>, greater<int> > Q;
    for(int i = 1; i <= n; i++)if(deg[i]==2)Q.push(i);
    while(!Q.empty()){
        int x = Q.top(); Q.pop(); NN--; Vis[x] = 1;
        for(int i = Head[x]; i!=0; i = Next[i]){
            deg[V[i]] -= 2;
            if(deg[V[i]] == 2&&!Vis[V[i]])Q.push(V[i]);
            if(deg[V[i]]>0||(NN == 1 && !Vis[V[i]]))printf("%d ", V[i]);
        }
    }
    printf("\n");
}
int main(){
    ios::sync_with_stdio(false);
    char ch = 0;
    while(ch!=EOF){
        init();
        bool flag = 0, iss = 0;
        int root[100005];
        int x=-1 ,y=0;
        while(x != -1 || iss == 0){
            ch = getchar();
            switch(ch){
                case '(':{
                    root[y] = x;
                    x = y;
                    flag = 1;
                    y = 0;
                    break;
                }
                case ')':{
                    flag = 0;
                    n = max(n, y);
                    //printf("%d%d\n",x,y);
                    if(x)add(x,y);
                    y = x;
                    x = root[x];
                    break;
                }
                default:{
                    if(ch <= '9' && ch > '0'){
                        if(flag) y*=10;y += ch-'0';
                        iss = 1;
                    }
                }
            }
        }
        Topsort();
        ch = getchar();
    }
    
    return 0;
}