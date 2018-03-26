#include<iostream>
using namespace std;
const int MAX_N = 200005;
int n, k ,p, pri, ans = 0;
int pre[MAX_N] , CNUM[MAX_N][55], a[MAX_N];
int main(){
    cin>>n>>k>>p;
    for(int i = 0;i < n; i++){
        cin>>a[i]>>pri;
        for(int j = 0; j < k; j++)CNUM[i][j] = CNUM[i-1][j];
        CNUM[i][a[i]]++;
        if(pri<=p)pre[i] = i;
        else pre[i] = pre[i-1];
    }
    for(int i = 0; i < n;i++){
        ans+=CNUM[pre[i]][a[i]];
        if(pre[i]==i)ans--;
    }
    cout<<ans;
    return 0;
}