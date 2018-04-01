#include <cstdio>
int main(){
    for(int i = 1; i <= 20;i++){
        for(int j = 1; j < i; j++){
            printf("%d\n",(i-j)%5%3+(i-j)%5);
        }
    }
    printf("\n%d",-((1<<31)+1));
    return 0;
}