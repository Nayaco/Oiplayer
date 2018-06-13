#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
const int maxlen = 20000005;

struct node{
    int data, id;
}a[maxlen];
int cmp(const node a,const node b){
    return a.data>b.data;
}
int count[maxlen], num[maxlen], pos[maxlen];

int n,q;
int main(){
    priority_queue<int> q;
    while(scanf("%d%d", &n, &q)){
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i].data);
            a[i].id = i;
        }
        sort(a, a+n, cmp);
        int id = 1;count[a[0].id] = 1;
        for(int i = 1; i < n; i++){
            if(a[i].data == a[i-1].data){
                count[a[i].id] = id;
            }else{
                count[a[i].id] = ++id;
            }
        }

        while(q--){
            scanf("%d%d", &minx, &maxx);
            int l = 0, r = 0, ans = 0;
            q.push(count[0]);
            num[count[0]] ++;
            pos[]
            while(l < n - 1 || r < n - 1){
                if(l == r){
                    r++;
                    
                    if(num[count[r]]==0)q.push(count[r]);
                    num[count[r]] ++;
                }
                if(maxn - minn <= maxx && maxn - minn >= minx){
                    ans++;
                    r++;
                    if(num[count[r]]==0)q.push(count[r]);
                    num[count[r]] ++;
                }
                if(maxn - minn <= minx){
                    r++;
                       
                }
                if(maxn - minn >= minx){
                    l++;
                    
                }
            }
        }
    }
}