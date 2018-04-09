#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct node{
    int _id;
    int _len;
}NODE;

int cmp(const NODE a,const NODE b)
{
    return a._len < b._len?1:(a._id < b._id);
}

int main()
{
    int n, m = 0;
    char str[20][26];
    NODE map[20];
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)break;
        printf("SET %d\n", ++m);
        for(int i = 0; i < n; i++){
            scanf("%s",str[i]);
            map[i]._id = i;
            map[i]._len = strlen(str[i]);
        }
        sort(map, map + n, cmp);
        for(int i = 0; i < (n + 1) / 2 ; i++){
            printf("%s\n",str[map[i * 2]._id]);
        }
        for(int i = n / 2; i > 0; i--){
            printf("%s\n",str[map[i * 2 - 1]._id]);
        }
    }
    return 0;
}