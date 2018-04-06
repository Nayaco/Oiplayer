int Ex_uci(int a, int b, int &x, int &y){
    if(b==0){
        x = 1; y = 0;return a;
    }
    int _t = x;x = y; y = _t - (a/b) * y;
    return Ex_uci(b, a%b, x, y);
}
    
Ula[i] = ((M-M/i)*Ula[M%i])%M;