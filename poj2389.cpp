#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn = 100005;
const double PI = 3.14159265358979;
typedef complex<double> cd;
int rev[maxn];

int hst(int k){
    int i = 1;
    while((1<<i) < k) i++;
    return i + 1;
}

void getrev(int bit){
    for(int i = 1; i < (1<<bit); i++){
        rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit - 1));
    }
}

void fft(cd *a, int n, int dft){
    for(int i = 0; i < n; i++){
        if(i < rev[i])swap(a[i], a[rev[i]]);
    }
    for(int step = 1; step < n; step<<=1){
        cd wn = exp(cd(0, dft * PI / step));
        for(int j = 0; j < n; j += step<<1){
            cd wnk(1, 0);
            for(int k = j; k < j + step; k++){
                cd x = a[k];
                cd y = wnk * a[step + k];
                a[k] = x + y;
                a[k + step] = x - y;
                wnk *= wn;
            }
        }
    }
    if(dft == -1){
        for(int i = 0; i < n; i++){
            a[i] /= n; 
        }
    }
}

int main(){
    char _s[maxn];
    int ans[maxn];
    int n, m;
    int l1, l2;
    int _temp;
    cd a[maxn], b[maxn];
    scanf("%s", _s);
    l1 = strlen(_s);
    for(int i = 0; i < l1; i++)a[i] = cd(_s[l1 - i - 1] - '0', 0);
    scanf("%s", _s);
    l2 = strlen(_s);
    for(int i = 0; i < l2; i++)b[i] = cd(_s[l2 - i - 1] - '0', 0);
    int len = hst(l1 + l2 - 1);
    getrev(len);
    len = 1<<len;
    fft(a, len, 1);
    fft(b, len, 1);
    for(int i = 0; i < len; i++)a[i] *= b[i];
    fft(a, len, -1);
    ans[0] = 0;
    int tmp = 0;
    for(int i = 0; i < l1 + l2 - 1; i++){
        ans[i] += (int)(a[i].real() + 0.5);
        ans[i + 1] = ans[i] / 10;
        ans[i] %= 10;
        if(ans[i])tmp = i;
    }
    tmp += 1;
    while(tmp--)printf("%d", ans[tmp]);
    return 0;
}