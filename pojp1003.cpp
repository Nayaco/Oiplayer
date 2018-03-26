#include <cstdio>
using namespace std;
double Len[300];
void init(){
    Len[0] = 0;
    for(int i = 1;i < 300;i++){
        Len[i] = Len[i-1] + (double)1/(double)(i+1);
    }
} 
int search(double len){
    int l = 0,r = 299;
    while(l+1<r){
        int mid = (l+r)>>1;
        if(Len[mid]<len)l=mid;
        else r=mid;
    }
    return r;
}
int main(){
    init();
    double len;
    scanf("%lf",&len);
    while(len != 0){
        int ans = search(len);
        printf("%d card(s)\n",ans);
        scanf("%lf",&len);
    }
    return 0;
}