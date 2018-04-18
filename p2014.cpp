#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAX_N = 100005;

typedef struct node{
    int l, r, sum;
}NODE;
NODE T[MAX_N * 20];
int tot;

void add(int &num, int &x, int l, int r){
    T[tot++] = T[x]; x = tot - 1;
    T[x].sum++;
    if(l == r)return;
    int mid = (l + r)>>1;
    if(num <= mid)add(num, T[x].l, l, mid);
    else add(num, T[x].r, mid+1, r);    
}

int query(int i, int j, int k, int l, int r){
    if(l == r)return l;
    int t = T[T[j].l].sum - T[T[i].l].sum;
    int mid = (l + r)>>1;
    if(k <= t)return query(T[i].l, T[j].l, k, l, mid);
    else return query(T[i].r, T[j].r, k - t, mid + 1, r);
}

struct A{
    int x, id;
    bool operator <(const A &rhs)const{
        return x < rhs.x;
    }
};

A a[MAX_N];
int _rank[MAX_N], root[MAX_N];
int n, m;

int main(){
    T[0].l = T[0].r = T[0].sum = 0;
    root[0] = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i].x);
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    for(int i  = 1; i <= n; i++)_rank[a[i].id] = i;
    tot = 1;
    for(int i = 1; i <= n; i++){
        root[i] = root[i - 1];
        add(_rank[i], root[i], 1, n);
    }
    while(m--){
        int i, j, k;
        scanf("%d%d%d", &i, &j, &k);
        printf("%d\n",a[query(root[i - 1], root[j], k ,1, n)].x);
    }
    return 0;
}