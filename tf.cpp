#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    long long a,b,x;
    scanf("%lld%lld%lld", &a, &b, &x);
    long long t = b - (a - a % x);
    long long ans = t / x;
    ans += !(a % x);
    printf("%lld", ans);
    while(1)getchar();
    return 0;
}