#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn = 10005;
int a[maxn], b[maxn];
int n;
void ms(int l, int r){
    if(l == r)return;
    int mid = (l + r) >> 1;
    ms(l, mid);
    ms(mid + 1, r);
    int ll = l;
    int rr = mid + 1;
    int k = l;
    while(ll <= mid && rr <= r){
        if(a[ll]<=a[rr]){
            b[k++] = a[ll];
            ll++;
        }else{
            b[k++] = a[rr];
            rr++;
        }
    }
    if(ll <= mid){
        for(int i = ll; i <= mid; i++)b[k++] = a[i];
    }
    if(rr <= r){
        for(int i = rr; i <= r; i++)b[k++] = a[i];
    }
    memcpy(a + l, b + l, sizeof(int) * (r - l + 1));
    return;
}


int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", a + i);
    ms(0, n - 1);
    for(int i = 0; i < n; i++)printf("%d ", a[i]);
    while(1)getchar();
    return 0;
}
