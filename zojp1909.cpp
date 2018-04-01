#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAX(X,Y) (X>Y?X:Y)
using namespace std;
const int MAX_N = 25;
int n,m;
int a[MAX_N],vis[MAX_N];
int main(){
    scanf("%d",&n);
    for(int i = 0; i< n; i++){
        scanf("%d",&m);
        int _arglen = 0;
        for(int j = 0; j < m;j++){
            scanf("%d",a[j]);
            _arglen = a[i];
        }
        if(!_arglen | 0x3){
            printf("no\n");
            continue;
        }
        int num = m;
        int len = 0;
        sort(a, a+m);
        for(int j = 0; j < m; j++){
            for(int k = num; k >= 0; k--)if(a[k]<= _arglen - len && !vis[k]){
                vis[k] = 1;
                len += a[k];
                ans 
                break;
            }else{
                if(k == 0){
                    printf()
                }
            }
            if()
        }
    }
    return 0;
}