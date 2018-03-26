#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define LL long long
using namespace std;
const int N_V = 205;
int Map[N_V], Len[N_V], PRI[N_V], TIMES[N_V];
bool Vis[N_V], ISP[N_V];
int N, num, tot;
LL minpb;

void Prime(){
    memset(ISP,0,sizeof(ISP));
    num = 0;
    for(int i =2; i<N_V; i++){
        if(!ISP[i])PRI[++num] = i;
        for(int j = 1; j<num+1;j++){
            ISP[PRI[j]*i] = 1;
            if(!(i%num))break;
        }
    }
    return;
}

void init(){
    tot = 0;
    for(int i = 1; i < N+1; i++){
        int k = i,len = 0;
        for(;!Vis[k];len++)k = Map[k];
        if(len){tot++;Len[tot] = len;}
    }
    return;
}

int main(){
    init();
    scanf("%d",&N);
    char str[N_V];
    for(int i = 1; i < N+1; i++)scanf("%d",&Map[i]);
    init();
    
    for(int i = 1; i < tot+1; i++){
        for(int j = 1; j < num+1&&Len[i]; j++){
            int k = 0;
            while()
        }
    }
    for(int i = 0;;){
        scanf("%d",)
        if(i>0){
            gets_s(str,N_V-1);
        }else{
            break;
        }
    }
} 