#include <cstdio>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double PI = 3.1415926535;
typedef complex<double> cd;
const int MAXLEN = 4005;
int rev[MAXLEN];
int hst(int k){
    int i = 1;
    for(;(1<<i)<k;i++);
    return i;
}
//getreverse (it is important)
void getrev(int bit)
{
    for(int i = 0; i < (1<<bit); i++){
        rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
    }
}

void fft(cd *a, int n, int dft)
{
    for(int i = 0; i < n; i++){
        if(i < rev[i]){
            swap(a[i], a[rev[i]]);
        }
    }
    for(int step = 1; step < n; step<<=1){
        cd wn = exp(cd(0, dft * PI / step));
        for(int j = 0; j < n; j+=step<<1){
            cd wnk(1, 0);
            //The butterfly
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
            a[i]/=n;
        }
    }
}


int main(){
    int n, m;
    int l1, l2;
    int s;
    cd a[1005], b[1005];
    scanf("%d%d", &n, &m);
    int _temp;
    for(int i = 0; i < n; i++){
        scanf("%d", &_temp);
        a[i] = cd(_temp, 0);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &_temp);
        b[i] = cd(_temp, 0);
    }
    int len = 1<<hst(n + m - 1);
    getrev(hst(n + m - 1));
    fft(a, len, 1);//dft for a
    fft(b, len, 1);//dft for b
    for(int i = 0; i < len; i++)a[i] *= b[i];
    fft(a, len, -1);//idft
    for(int i = 0; i < n + m - 1; i++)printf("%d ",(int)(a[i].real()+0.5));
    printf("\n");
    while(1)getchar();
    return 0;
}