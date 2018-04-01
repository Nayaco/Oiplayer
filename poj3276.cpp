#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N = 8000;
int f[MAX_N],dir[MAX_N];
int n,M,K;

int calc(int k){
    memset(f,0,sizeof(f));
    int sum = 0;
    int res = 0;
    for(int i = 0; i+k <= n; i++){
        if((dir[i]+sum)%2){
            res++;
            f[i] = 1;
        }
        sum+=f[i];
        if(i-k+1>=0){
            sum-=f[i-k+1];
        }
    }
    for(int i = n-k+1; i < n; i++){
        if((sum+dir[i])%2){
            return -1;
        }
        if(i-k+1>=0){
            sum-=f[i-k+1];
        }
    }
    return res;
}

void solve(){
    M = n;
    K = 1;
    for(int i = 1; i <= n; i++){
        int num = calc(i);
        if(num!=-1&&num<M){
            M = num;
            K = i;
        }
    }
}
int main(){
    cin>>n;
    char ch;
    memset(dir,0,sizeof(dir));
    for(int i = 0; i < n; i++){
        cin>>ch;
        if(ch == 'B'){
            dir[i] = 1;
        }
    }
    solve();
    cout<<K<<' '<<M;
    return 0;
}