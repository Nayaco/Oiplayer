#include <cstdio>
#include <cstdlib>
#include <ctime>
#define ran(x) (rand()%x)
#define min(x, y) (x > y?y : x)
using namespace std;
const int MAX_N = 10005;
int a[MAX_N];
int n;

void swap(int &a, int &b){
    int t = b;
    b = a;
    a = t;
    return;
}
void qsort(int l, int r){
    if(l >= r)return;
    int mid = (l + r) >> 1;
    swap(a[mid], a[r]);
    int lc = l; int rc = r - 1;
    while(lc < rc){
        while(a[lc] < a[r] && lc < rc)lc++;
        while(a[rc] >= a[r] && lc < rc)rc--;
        swap(a[lc], a[rc]);
    }
    if(a[lc] >= a[r])swap(a[r], a[lc]);
        else lc++;
    qsort(l, lc - 1);
    qsort(lc + 1, r);
    return;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    qsort(0, n - 1);
    for(int i = 0; i < n; i++)printf("%d ", a[i]);
    while(1)getchar();
    return 0;
}
