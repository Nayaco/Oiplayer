#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#define abs(x) ((x)>0?(x):-(x))
#define min(x, y) (x<y?x:y)
#define max(x, y) (x>y?x:y)
using namespace std;
int main(){
    int a, b;
    double g = (sqrt(5.0)+1.0)/2.0;
    while(scanf("%d%d", &a, &b)){
        int k = abs(a-b);
        if((int)(g*k) == min(a, b))printf("0\n");
        else printf("1\n"); 
    }
    return 0;
}