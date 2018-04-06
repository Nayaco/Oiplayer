#include <iostream>
#define lc(x) (x<<1)
#define rc(x) ((x<<1) + 1)
#define max(x, y) (x>y?x:y)
using namespace std;
const int maxn = 100005;
int a[maxn] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
struct node{
    int l;
    int r;
    int laz;
    int val;
}T[maxn * 2];

void Build(int l, int r, int k){
    if(l==r){  
        T[k] = {
            l,
            r,
            0,
            a[l]
        };
        return;
    }
    int _mid = (l+r) >> 1;
    Build(l, _mid, lc(k));
    Build(_mid+1, r, rc(k));
    T[k] = {
        l,
        r,
        0,
        max(T[lc(k)].val, T[rc(k)].val)
    };
    return;
}

void Push(int k){
    if(T[k].laz > 0){
        T[lc(k)].laz += T[k].laz;
        T[rc(k)].laz += T[k].laz;
        T[lc(k)].val += T[k].laz;
        T[rc(k)].val += T[k].laz;
        T[k].laz = 0;
    }
    return;
}

void Update(int l, int r, int k, int v){
    if(l == T[k].l && r == T[k].r){
        T[k].val += v;
        T[k].laz += k;
        return; 
    }
    Push(k);
    if(T[lc(k)].r >= l){
        if(T[lc(k)].r > r)Update(l, r, lc(k), v);
        else Update(l, T[lc(k)].r, lc(k), v);
    }
    if(T[rc(k)].l <= r){
        if(T[rc(k)].l < l)Update(l, r, rc(k), v);
        else Update(T[rc(k)].l, r, rc(k), v);
    }
    T[k].val = max(T[lc(k)].val, T[rc(k)].val);
    return;
}

int Query(int l, int r, int k){
    if(l <= T[k].l && r >= T[k].r)return T[k].val; 
    if(l > T[k].r || r < T[k].l)return 0;
    Push(k);
    int _lans = -1;
    int _rans = -1;
    _lans = Query(l, r, lc(k));
    _rans = Query(l, r, rc(k));
    return max(_lans, _rans);
}

int main(int argc, char **argv){
    int _ans = -1;
    Build(1, 10, 1);    
    _ans = Query(3, 8, 1);
    printf("%d\n", _ans);
    Update(2, 8, 1, 2);
    _ans = Query(3, 8, 1);
    printf("%d\n", _ans);
    _ans = Query(3, 10, 1);
    printf("%d\n", _ans);
    return 0;
}
//BST