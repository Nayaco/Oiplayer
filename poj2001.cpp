#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 500005;
int trie[maxn][26];
int sum[maxn];
int presum[maxn];
int tot = 0, n;
void addstr(char *str, int rt, int num){
    int len = strlen(str);
    int root = 0;
    for(int i = 0; i < len; i++){
        int id = str[i] - 'a';
        if(!trie[rt][id]){
            trie[rt][id] = ++tot;
            if(!sum[tot])sum[tot] = num;
        }else{
            if(i == len-1){
                sum[trie[rt][id]] = num;
            }   
        }
        presum[trie[rt][id]]++;
        rt = trie[rt][id];
    }
}
int find(char *str, int rt){
    for(int i  = 0;i < strlen(str); i++){
        int id = str[i] - 'a';
        if(!trie[rt][id])return -1;
        if(presum[trie[rt][id]]==1){
            return i;
        }
        rt = trie[rt][id];
        if(i==strlen(str)-1){
            for(int j = 0; j < 26; j++){
                if(trie[rt][j]&&sum[trie[rt][j]]==sum[rt]){
                    return -1;
                }
            }
        }
    }
    return strlen(str)-1;
}
char str[10005][25];
int main(){
    n = 0;
    for(int i = 0;; i++){
        int t = scanf("%s", str[i]);
        if(!t || (str[i][0]<'a'||str[i][0]>'z'))break;
        n++;
        addstr(str[i], 0, i+1);
    }
    for(int i = 0; i < n; i++){
        int ans = find(str[i], 0);
        printf("%s ",str[i]);
        str[i][ans+1] = '\0';
        printf("%s\n",str[i]);
    }
    return 0;
}
