#include<iostream>
using namespace std;
const int num = 100005;
struct Cube{
    int x, y, w, h;
    Cube(){};
    ~Cube(){};
    bool isin(int x1,int y1){
        if(x1>=x&&y1>=y&&x1<=x+w&&y1<=y+h)return 1;
        return 0;
    }
};
Cube a[num];
int n;
int X,Y;
int main(){
    cin>>n;
    int ans = -1;
    for(int i = 0; i < n; i++)cin>>a[i].x>>a[i].y>>a[i].w>>a[i].h;
    cin>>X>>Y;
    for(int i = 0; i < n; i++)if(a[i].isin(X,Y))ans = i;
    cout<<ans+1;
    return 0;
}