#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        int x = (int)sqrt((float)(n<<1));
        if(x*(x+1)>(n<<1))x--;
        long long sum = (n-(x)*(x+1)/2)*(x+1);
        sum += (x)*(x+1)*(2*x+1)/6;
        printf("%d %lld\n", n, sum);
    }
    return 0;
}