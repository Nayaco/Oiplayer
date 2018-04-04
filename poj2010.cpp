#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define max(x, y) (x>y?x:y)
using namespace std;
const int maxN = 200005;
const int maxM = 100005;
struct node{
    int x,y;
}a[maxN];
int cmp(node a1, node b1){
    return a1.x<b1.x;
}
int f1[maxM], f2[maxM];
priority_queue<int, vector<int> ,less<int> > q1;
priority_queue<int, vector<int> ,less<int> > q2;
int n, c, f;
int main(){
    scanf("%d%d%d", &n, &c, &f);
    for(int i = 0; i < c; i++){
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    sort(a,a+c,cmp);
    {
        for(int i = 0; i < n/2; i++){
            q1.push(a[i].y);
            f1[n/2-1] += a[i].y;
            q2.push(a[c-i-1].y);
            f2[c-n/2] += a[c-i-1].y;
        }
    }
    {
        for(int i = n/2; i < c - n/2; i++){
            //f1
            if(a[i].y>=q1.top()){
                f1[i] = f1[i-1]; 
            }else{
                f1[i] = f1[i-1] - q1.top() + a[i].y;
                q1.pop();q1.push(a[i].y);
            }
        }
        for(int i = c - n/2 - 1; i > n/2; i--){
            //f2
            if(a[i].y>=q2.top()){
                f2[i] = f2[i+1];
            }else{
                f2[i] = f2[i+1] - q2.top() + a[i].y;
                q2.pop();q2.push(a[i].y);
            }
        }
    }
    int ans = -1;
    for(int i = n/2; i < c - n/2; i++){
        if(a[i].y + f1[i - 1] + f2[i + 1] <= f){
            ans = a[i].x;
        }
    }
    printf("%d",ans);
    return 0;
}

/*
5 9 110
30 25
50 21
20 20
5 18
35 30
51 30
3 11
1 50
60 10
*/