#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
const int N = 300005;
int v[N],w[N];
int n,m;
long long S;
long long preW[N],preV[N];
int qu[N][2];
long long ans,sumer;
long long sum(int W){
    memset(preW,0,sizeof(preW));
    memset(preV,0,sizeof(preV));
    for(int i = 1; i <= n;i++)
        if(w[i]>=W){preW[i] = preW[i-1]+1;preV[i] = preV[i-1]+v[i];}
            else{preW[i] = preW[i-1];preV[i] = preV[i-1];}
    long long sum_y = 0;
    for(int i = 1; i <= m; i++){
        sum_y += (preW[qu[i][1]]-preW[qu[i][0]-1])*(preV[qu[i][1]]-preV[qu[i-1][0]-1]);
    }
    printf("%d %lld\n",W,sum_y);
    sumer = llabs(sum_y-S);
    return sum_y;
}
int main(){
    freopen("in.in","r",stdin);
    int Ws = 2147483647,Wt = -1;
    scanf(" %d %d %lld",&n,&m,&S);
    for(int i = 1; i <= n; i++){
        scanf("%d %d",&w[i],&v[i]);
        Ws = min(w[i],Ws);
        Wt = max(w[i],Wt);
    }
    printf("%d %d\n",Ws,Wt);
    Wt+=2;
    Ws--;
    ans = 8147483647;
    for(int i = 1; i <= m; i++){scanf("%d%d",&qu[i][0],&qu[i][1]);}
    while(Ws<=Wt){
        int mid = (Ws+Wt)>>1;
        long long Y = sum(mid);
        if(Y>S)Ws = mid + 1;
        else Wt = mid - 1;
        if(sumer<ans)ans = sumer;
    }
    printf("%lld",ans);
    return 0;
}