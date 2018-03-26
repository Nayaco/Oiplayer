#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 100,MAX_M = 100;
struct NODE{
    int L,R,U,D;
    NODE(){}
    ~NODE(){}
};
int COL[MAX_N],ROW[MAX_N];
NODE MAP[MAX_N];
int NUM;
int ANS[MAX_N], LEN;
int H[MAX_N];
int S[MAX_N];
int n;
void ADD(int col, int row, int id){
    COL[id] = col;
    ROW[id] = row;
    MAP[id].U = col;MAP[id].D = MAP[col].D;
    MAP[MAP[col].D].U = id;MAP[col].D = id;
    if(H[row] == 0){
        H[row] =  MAP[id].R = MAP[id].L = id;
        return;
    }
    MAP[id].R = H[row];
    MAP[id].L = MAP[H[row]].L;
    MAP[MAP[H[row]].L].R = id;
    MAP[H[row]].L = id;
    H[row] = id;
    return;
}

void DELETE(int col){
    MAP[MAP[col].R].L = MAP[col].L;
    MAP[MAP[col].L].R = MAP[col].R;
    for(int i = MAP[col].D; i != col; i = MAP[i].D){
        for(int j = MAP[i].R; j != i; j = MAP[j].R){
            MAP[MAP[j].D].U = MAP[j].U;
            MAP[MAP[j].U].D = MAP[j].D;
            S[COL[j]]--;
        }
    }
    return;
}

void REUSE(int col){
    MAP[MAP[col].R].L = col;
    MAP[MAP[col].L].R = col;
    for(int i = MAP[col].D; i != col; i = MAP[i].D){
        for(int j = MAP[i].R; j != i; j = MAP[j].R){
            MAP[MAP[j].D].U = j;
            MAP[MAP[j].U].D = j;
            S[COL[j]]++;
        }
    }
    return;
}

bool DANCE(int i){
    if(MAP[0].R == 0){
        return 1;
    }
    DELETE(COL[i]);
    for(int j = MAP[i].D; j != i; j = MAP[j].D){
        for(int k = MAP[j].R; k != j; k = MAP[k].R)DELETE(COL[k]);
        if(DANCE(MAP[0].R)){
            ANS[++LEN] = j;
            for(int k = MAP[j].R; k != j; k = MAP[k].R)DELETE(COL[k]);
            return 1;
        }
        for(int k = MAP[j].R; k != j; k = MAP[k].R)DELETE(COL[k]);
    }
    REUSE(i);
    //for(int i=1;i<=NUM;i++)cout<<MAP[i].U<<' '<<MAP[i].D<<' '<<MAP[i].L<<' '<<MAP[i].R<<endl;
    //    printf("------------------\n");
    return 0;
}
void init(int n){
    MAP[0].R = 1;MAP[0].L = n;
    MAP[0].U = 0;MAP[0].D = 0;
    for(int i = 0; i < n-1; i++){
        MAP[i+1].U = MAP[i+1].D = i+1;
        MAP[i+1].L = i;MAP[i+1].R = i+2;
        COL[i+1] = i+1;
    }
    for(int i = 1; i < n+1; i++)H[i] = 0;
    MAP[n].L = n-1;MAP[n].R = 0;
    MAP[n].U = n;MAP[n].D = n;
    COL[n] = n;
    NUM = n;
}
int main(){
    scanf("%d",&n);
    init(n);
    for(int i = 0; i<n; i++){
        ADD(i+1,i+1,++NUM);
        if(i<n-1)ADD(i+2,i+1,++NUM);
            else ADD(1,i+1,++NUM);
    }
    
    if(DANCE(1))printf("yes\n");
        else printf("no\n");
    for(int i = 1; i <= LEN; i++){
        printf("%d ",ROW[ANS[i]]);
    }
    getchar();
    getchar();
    return 0;    
}