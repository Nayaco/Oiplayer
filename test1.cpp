#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int maxN = 100005;
const int maxM = 20000;
int a[maxN], f1[maxM], f2[maxM];
priority_queue<int, vector<int> ,less<int> > q;
int main(){
    q.push(1);
    q.push(2);
    printf("%d",q.top());
    return 0;
}