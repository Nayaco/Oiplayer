#include <cstdio>
using namespace std;
int main(){
    int w,h;
    char str[105];
    scanf("%d%d", &h, &w);
    for(int i = 0; i < h; i++){
        scanf("%s", str);
        printf("%s\n", str);
        printf("%s\n", str);
    }
    return 0;
}