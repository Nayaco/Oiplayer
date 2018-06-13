#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const char *dream[4] = {
    "dream",
    "dreamer",
    "erase",
    "eraser"
};
int ck(const char *a, const char *b){
    int la = strlen(a), lb = strlen(b);
    if(la < lb)return 0;
    for(int i = 0; i < lb && i < la; i++)if(a[i] != b[i])return 0;
    return 1;
}
int dfs(const char *str){
    if(strlen(str) == 0 || str[0] == '\0')return 1;
    for(int i = 0; i < 4; i++){
        if(ck(str, dream[i])){
            int t = dfs(str + strlen(dream[i]));
            if(t)return 1;
        }
    }
    return 0;
}
char str[100005];
int main(){
    scanf("%s", str);
    if(dfs(str))printf("YES");
        else printf("NO");
    return 0;
}